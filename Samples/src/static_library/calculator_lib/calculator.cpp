#include <calculator.h>

// Local static functions
static int sum(int a, int b) {
    return a + b;
}

static int product(int a, int b) {
    return a * b;
}

// Exported function
int compute_sum_and_product(int a, int b) {
    return sum(a, b) + product(a, b);
}
