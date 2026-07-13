#include <iostream>
#include <new>      // Required for std::size_t and std::bad_alloc
#include <cstdlib>  // Required for malloc and free

void* operator new(std::size_t size) {
    std::cout << "Global new operator called, size: " << size << " bytes" << std::endl;
    void* ptr = std::malloc(size); // Use standard malloc for raw memory
    if (!ptr) {
        throw std::bad_alloc(); // Handle allocation failure
    }
    return ptr;
}

void operator delete(void* ptr) noexcept { // noexcept is recommended in modern C++
    std::cout << "Global delete operator called" << std::endl;
    std::free(ptr); // Use standard free to deallocate
}

// Don't forget the array versions
void* operator new[](std::size_t size) {
    std::cout << "Global new[] operator called, size: " << size << " bytes" << std::endl;
    void* ptr = std::malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }
    return ptr;
}

void operator delete[](void* ptr) noexcept {
    std::cout << "Global delete[] operator called" << std::endl;
    std::free(ptr);
}

#include <iostream>
#include <cstdlib>

class MyClass {
public:
    // new and delete are static by default, therefore they don't have access to 'this' pointer.
    void* operator new(std::size_t size) {
        std::cout << "MyClass specific new operator, size: " << size << " bytes" << std::endl;
        return std::malloc(size);
    }

    void operator delete(void* ptr) noexcept {
        std::cout << "MyClass specific delete operator" << std::endl;
        std::free(ptr);
    }
};

int main() {
    // This will call MyClass's overloaded operators
    MyClass* obj = new MyClass;
    delete obj;

    // This will call the global operators (if defined, otherwise standard)
    int* num = new int(10);
    delete num;

    return 0;
}
