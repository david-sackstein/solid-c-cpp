#pragma once

// C++ function intended to be called from C
#ifdef __cplusplus
extern "C" {
#endif

void cpp_print_message(const char* msg);
int cpp_multiply(int a, int b);

#ifdef __cplusplus
}
#endif

// For demonstration: a function without extern "C" (will cause issues)
void cpp_noextern_function(const char* msg);