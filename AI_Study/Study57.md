Debug symbols are metadata that map the compiled machine code back to the original source code. They allow a debugger such as **GDB**, **LLDB**, or **WinDbg** to answer questions like:

* What function am I currently executing?
* What source file and line number corresponds to this instruction?
* What are the names and types of local variables?
* What is the class layout?
* What does this stack trace mean?

Without debug symbols, a debugger mostly sees raw addresses and assembly instructions.

---

# What debug symbols contain

Suppose you have this C++ code:

```cpp
int add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    return add(3, 5);
}
```

Compile with

```bash
g++ -g test.cpp -o test
```

The executable contains:

```
+--------------------------------+
| ELF Header                     |
+--------------------------------+
| Machine code (.text)           |
+--------------------------------+
| Read-only data (.rodata)       |
+--------------------------------+
| Global variables (.data/.bss)  |
+--------------------------------+
| Symbol table                   |
+--------------------------------+
| DWARF debug information        |
|  - source filenames            |
|  - line numbers                |
|  - variable names              |
|  - type information            |
|  - stack frame descriptions    |
+--------------------------------+
```

The **DWARF** sections may include:

```
Function:
    add()

Address range:
    0x1149 - 0x1162

Source:
    test.cpp

Line mapping:
0x1149 -> line 1
0x1153 -> line 2
0x115c -> line 3

Local variables:
a : int
b : int
c : int
```

When GDB stops at address `0x1153`, it knows this is:

```cpp
int c = a + b;
```

instead of just:

```asm
mov eax,[rbp-8]
```

---

# Why separate debug symbols?

Production binaries usually do **not** need debugging information.

Reasons to remove them:

* reduce executable size
* reduce firmware size (important for embedded systems)
* avoid exposing implementation details
* faster distribution

However, developers still need symbols when debugging a crash.

Therefore many companies ship

```
my_app
```

to customers

and keep

```
my_app.debug
```

internally.

---

# How to split debug symbols (Linux ELF)

The standard tool is **objcopy**.

## Step 1: Build with symbols

```bash
g++ -g main.cpp -o myapp
```

Now

```
myapp
```

contains everything.

---

## Step 2: Extract debug info

```bash
objcopy --only-keep-debug myapp myapp.debug
```

Result:

```
myapp
myapp.debug
```

The `.debug` file contains only DWARF information.

---

## Step 3: Strip the executable

```bash
strip --strip-debug myapp
```

or

```bash
objcopy --strip-debug myapp
```

Now

```
myapp
```

contains machine code but almost no debugging information.

Its size may shrink considerably.

Example:

```
Before:
8 MB

After stripping:
2 MB

Debug file:
6 MB
```

---

## Step 4: Link them together

Tell the executable where its symbols live:

```bash
objcopy \
    --add-gnu-debuglink=myapp.debug \
    myapp
```

Now GDB automatically finds

```
myapp.debug
```

if it is in the same directory or a configured debug symbol directory.

---

# What happens during debugging?

Imagine the program crashes.

Crash log:

```
PC = 0x401193
```

Without symbols:

```
0x401193
```

Not useful.

With

```
myapp.debug
```

GDB can resolve it to:

```
main.cpp:42

Foo::calculate()

local variable:
count = 15
```

Even though the executable itself is stripped.

---

# Symbolication after a crash

Many companies collect only:

```
Executable
Crash address

0x401193
```

Later, on the build server:

```
gdb myapp myapp.debug
```

or

```
addr2line
```

can translate

```
0x401193
```

into

```
Foo.cpp:128
```

This process is called **symbolication**.

---

# Embedded systems example

For an embedded project:

```bash
arm-none-eabi-g++ -g firmware.cpp -o firmware.elf
```

Generate firmware:

```bash
arm-none-eabi-objcopy \
    -O binary \
    firmware.elf \
    firmware.bin
```

Extract symbols:

```bash
arm-none-eabi-objcopy \
    --only-keep-debug \
    firmware.elf \
    firmware.debug
```

Strip the ELF:

```bash
arm-none-eabi-strip firmware.elf
```

Artifacts become:

```
firmware.bin      <-- flashed to MCU

firmware.elf      <-- stripped

firmware.debug    <-- archived
```

If the device later reports a faulting program counter (PC), you can use the debug file to recover source locations:

```bash
arm-none-eabi-addr2line \
    -e firmware.debug \
    0x10001234
```

Output:

```
main.cpp:87
```

---

# Windows equivalent

Windows uses **PDB (Program Database)** files.

```
myapp.exe
myapp.pdb
```

The `.exe` contains little or no debug information, while the `.pdb` stores:

* source file mappings
* variable names
* type information
* stack unwinding metadata

Visual Studio automatically loads the matching PDB during debugging.

---

# macOS equivalent

macOS stores debug information in **dSYM** bundles:

```
MyApp

MyApp.dSYM/
```

The executable is distributed, while the `.dSYM` is kept for debugging and crash symbolication.

---

## Summary

| Platform       | Executable | Separate debug symbols | Common format                       |
| -------------- | ---------- | ---------------------- | ----------------------------------- |
| Linux          | ELF        | Yes                    | DWARF in `.debug` file              |
| Embedded (ARM) | ELF / BIN  | Yes                    | DWARF in `.debug` or unstripped ELF |
| Windows        | PE         | Yes                    | `.pdb`                              |
| macOS          | Mach-O     | Yes                    | `.dSYM`                             |

The key idea is that the machine code needed to run the program is independent of the metadata needed to debug it. By extracting and storing debug symbols separately, you can ship smaller, less revealing binaries while retaining the ability to diagnose crashes and inspect execution using the matching symbol files.
