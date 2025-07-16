#include <library.h>

// Private static functions
static int sum(int a, int b) {
    return a + b;
}

static int product(int a, int b) {
    return a * b;
}

// Public function
int compute_sum_and_product(int a, int b) {
    // Example: return sum + product
    return sum(a, b) + product(a, b);
}
