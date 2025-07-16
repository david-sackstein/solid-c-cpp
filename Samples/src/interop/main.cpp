#include "c_func.h"
#include "cpp_func.h"
#include <iostream>

// Forward declaration for demonstration (simulate C code calling C++ function)
extern "C" {
    void cpp_print_message(const char* msg);
    int cpp_multiply(int a, int b);
    // void cpp_noextern_function(const char* msg); // This would fail to link!
}

int main() {
    // C++ calling C functions (with extern "C")
    c_print_message("Hello from C++ to C!");
    std::cout << "C add: " << c_add(2, 3) << std::endl;

    // C++ calling C function without extern "C" (should link, but name mangling may occur)
    // c_noextern_function("This may not link if compiled as C++!");

    // C++ calling C++ functions (with extern "C")
    cpp_print_message("Hello from C++ to C++ (extern C)!");
    std::cout << "C++ multiply: " << cpp_multiply(4, 5) << std::endl;

    // C++ calling C++ function without extern "C" (should work, but not callable from C)
    cpp_noextern_function("Hello from C++ to C++ (no extern C)!");

    return 0;
}