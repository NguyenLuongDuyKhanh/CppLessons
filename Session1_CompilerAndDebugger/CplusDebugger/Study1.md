In **GDB**, you can run your program until a condition becomes true using **conditional breakpoints** or the **`until`** command, depending on what you want:

---

### 1. **Run until a condition is true (conditional breakpoint)**

If you want the program to stop when some expression becomes true:

```gdb
break <location> if <condition>
```

or if you want it to stop *anywhere* when a variable/expression matches:

```gdb
break <line_number>
condition <breakpoint_number> <condition>
```

**Example:**

```gdb
break myfile.c:42 if x == 10
```

→ Execution will stop at line 42 only when `x == 10`.

---

### 2. **Run continuously until condition holds**

If you want the program to just keep running until a condition happens (no matter where):

```gdb
watch <expression>
```

Stops when the expression changes value.
Example:

```gdb
watch x if x > 100
```

→ Stops when `x` becomes greater than 100.

---

### 3. **Temporary loop with `while` + `continue`**

You can script it in GDB:

```gdb
while (x != 10)
    continue
end
```

→ Keeps running until `x == 10`.

---

### 4. **Run until a specific line (not condition-based)**

If you just want to run until a given line or function returns:

```gdb
until <line_number>
finish        # until current function returns
```

---

👉 Do you want to stop **only when a variable has a specific value** (e.g., `x == 42`), or to stop **each time it changes**?

When a **segmentation fault (SIGSEGV)** happens while running your program in **GDB**, that’s actually the best time to debug — GDB will stop execution *at the exact instruction* that caused the crash. Here’s what to do step by step:

---

### 1. Run the program under GDB

```bash
gdb ./your_program
(gdb) run [args...]
```

When the segfault happens, GDB will stop and print something like:

```
Program received signal SIGSEGV, Segmentation fault.
0x0000000000401234 in foo (p=0x0) at main.cpp:42
42          *p = 5;
```

---

### 2. Inspect where it crashed

* See the current line:

```gdb
(gdb) list
```

* Print the backtrace (stack trace):

```gdb
(gdb) bt
```

This shows the chain of function calls that led to the segfault.

---

### 3. Inspect variables

Check pointers and values near the crash:

```gdb
(gdb) print p
(gdb) print *p
(gdb) info locals
(gdb) info args
```

If `p` is `0x0` or garbage → that’s your null/invalid pointer dereference.

---

### 4. Move up and down the stack

If the crash happened deep inside a function, you can look at higher levels:

```gdb
(gdb) frame 1      # move to caller
(gdb) frame 2      # further up
```

Then inspect arguments/locals there.

---

### 5. Use watchpoints (if needed)

If you suspect a variable gets corrupted *before* the crash:

```gdb
watch myVar
```

→ Program stops when `myVar` changes.

---

### 6. Restart after fixing breakpoints

You don’t need to restart GDB, just rerun:

```gdb
(gdb) run
```

---

✅ **In short**:
When segfault happens in GDB → don’t worry, it’s normal. Use `bt`, `frame`, `info locals`, and `print` to trace the root cause.

---

Do you want me to show you a **minimal workflow** (like 3–4 commands only) to catch the exact line and variable that caused the segfault, without overwhelming steps?
