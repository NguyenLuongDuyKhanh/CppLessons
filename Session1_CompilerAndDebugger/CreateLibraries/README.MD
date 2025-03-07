An application can be built with a header without link a lib, in that case, the build would succeed but no concrete code is implemented.
File header và objectso/libs là khác nhau, khi include thì cần file header, nhưng khi cần chạy thì linker phải tìm được objects, nếu chỉ có header mà không có object thì cũng không chạy được

# Về binary file and executable file
A binary is a file containing linked object code, an executable is a file with the executable permission bit set. All binaries should be executable (although not necessarily an executable), but not all of them do anything useful when executed. 
Binary files are not necessarily executable, for example a library compiled to .dll or .so form is a binary but not an executable
https://stackoverflow.com/questions/59826292/where-is-the-difference-between-binaries-and-executables-in-the-context-of-a?newreg=1bbeada8e2ea4b028744f6c0354563e5
Link  rất hay, nói về việc thêm shebang, xem đoạn dưới:
Binary files are not necessarily executable, for example a library compiled to .dll or .so form is a binary but not an executable. A Java program compiled to .class or .jar form is not an executable file, but might be run using the command java -jar program.jar rather than the command ./program.jar.

Executable files are not necessarily binary, for example a Python script in text form can be made executable on Unix systems by writing a shebang line #!/usr/bin/python3 and setting the file's executable flag.

# Về linker
When a C program is compiled, the compiler generates object code. After generating the object code, the compiler also invokes linker. One of the main tasks for linker is to make code of library functions (eg printf(), scanf(), sqrt(), ..etc) available to your program.

A linker can accomplish this task in two ways, by copying the code of library function to your object code, or by making some arrangements so that the complete code of library functions is not copied, but made available at run-time.
https://www.geeksforgeeks.org/static-vs-dynamic-libraries/

# Static
- Được link tại build/compile time
- Apply static linking, copy of all used library functions to the executable file -> create bigger binary file on disk and memory

- File thư viện là file object đã linked -> khi build app thì build lại bản sau của lib luôn
- Tên lib***.a or ***.lib - linker dùng tên này để tìm nên phải đúng convention.
- Thư viện được cung cấp dưới dạng file header và .a/.lib
- Khi lib thay đổi thì build lại lib và app

# Dynamic/shared
- Là object link, Được dùng bởi nhiều application và load vào app lúc runtime 
- Tên lib***.so or lib***.dll
- Khi lib thay đổi thì phải link lại file .so là được.

# TODO verify:
- Kiểm tra các thư viện build-in xem là static hay dynamic.
- test trường hợp include thư viện (kể cả static và dynamic) có file header nhưng không có object xem sao.
- Dynamic có thật sự được dùng bởi nhiều application không? Static có được không?
- Thư viện không có header thì sao? có include được không