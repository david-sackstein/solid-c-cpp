#pragma once

// C function, intended to be called from C++
#ifdef __cplusplus
extern "C" {
#endif

void c_print_message(const char* msg);
int c_add(int a, int b);

#ifdef __cplusplus
}
#endif

// For demonstration: a function without extern "C" (will cause issues)
void c_noextern_function(const char* msg);