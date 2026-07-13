Nice—I’ll give you (1) a clear diagram of the real kernel structs involved (`task_struct` ↔ `mm_struct` ↔ VMAs`), (2) a step-by-step explanation of how the kernel schedules the process’s final removal (reparenting, dead list, zombie → `release_task()`), and (3) **annotated, easy-to-read pseudo-source** that maps to the real implementations in `kernel/exit.c`and`mm/mmap.c` so you can quickly relate behaviour to the code. I’ll cite the kernel sources and docs I used so you can read the originals.

---

# 1) Kernel structs — practical diagram (real fields to watch)

This is a condensed, practical view of the **actual kernel objects** used during process exit. It matches the kernel’s design: execution state lives in `task_struct`, memory state in `mm_struct`, and memory regions in `vm_area_struct` (VMA).

```
+---------------------------+      +-----------------------------------+
|        task_struct        |      |             mm_struct             |
|  (execution / sched info) |<---->| (address-space / VM descriptor)   |
|                           |      |                                   |
|  pid        : int         |      |  mmap       : struct vm_area_struct *  ---> VMAs linked list
|  state      : long        |      |  mm_users   : atomic_t               (refcount)
|  flags      : unsigned    |      |  pgd / pg_tables : page table ptrs  (page tables)
|  exit_state : int         |      |  total_vm   : unsigned long
|  exit_code  : int         |      |  mmap_lock  : rw_semaphore
|  parent     : task_struct*|      |  mm_rb      : rbtree of VMAs
|  children   : list_head   |      |  map_count  : int (vma count)
|  files      : files_struct*|     +-----------------------------------+
|  mm         : mm_struct * |  (task->mm points to mm; kernel threads often have NULL)
+---------------------------+
```

Key relationships:

* `task_struct->mm` points to the `mm_struct` for user threads. Kernel threads often have `mm == NULL`.
* `mm_struct->mmap` (or `mm_rb`) links all `vm_area_struct`s (the heap, stack, mappings).
* `mm_users`/`map_count`/refcounts govern when the kernel can free `mm_struct` and unmap pages. ([WXDublin][1])

---

# 2) High-level sequence: how the kernel removes a process (quick flow)

Short flow (mapping to kernel functions):

1. **User calls `exit()` / process returns from `main()`** → kernel syscall `sys_exit_group()` invoked.
2. `sys_exit_group()` → `do_exit()` — the central exit work begins.

   * `do_exit()` calls helpers: `exit_mm()`, `exit_files()`, `exit_fs()`, `exit_task()` and reparenting logic. ([Code Browser][2])
3. **`exit_mm()` → `mmput()`**. `mmput()` decrements `mm_users`; if it reaches zero it runs the sequence to unmap VMAs, drop page tables and free `mm_struct`. This is where **all user-space pages (heap, stack, mmapped files)** are unmapped and freed. ([Android Go Source][3])
4. After `do_exit()` the process becomes a **zombie**: most kernel state removed but an entry remains so the parent can collect exit status. `SIGCHLD` is sent to the parent. ([Code Browser][2])
5. Parent calls `wait()`/`waitpid()` → kernel reaps the child. Reaping triggers `release_task()` / `put_task_struct()` and the final freeing of the `task_struct` (and kernel-thread stacks, scheduling data). After this, the PID and all kernel structures are gone. ([Code Browser][2])

---

# 3) How the kernel schedules the *final removal* (reparenting, dead list, reapers)

Two things to watch:

* **Reparenting**: orphaned children must be adopted by a new parent (often `init` or a subreaper). The exit code moves children requiring final cleanup onto a “dead” list which the reaper will process. The reparenting + reaper logic is in `kernel/exit.c`. ([Android Go Source][4])

* **Zombie → Reap → release_task**: while zombie, only minimal info remains. The parent’s `wait()` causes the kernel to run `release_task()` for those tasks on the dead list; `release_task()` frees the `task_struct` and kernel-mode stacks. The kernel also uses lists/locks to ensure reaping is serialized and safe against races. ([Code Browser][2])

Illustration (timing & lists):

```
[do_exit()] 
   ├─> put mm on mmput path (exit_mm -> mmput -> unmap VMAs)
   ├─> close file descriptors
   ├─> mark TASK_DEAD / EXIT_ZOMBIE (small PCB remains)
   └─> reparent children (move some to 'dead' list if needed)
           ↓
   Parent later calls wait() -> reap() -> release_task() -> final free
```

---

# 4) Annotated pseudo-source that maps to `kernel/exit.c` and `mm/mmap.c`

Below I give **short, annotated pseudo-code** for the real kernel functions (keeps the logic but is readable). Each block explains the intent and points to the real function names/files.

---

### A — Process exit (simplified) — maps to `kernel/exit.c`

```c
/* simplified do_exit() flow */
void do_exit(int code)
{
    struct task_struct *p = current;

    /* 1) notify and prepare thread group / signals */
    flush_signals(p);               // tidy up pending signals
    send_sig(SIGCHLD, p->parent);   // let parent know child died

    /* 2) release address space (user memory) */
    exit_mm(p);                     // -> calls mmput(mm) [mm/mmap.c]

    /* 3) close file descriptors and FS state */
    exit_files(p);                  // closeall fds
    exit_fs(p);                     // drop cwd, root

    /* 4) arch-specific thread cleanup */
    exit_thread(p);                 // architecture dependent

    /* 5) mark as zombie so parent can read exit code */
    p->exit_code = code;
    p->exit_state = EXIT_ZOMBIE;    // minimal PCB remains
    wake_up_parent_if_waiting(p);   // so parent can reap

    /* children reparenting kept here */
    reparent_children(p);           // adopt children by reaper/init
}
```

**Notes / mapping**: Real function `do_exit()` in `kernel/exit.c` performs much more (locking, accounting, scheduler interactions), but the above captures the main cleanup steps and where they occur. See `kernel/exit.c`. ([Code Browser][2])

---

### B — Unmapping the address space — maps to `mm/mmap.c` (`exit_mmap()` / `mmput()`)

```c
/* simplified mmput/exit_mmap behavior */
void exit_mm(struct task_struct *p)
{
    struct mm_struct *mm = p->mm;
    if (!mm) return;                 // kernel threads may have no mm

    /* decrement mm refcount - mmput handles final free */
    mmput(mm);                       // may call free_mm() if refcount==0
}

/* mmput() roughly */
void mmput(struct mm_struct *mm)
{
    if (atomic_dec_and_test(&mm->mm_users)) {
        /* last user of mm: unmap everything and free structures */
        exit_mmap(mm);              // unmaps all VMAs, calls unmap_vmas()
        free_pagetables(mm);        // free page tables (pgd, pud, pmd, pte)
        mmdrop(mm);                 // drop the final ref and free mm_struct
    }
}
```

`exit_mmap()` walks the list / rbtree of `vm_area_struct`s and calls the VM unmap machinery (e.g. `unmap_vmas()`, `vma_unmap_aliases()`, `zap_page_range()`), releasing page-cache references, and decrementing swap and anon-accounting as it goes. This is where all user pages are freed. See `mm/mmap.c` for the exact functions and locking. ([Android Go Source][3])

---

### C — Final freeing of `task_struct` — maps to codepaths invoked when parent reaps

```c
/* simplified reaping */
void reap_child(task_struct *child)
{
    /* parent called wait(); kernel collected child's exit_code */
    release_task(child);     // frees kernel stacks & task_struct
}

/* release_task roughly */
void release_task(struct task_struct *p)
{
    free_kernel_stack(p);
    put_task_struct(p);      // final refcount drop frees task_struct
}
```

**Note:** The kernel protects these steps with lists and locks (see `kernel/exit.c` usage of dead lists and reaper logic). ([Code Browser][2])

---

# 5) Concrete places in the real kernel source to read (links)

* `kernel/exit.c` — core exit, reparent, zombie, reaper; examine functions `do_exit()`, `release_task()`, `reparent_leader()`. ([Code Browser][2])
* `mm/mmap.c` — `exit_mmap()`, the VMA unmapping code, and `mmput()` interactions. ([Android Go Source][3])
* Documentation on VM (Gorman’s “Understanding the Linux Virtual Memory Manager”) for background on VMAs, page tables and accounting. ([Kernel.org][5])

(If you want, I can open the exact lines in a chosen kernel version and show direct links to the canonical repo for the version you care about — tell me which kernel version, e.g. `v6.6`, `v6.7-rc`, or the distro kernel.)

---

# 6) Quick pitfalls and gotchas (practical)

* **Kernel threads**: often have `mm == NULL`. `exit_mm()` is a no-op there — nothing to free. ([Stack Overflow][6])
* **Race between unmapping and I/O**: `exit_mmap()` must hold mmap locks and use the VM unmap functions carefully — several CVEs and bug reports historically show this is delicate. Check `unmap_vmas()` call sites. ([Google Issue Tracker][7])
* **Zombie lifetime**: if parent never calls `wait()` the child remains a zombie (tiny memory footprint), but resources like PID table entries persist until reaped. Avoid leaks of zombies by properly reaping or using a `SIGCHLD` handler / `prctl(PR_SET_CHILD_SUBREAPER)` where appropriate. ([Code Browser][2])

---

# 7) Next steps I can do right away (pick any)

* Fetch and paste the **exact `do_exit()` / `exit_mmap()` functions** from a specific kernel version (I can show the exact lines and annotate them).
* Draw an SVG or PNG diagram of the `task_struct` ↔ `mm_struct` ↔ VMAs and the timeline (do_exit → mmput → zombie → release_task) so you can use it in slides.
* Show a short kernel tracing session (ftrace/printk traces) of a process exit to see the calls in order (requires your kernel version).

Tell me which of these you want next and which kernel version (or distro kernel) you prefer — I’ll fetch the exact source and annotate it.

[1]: https://wxdublin.gitbooks.io/deep-into-linux-and-beyond/content/vm_subsystem.html?utm_source=chatgpt.com "VM Subsystem | Deep into Linux and Beyond"
[2]: https://codebrowser.dev/linux/linux/kernel/exit.c.html?utm_source=chatgpt.com "exit.c source code [linux/kernel/exit.c] - Codebrowser"
[3]: https://android.googlesource.com/kernel/common/%2B/bb52bba67e35e1eefaf4b4b898b008fa82df47e1/mm/mmap.c?utm_source=chatgpt.com "mm/mmap.c - kernel/common - Git at Google"
[4]: https://android.googlesource.com/kernel/common/%2B/234d53d2bb60a9436a6d4d55bef1712613b79014/kernel/exit.c?utm_source=chatgpt.com "kernel/exit.c - kernel/common - Git at Google"
[5]: https://www.kernel.org/doc/gorman/pdf/understand.pdf?utm_source=chatgpt.com "Understanding The Linux Virtual Memory Manager"
[6]: https://stackoverflow.com/questions/27424425/what-part-of-mm-struct-use-by-kernel-thread-in-linux?utm_source=chatgpt.com "what part of mm_struct use by kernel thread in linux?"
[7]: https://issuetracker.google.com/172226811?utm_source=chatgpt.com "Linux Kernel V5.2.0-rc1 #2 use-after-free in unmap_vmas ..."
