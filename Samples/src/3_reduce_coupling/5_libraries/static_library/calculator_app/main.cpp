#include <iostream>

#include <calculator.h>

int main() {
    int a = 3, b = 4;
    int result = compute_sum_and_product(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
