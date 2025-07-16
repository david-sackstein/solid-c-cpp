#include "c_func.h"

#include <stdio.h>

void c_print_message(const char* msg) {
    printf("C says: %s\n", msg);
}

int c_add(int a, int b) {
    return a + b;
}

// This function is not protected by extern "C"
void c_noextern_function(const char* msg) {
    printf("C (no extern) says: %s\n", msg);
}
