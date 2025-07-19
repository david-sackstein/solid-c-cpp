#include "c_func.h"
#include "cpp_func.h"

void c_print_message(const char* msg) {
    cpp_print_message("Hello from C to C++!");
    cpp_print_message(msg);
}
