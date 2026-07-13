# Python 
    - override decorator python
    - difference with overwrite/overload. override != overload
    - https://www.geeksforgeeks.org/method-overriding-in-python/
    - https://realpython.com/python-operator-module/
    - https://realpython.com/python-asterisk-and-slash-special-parameters/
    - https://realpython.com/python-for-data-analysis/
    - https://realpython.com/python-seaborn/
    - https://realpython.com/python-catch-multiple-exceptions/
    - https://realpython.com/python3-object-oriented-programming/
    - https://realpython.com/inheritance-composition-python/
    - https://realpython.com/how-to-implement-python-stack/
    - https://realpython.com/pypy-faster-python/

    - difference between module and file
    - alembic in database python 
    - python del keyword, tại sao cần, sao chưa bao giờ xài thử
    - pass a function as call back
    - lock thif queue hay skip
    - https://docs.python.org/3/library/threading.html
    - copy and deepcopy python
    - https://docs.python.org/3/library/glob.html
    - struct in python
    instance and class attribute cungf teen
    - https://stackify.com/python-garbage-collection/
    - dùng https://docs.python.org/3/library/gc.html để check giữa việc tạo object dùng 1 lần và instance thì cái nào okay hơn
    - tuwf local ipc publisher tạo mới object mà chỉ dùng 1 lần thi co hai gi cho performance hay khong
    - break a sleep in thread
    - check syntax of python script - The use of py_compile
    - @dataclass in python - @staticmethod
    - @property
    - from collections import ChainMap python
    - https://inquirerpy.readthedocs.io/en/latest/
    https://realpython.com/queue-in-python/
    
    django
    https://realpython.com/django-flashcards-app/
    https://realpython.com/installable-django-app/


    os.mkfifo() - fifo and named pipe in linux
    __del__ in python (deconstruct)
    paramiko - channel
    <dictionary>.update(...) python
    import bên trong và bên ngoài khác nhau ntn

    read/write lock seperately
    protect a var with lock through all access ()

    black --line-length=100 commonutils.py 
    mypy --strict commonutils.py 
    pylint commonutils.py 
    socket programming in C++ and python
    statistic module in python 
    https://www.geeksforgeeks.org/template-class-in-python/
    https://stackoverflow.com/questions/6725868/generics-templates-in-python
    https://docs.python.org/3/library/os.html#os.fork
    https://docs.python.org/3/library/index.html
    boto3

    Coroutine with 
        Tornado and Twisted are ready since Python2.7
        uvloop is ultra fast asyncio event loop (uvloop makes asyncio 2-4x faster).

    * python iunit test
    - difference Mock() and MagicMock() python
    - unit test assert_awaited_once for thread
    https://medium.com/@utkarshshukla.author/mastering-patching-and-mocking-in-python-a-comprehensive-guide-01f57fb91dda

    paramico
    - import argparse 
    - from paramiko import AutoAddPolicy, RSAKey, SSHClient 
    - from paramiko.channel import Channel 
    - from paramiko.auth_handler import AuthenticationException, SSHException 
    - from scp import SCPClient 
    - import json 
    - import getpass

# GPSD
    - nmea format
    - netcat localhost 2947
    - telnet 
    - https://nmeagen.org/
    - https://pypi.org/project/pynmea2/
    - https://gpsd.io/gpsd_json.html
    - https://gisgeography.com/gps-accuracy-hdop-pdop-gdop-multipath/
    - https://gpsd.gitlab.io/gpsd/client-howto.html
    - https://gpsd.gitlab.io/gpsd/gpsd.html
    - https://gpsd.gitlab.io/gpsd/
    - gpsctl

# Threading in programming
 thread and daemon and process in pyhon/C++/linux, threading.event python
    - https://superfastpython.com/thread-event-object-in-python/
    - https://superfastpython.com/thread-condition/
    - process
    - https://github.com/thanhit95/multi-threading/tree/main/cpp/cpp-pthread
    https://www.libhunt.com/l/cpp/topic/multithreading
    https://viblo.asia/p/013-lap-trinh-multi-thread-co-that-su-nhanh-hon-single-thead-L4x5xV2YZBM
    - https://www.geeksforgeeks.org/ps-command-in-linux-with-examples/
    - https://man7.org/linux/man-pages/man1/ps.1.html
    - issue cherry pick dd8 before dd7.1
    - https://git-scm.com/docs/git-cherry-pick
    - https://man7.org/linux/man-pages/man1/ps.1.html
    - https://realpython.com/intro-to-python-threading/#what-is-a-thread
    - The Daemon Thread does not block the main thread from exiting and continues to run in the background. This article is based on threading in python, here we discuss daemon thread with examples.
    - Unlike regular programs that are typically launched by users and run in the foreground, Daemons operate independently and often start automatically when a computer boots up. They don't have a graphical user interface (GUI) and usually don't require user input to perform their tasks.
    - https://docs.python.org/3/library/multiprocessing.html pool and manager
    suggest
    How do you know 100ms is enough on all machines this runs on? Also, pushing the request and waiting for 3 seconds, what if it had made it's state transition within 0.1s? Aren't we now just making every developer and CI running this test wait for 2.9s for nothing?
    This is where designing for test comes into play. When designing a class ask yourself how will I test this. For example, break the class into a thread wrapper of the algo and you can then test without any threads and not require any sleeps. Or, provide a mechanism to 'sleep until processed' and block on that in your test.

    - https://www.geeksforgeeks.org/python-os-getpid-method/
    - https://www.geeksforgeeks.org/ps-command-in-linux-with-examples/
    - https://stackoverflow.com/questions/3032805/starting-a-separate-process
    - https://docs.python.org/3/library/multiprocessing.html
    - https://docs.python.org/3/library/queue.html#queue.Queue
    - pid of a call back and a thread
    - thread join and thread daemon in python: what end what wait
    - trong truongwf hợp call back bình thường thì sẽ vào queue trong thread gốc hay miss luôn hay mở thread mở
    https://www.personal.kent.edu/%7Ermuhamma/OpSystems/Myos/threads.htm
    <interprocess communication> or <interthreads communication>

# DSA
Decision tree
Bitwise python
Graph dag
AI để giải tictacto
Parenthesis checker
Djkstra trong bai toan tim duong di ngan nhat
Md5 và crc32
The second big in a list
Đảo ngược danh sách liên kết đơn dùng 1 vòng lặp

Sorting
Selection
Insertion heap
Bubble
Cocktail
Circle
Quick
Shell

Fenwick Tree (Binary Indexed Tree) for Competitive Programming - GeeksforGeeks 
https://oj.vnoi.info/problem/hcm_thpt_23_a?fbclid=IwZXh0bgNhZW0CMTAAAR3gWU-UrGlFnBwnLUdBKsq34zcd9qPI2cN4EeVk5PHNdNH2u5am1FN5_h8_aem_byYtMsOstCU3lf0Qs8BEMg

https://www.geeksforgeeks.org/dsa/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/
tháp ha noi
    thuật toán phá mật khẩu
    https://en.wikipedia.org/wiki/Brute-force_attack
    https://techie.vn/tong-quan-ve-thuat-toan-brute-force-trong-lap-trinh/ 

* chess ai algorithm
    - minimax algorithm tic tac toe
    - https://www.freecodecamp.org/news/simple-chess-ai-step-by-step-1d55a9266977/
    - https://www.cs.cornell.edu/boom/2004sp/ProjectArch/Chess/algorithms.html
    - minimax algorith
    - 
* recursion
    - https://realpython.com/python-recursion/
    - https://www.geeksforgeeks.org/introduction-to-recursion-data-structure-and-algorithm-tutorials/
    - https://www.freecodecamp.org/news/how-recursion-works-explained-with-flowcharts-and-a-video-de61f40cb7f9/
    - https://www.geeksforgeeks.org/sudoku-backtracking-7/
    - https://www.google.com/search?q=brute+force+in+maze+solving&rlz=1C1FKPE_viVN991VN991&oq=brute+force+in+maze+solving&aqs=chrome..69i57j33i160l2.8774j0j7&sourceid=chrome&ie=UTF-8
    - https://en.wikipedia.org/wiki/Maze-solving_algorithm
    - https://gist.github.com/Chuwiey/1e34ed9e65d41b735d8c

    graph traversal
    https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/
    https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/
    https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-on-directed-graph/
    self balancing binary search trees ?

    https://realpython.com/tic-tac-toe-python/
    https://realpython.com/tic-tac-toe-ai-python/
    
# git 
        https://git-scm.com/book/en/v2/Git-Basics-Viewing-the-Commit-History
        https://viblo.asia/p/cac-cach-xem-lich-su-commit-trong-git-63vKjJjMK2R

    stale review on github
        https://github.com/orgs/community/discussions/12876
        https://git-scm.com/book/en/v2/Git-Basics-Working-with-Remotes
        https://www.theserverside.com/blog/Coffee-Talk-Java-News-Stories-and-Opinions/How-to-use-the-git-clean-command
        https://git-scm.com/docs/git-clean

    how to use git blame
        https://git-scm.com/docs/git-blame
    git pull -> 1 hay nhiều branch  
    git fetch -> 1 hay nhiều branch
    https://docs.github.com/en
    cherry pick một commit nằm sau một commit khac
    What is `git restore` and how is it different from `git reset`? - Stack Overflow 
    https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository#_ignoring
    https://git-scm.com/docs/git-restore compare to checkout – .

# Linux
    - source command
    - ntq
    - Write a service in linux
    - symbol link in linux
    - curl -I ' ' 2>/dev/null | grep -i '^date:' | sed 's/^[Dd]ate: //g'
    - curl -I 'google.com' 2>/dev/null | grep -i '^date:' | sed 's/^[Dd]ate: //g'
    * In short, the differences between service and systemctl commands can be summarized as two different commands for two different init systems.SysVInit and SystemD
    * The service command is a wrapper script for /etc/init.d scripts and Upstart's initctl command, and systemctl as well
    * iptables
        - iptables là firewall dùng để define các rule cho phép hoặc không cho phép connection vào một ip/port
        - có 2 loại firewall: Bảo vệ (chặn bên ngoài tấn công vào), ngăn chặn (kiểm duyệt các kết nối từ trong ra))
        - proxy server là cách dùng một interface để chuyển tiếp gói tin. giúp kiểm duyệt và lưu cache tốt hơn
    https://www.howtogeek.com/839285/how-to-list-linux-services-with-systemctl/
    https://www.tecmint.com/list-all-running-services-under-systemd-in-linux/
    https://devconnected.com/how-to-list-services-on-linux/
    sudo systemctl status dns-sync.service
    * https://docs.kernel.org/filesystems/overlayfs.html
    * https://wiki.archlinux.org/title/Overlay_filesystem
    * https://en.wikipedia.org/wiki/OverlayFS
    * class mang

    * Found a swap file by the name ".TODOlist.md.swp"
              owned by: pi   dated: Mon Apr 29 10:31:48 2024
             file name: ~pi/workspace/tobearrange/TODOlist.md
              modified: YES
             user name: pi   host name: raspberrypi
            process ID: 1832
    While opening file "TODOlist.md"
                 dated: Mon Apr 29 10:30:11 2024

    (1) Another program may be editing the same file.  If this is the case,
        be careful not to end up with two different instances of the same
        file when making changes.  Quit, or continue with caution.
    (2) An edit session for this file crashed.
        If this is the case, use ":recover" or "vim -r TODOlist.md"
        to recover the changes (see ":help recovery").
        If you did this already, delete the swap file ".TODOlist.md.swp"
        to avoid this message.
    - link and symbolic link - create a Symbolic Links
    - https://www.geeksforgeeks.org/soft-hard-links-unixlinux/
    - https://www.nixtutor.com/freebsd/understanding-symbolic-links/
    - https://viblo.asia/p/hard-links-va-symbolic-links-tren-linux-07LKXJR2lV4
    - https://phoenixnap.com/kb/symbolic-link-linux
    - log rotate
    - https://www.computerhope.com/issues/ch001638.htm
    - sudo nmcli c m eth0 ipv4.gateway "192.168.1.1" && \
    - sudo nmcli c m eth0 ipv4.address "192.168.1.100" && \
    - sudo nmcli d c eth0 && \
    - sudo ip route add default via 192.168.1.1 dev eth0

* named pipe 
    - https://linuxconfig.org/identifying-file-types-in-linux
    - https://stackoverflow.com/questions/7646592/how-to-create-a-linux-fifo-pipe-or-something-which-does-not-block-writer-an
    - https://www.gnu.org/software/libc/manual/html_node/FIFO-Special-Files.html
    - https://man7.org/linux/man-pages/man7/fifo.7.html
https://www.freecodecamp.org/news/shell-scripting-crash-course-how-to-write-bash-scripts-in-linux/
https://www.geeksforgeeks.org/bash-scripting-functions/
    khi nào thì shell fork 1 process mới
    What difference between the below lines
        echo `cmd`
        echo $(cmd)
        echo < (cmd)
    Where to read 'rm' (and other linux util) command source 
    build and install my own customed bash (or any linux utility)

    About environment variable
    The environment variables of a process exist at runtime, and are not stored in some file or so. They are stored in the process's own memory (that's where they are found to pass on to children). But there is a virtual file in
    /proc/pid/environ

    Check size and its contents
    https://www.howtouselinux.com/post/ check-directory-size-in-linux#:~:text=The%20procedure%20to%20check%20directory%20size%20in%20Linux,in%20human%20readable%20format%20 (e.g.,%201K%20234M%202G)
    why ls show dir size at 4k
    linux command to run in background, how to know whether a command spawn sub process
    find --user <to check files belong to a user>
    open a file in read only mode linux
    write protected file? is there anything called like that?
    is there a transaction for bash script
    how to make a tab-completion path work in command line param
    STRATEGY TO debug a bash script 
    shell - How can I debug a Bash script? - Stack Overflow
    syslog c++ and pytthon
    https://stackoverflow.com/questions/13332268/how-to-use-subprocess-command-with-pipes
how bash look for binary of a commands? the order of /bin, /usr/... where it look? nếu 1 binary xuất hiện tỏng nhiều foldẻ thì sao 
investigate xem khi gọi 1 command (such as 'ls' thì fork system call được gọi như thế nào? có thể strace 1 process từ trước khi nó được gọi để inspect)
How to handle interactive actions in non-interactive more (extract script?) nhập password các thứ

Nếu 1 script viết bằng bash, sau đó giữa chừng muốn đổi sang shell khác thì dùng ntn
nếu 1 script take time thì terminal chờ hay interupt nếu không send background hoặc foreground?
Install mailutils to send mail 
Một process luôn có nhiều file descriptor, trong đó có 3 file descriptor mặc định. Vậy làm sao để tăng, giảm, dùng file descriptor như thế nào
It is important to understand that file descriptors are process specific: to speak of "standard output" only makes sense when referring to a specific process

Exit vs return 
Exit terminates the entired script while return end the function only.
declare / let/ export

process groups?
process id?
https://www.baeldung.com/linux/kill-members-process-group
# proc in expect script
    expect is used for interactive mode
    Spawn.h

# Context Switching
    Interrupts
    Multitasking
    User/Kernel switch
    # Process Control Block(PCB), Task Control Block
    It is a data structure used by a computer to store all information about a process
    # Process Context Switching 
    # User mode 
    - crash in user mode brings down the faulty process only
    # Kernel mode
    - A crash in kernel mode bring down the whole system
    - The only entry point are system calls interface (SCI)
    https://www.tutorialspoint.com/assembly_programming/assembly_system_calls.htm
    https://www.geeksforgeeks.org/operating-systems/introduction-of-system-call/
    https://www.geeksforgeeks.org/user-mode-and-kernel-mode-switching/
    how asm code call system call
    x86_64 instruction set

    System calls are divided into 5 categories mainly :

Process Control
File Management
Device Management
Information Maintenance
Communication
list of system calls: 
https://man7.org/linux/man-pages/dir_section_2.html
``` list syscalls
man -k syscalls
man 2 intro
```

# C++
    https://stackoverflow.com/questions/5724171/passing-an-array-by-reference
    https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
    https://www.geeksforgeeks.org/segmentation-fault-c-cpp/

    https://www.geeksforgeeks.org/cpp-literals/

    We cannot pass items bigger than an integer to functions, you need pointer to address this case
    https://www.geeksforgeeks.org/pointer-arithmetics-in-c-with-examples/
    Library
    https://cppdeveloper.com/c-nang-cao/phan-biet-static-libraries-va-shared-libaries/
    https://www.boost.org/build/doc/html/bbv2/faq/header-only-libraries.html
    https://www.reddit.com/r/cpp_questions/comments/ug2nbr/header_only_libraries/?rdt=40109
    https://stackoverflow.com/questions/9246570/are-lib-files-useless-without-the-header-files
    Event handling 
    https://stackoverflow.com/questions/9711414/what-is-the-proper-way-of-doing-event-handling-in-c
    https://stackoverflow.com/questions/7464025/designing-an-event-mechanism-in-c

    https://www.geeksforgeeks.org/type-conversion-in-c/
    
    https://en.cppreference.com/w/cpp/atomic/atomic
    User-defined literals [CppLessons/Session2_BasicLanguageFacilities/Lesson1/15_UserLiteral]
    https://github.com/xizhengszhang/Leetcode_company_frequency
    https://learngitbranching.js.org/?locale=vi
    https://github.com/ripienaar/free-for-dev
    https://github.com/topics/tower-of-hanoi?l=python

    https://www.geeksforgeeks.org/sudoku-backtracking-7/
    https://www.geeksforgeeks.org/stack-in-python/
    https://www.learnpython.org/
    
    https://stackoverflow.com/questions/2298242/callback-functions-in-c#:~:text=A%20callback%20is%20a%20callable,be%20reused%20with%20different%20callbacks.
    https://www.geeksforgeeks.org/synchronization-by-using-semaphore-in-python/
    https://www.codespeedy.com/semaphores-in-cpp/#:~:text=What%20is%20a%20semaphore%3F,used%20to%20access%20common%20resources.
    https://www.modernescpp.com/index.php/semaphores-in-c-20
    https://en.cppreference.com/w/cpp/thread/counting_semaphore
    https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
    https://stackoverflow.com/questions/35160417/threading-queue-working-example
    gdb server
    build c++ source to include by <> or "", build lib .so, .o,
    static_assert
    What syntax is this
        template<typename... _Args>
        void emplace(_Args&&... __args)
    https://stackoverflow.com/questions/2448242/struct-with-template-variables-in-c
    explicit keyword
    Trong C++, có 5 cách ép kiểu tường minh:
        C-style casts
        Static casts <Ưu điểm của toán tử static_cast là nó yêu cầu compiler kiểm tra kiểu dữ liệu tại thời điểm biên dịch chương trình, hạn chế được những lỗi ngoài ý muốn.>
        Const casts
        Dynamic casts
        Reinterpret casts
    http://www.gotw.ca/gotw/009.htm
    https://en.cppreference.com/w/cpp/language/storage_duration
    https://en.cppreference.com/w/cpp/language/static
    The use of extern and static
    https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
    https://stackoverflow.com/questions/10422034/when-to-use-extern-in-c
    GDB asm
    how to use itorator to print vector -> explore to other use of itorator

    Đa hình trong C vs C++.
        Template được dịch trong runtime hay compile time?
        template với số parameter không cố định thì sao.

    There are two types of semantics that a type can have:
        Value semantics.
        Reference semantics. (Sometimes called pointer semantics.)

    final in C++ and python giống java
    give me an example that non-POSIX programs cannot run on different systems

    Memory Allocation Strategiess
Có nhiều chiến lược cấp phát bộ nhớ khác nhau, mỗi cái phù hợp với tình huống khác nhau. First Fit cấp phát block bộ nhớ trống đầu tiên đủ lớn, nhanh nhưng có thể gây fragmentation. Best Fit tìm block nhỏ nhất đủ lớn, giảm lãng phí nhưng chậm hơn. Worst Fit chọn block lớn nhất, hy vọng phần còn lại sau khi cấp phát vẫn đủ lớn để sử dụng cho các yêu cầu khác.

Trong thực tế, các memory allocator hiện đại như ptmalloc (trong glibc), jemalloc, hoặc tcmalloc sử dụng các kỹ thuật phức tạp hơn, kết hợp nhiều chiến lược và tối ưu cho multithreading.

Có nhiều công cụ để phát hiện memory leak như Valgrind, AddressSanitizer, Visual Studio Memory Profiler, hoặc các tools tích hợp trong IDE. Ngoài ra, việc sử dụng smart pointers trong C++ (như unique_ptr, shared_ptr) hoặc RAII pattern giúp quản lý bộ nhớ tự động và giảm nguy cơ leak.

Union in C++

static in C/C++. static in function definition and global/local variable

What this mean
std::ostream& operator<<(std::ostream &stream, const AlarmInfo& alarmInfo)
function to work with string in c/c++

Try to make sudoku game in C++, try to make c++ sudoku solver and call it by python.
what is glibc? 


what are obj C code/library
https://github.com/aras-p/ClangBuildAnalyzer
https://www.w3schools.com/cpp/cpp_data_structures.asp

https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf
https://www.open-std.org/jtc1/sc22/wg14/
https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/threads.h.html
https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/
https://kernel.org/
https://git.kernel.org/
What is size_t - Unsigned integer data type
https://www.geeksforgeeks.org/c/size_t-data-type-c-language/
Unsigned integer data type
unit test cpp application
pdb advance

https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/
https://www.tutorialspoint.com/why-use-static-cast-int-x-instead-of-int-x-in-cplusplus
what is an identifier in c++
https://stackoverflow.com/questions/103512/why-use-static-casttx-instead-of-tx

what is C-compatible.
https://ccrma.stanford.edu/~jos/stkintro/Useful_commands_gdb.html
https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_28.html
https://superuser.com/questions/401182/how-can-i-create-a-dump-file-of-a-running-process-in-linux
 
https://medium.com/@killianchateau/a-simple-sudoku-solver-in-c-f00fd2963c67

semaphore in c++ and python

test if run a program which raise a signal in GDB, will it actually raise signals? verify by listening on another process. 
if yes, debugging is safe, if no, it actually run and may impact other (write to file/sent data to network/db)

https://stackoverflow.com/questions/45053275/can-static-local-variable-be-wrongly-optimized
How g++ optimize variable
How debug mode afect optimization mode

What is literal in C++ modern
there are alternatives like scoped_array, shared_array and vector, you can use a shared_ptr to manage scope of an array (but after this I have no idea why I would want to

statics are not always constructed and deconstructed as you would expect. This is particularly true in cross-platform environments?????????

Mutex and mutable go together (M&M rule)
For a member variable, mutex (or similar synchronization type) implies mutable: A member variable that is itself of a synchronization type, such as a mutex or a condition variable, naturally wants to be mutable, because you will want to use it in a non-const way (e.g., take a std::lock_guard<mutex>) inside concurrent const member functions.
unwind the stack -> gaiir phóng stack -> unwind
allocator in c++
use scoped_array, as it has less overhead than shared_array

While this cannot help with naming, it is particularly important for an open source project to maintain a consistent style.
Note that you can cause integer underflow when performing some operations on unsigned values. For example:
what is integer underflow?
what difference between debug and release build, why assert macro is remove in release build.

castinng, converting between 2 object in C++/python. Ex: assign an object of class A to an object of class B
https://stackoverflow.com/questions/103512/why-use-static-casttx-instead-of-tx
about casting, try doing cast 2 object to see the difference

timer_create() in <time.h> create a POSIX per-process timer use in  timmer. Is it a C function or system calls?
The timer_create function is a POSIX function used in C and C++ to create a per-process timer. 
It is part of the <time.h> library and is commonly used in Linux-based systems. 
time_t in <ctime>

# Make/build
    The GNU C Library (glibc) manual
    https://sourceware.org/glibc/manual/
    
    What this make file mean
    '''
    %:
        $(MAKE) $@ -C ../
    '''
    can a library is included without a visible header
    build link boost library, static or dinamic lib
    Nếu có dynamic lib thì nhiều app cùng chạy cùng dùng file binary đó thì có được, làm sao để share cái binary đó cho nhiều process.
    problems of static lib and dynamic lib. What happend if 2 people working with a library and one of them is crazy.
    investigate the use of libtool, in make file

# About permission of a file 
    https://unix.stackexchange.com/questions/411889/what-does-it-mean-when-a-file-is-owned-by-the-user-root-and-the-group-root
    
# One technique to improve performance is branchless code  
    https://www.linkedin.com/pulse/green-light-coding-power-branchless-programming-heitor-machado-4039f/
    
# Linker and loader
    https://www.geeksforgeeks.org/introduction-of-compiler-design/
    https://www.geeksforgeeks.org/linker/
    https://www.geeksforgeeks.org/difference-between-linker-and-loader/
    https://stackoverflow.com/questions/3322911/what-do-linkers-do
    
# Core dump 
    https://stackoverflow.com/questions/5115613/core-dump-file-analysis
    https://cgi.cse.unsw.edu.au/~learn/debugging/modules/gdb_coredumps/
    https://cgi.cse.unsw.edu.au/~learn/debugging/modules/debugging_data_structures/#debugging-a-linked-list-on-paper
    https://cgi.cse.unsw.edu.au/~learn/debugging/modules/gdb_init_file/#gdb-init
    https://cgi.cse.unsw.edu.au/~learn/debugging/
    https://cppdeveloper.com/category/c-nang-cao/page/1/
    https://www.devx.com/terms/core-dump/#:~:text=A%20core%20dump%20is%20a%20file%20that%20captures,to%20analyze%20the%20program%E2%80%99s%20state%20during%20the%20crash.
    https://stackoverflow.com/questions/69983484/what-does-repeat-n-times-mean-in-gdb-debugger
    https://www.geeksforgeeks.org/gdb-step-by-step-introduction/
    https://stackoverflow.com/questions/8305866/how-do-i-analyze-a-programs-core-dump-file-with-gdb-when-it-has-command-line-pa
    https://stackoverflow.com/questions/52847568/how-to-setup-custom-breakpoints-in-the-c-program
    g++ build with breakpoint
    https://stackoverflow.com/questions/12386467/compile-options-g-debug-and-o-optimization
    debug crash mà không cần đợi coredump, chạy gdb tới chỗ crash rồi bt với full bt mà checker
    
# TDD 
    test driven development python c++
    https://testdriven.io/blog/modern-tdd/
    https://www.freecodecamp.org/news/learning-to-test-with-python-997ace2d8abe/
    https://www.geeksforgeeks.org/test-driven-development-tdd/
    
Apply opensaf, quản lý amf and amm - https://sourceforge.net/p/opensaf/code/ci/develop/tree/
how to apply opensaf
https://stackoverflow.com/questions/26399976/how-to-run-a-application-in-opensaf

Tipc path vary across sles version
Kafka message pub/sub
Add log level in python
Ftp, Tcp ip study in c++
tcpdump -a
Encrypt tcp pacqkge
Freertos
Threading, orphan thread process in python
Override and overload runtime and compile time
How to check where in the memory a variable is put
Backend C++
Import custom tkiner
Catch exception trong đệ quy

Static var in python, stringvar các thứ, thay đổi bên ngoài. How to hook a var
tìm hiểu về selenium nha , còn realtime nữa thì xem thêm về webhook
 Xargs, sed, awk

How to lấy biến từ môi trường build, pass variable from build command

Trong shell script làm sao để tạo sub task có pid mới hoặc shell mới
Đọc pdf dùng python
The use of std::ostream& 
G++ pass các cờ xuống sub process ntn

Subarray in c++
Con trỏ trên mảng 2 chiều, nếu tăng số byte 1 bieens ko chẵn thì sẽ đọc đc kí tự gì. Nếu shift con trỏ thì sao, nếu tăng số byte trong con trỏ struct thì sao

How asm code pass to hardware, through linux kernal without the syscall -> nếu malloc gọi syscall khác nhau trên linux and embedded thì syscall tìm memory ntn mà ko dùng deiver

Làm app nhắn tin c++ python go để học tcp

Pdb
Gdb server
Tạo socket/tạo/mở/đọc/xoá file, send signal bằng python/c% rồi check syscall

Any performance improvement in one line code python c++ asm
Build iso and take to install kvm
Kỹ thuật schedule các task định kì trong linux 

Code kernel
Bên trong maloc dùng linked list, đọc source linux để xác minh

Could not open lock file /var/lib/dpkg/lock-frontend. Permission denied, are you root
Itertool, collection
Stress test command
Auto_ptr

Array của object có đc allocate ngay lúc tạo array ko
Pointer arithmatic is a major concept in c
Atom operation in asm
Inside the python virtual machine

Trap signal
Driver của kernel

Cython chống dịch ngược, pyarrmo
Dịch ngược pyc to py
How bash script is executed, có chạy ra bin hay syscall ko

Deep and shadow copy in c++
Bitmap
Tải pypy và các interpreter khác về xem  va nghien cuu GIL

what is root user and root group user, who has right to peform sudo, what í sudoer file
chat gpt ai, làm app thu chi
vì sao indexing dùng B+ tree
￼kafka
tipc

what is the default stdin/stdout

check ecimswmmethodtracer.hh

call C ++ from python and call puthon from c++
￼yocto
etcd
get process state in linux?

struct pollfd : the data structure describing a polling request
struct polls {
int fd;
short int events
}

# Devops
    etcd for distributed storage
    yocto
    https://etcd.io/
    https://github.com/etcd-io/etcd
    https://etcd.io/docs/v3.6/install/#homebrew-on-linux
    https://kubernetes.io/vi/docs/setup/production-environment/tools/kubeadm/setup-ha-etcd-with-kubeadm/

# general tech
    https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard
    https://partner.cloudskillsboost.google/course_sessions/4860924/video/384314
    https://www.baeldung.com/cs/
    https://refactoring.guru/
    https://peps.python.org/pep-0000/
    Game Programming Patterns by Robert Nystrom - https://gameprogrammingpatterns.com/
    https://cplusplus.com/
    https://cplusplus.com/reference/
    https://en.cppreference.com/w/
    https://cppcon.org/
    https://guide.bash.academy/
    https://mywiki.wooledge.org/BashGuide
    GNU Core Utilities repo
    Django and django rest framwork?
    https://github.com/igl42
Khóa safe C++
https://github.com/igl42
https://github.com/curl/curl
https://daniel.haxx.se/
https://flamingdangerzone.com/cxx11/rule-of-zero/
https://www.electronicshub.org/sram-vs-dram/
https://www.geeksforgeeks.org/computer-organization-architecture/difference-between-sram-and-dram/
https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2010/n3092.pdf

# Rasp pico 
any technique to put a c variable on flash memory (like PROGMEM in arduino)
example of request time

# None -tech 
    - https://en.wikipedia.org/wiki/Trade_union#Structure_and_politics
    - https://en.wikipedia.org/wiki/Labour_movement
    - https://en.wikipedia.org/wiki/Portal:Communism
    - https://en.wikipedia.org/wiki/Portal:Socialism
    - https://www.16personalities.com/personality-types
    - https://isha.sadhguru.org/en/sadhguru
    - ebook
    - https://gitlab.com/Phucbooks/books?fbclid=IwAR0W84m-K6fRmhOzNWP2mhf4PdJ0CKl2wQveuQmWHi9jMI5AgFj4PN_KQKE
    - https://kindlehanoi.vn/thuviensach/
    - https://www.linkedin.com/pulse/30-difficult-ielts-cue-card-topics-answer-razibul-hassan/
    - https://quillbot.com/
new line
