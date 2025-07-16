#include "cpp_func.h"
#include <iostream>

void cpp_print_message(const char* msg) {
    std::cout << "C++ says: " << msg << std::endl;
}

int cpp_multiply(int a, int b) {
    return a * b;
}

// This function is not protected by extern "C"
void cpp_noextern_function(const char* msg) {
    std::cout << "C++ (no extern) says: " << msg << std::endl;
}
