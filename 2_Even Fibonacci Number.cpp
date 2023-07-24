#include <iostream>

int main() {
    int limit = 4000000;
    int sum = 0;
    int a = 1, b = 2;

    while (b <= limit) {
        if (b % 2 == 0) {
            sum += b;
        }
        int temp = a + b;
        a = b;
        b = temp;
    }

    std::cout << "The sum of even-valued terms in the Fibonacci sequence below 4 million is: " << sum << std::endl;
    return 0;
}
