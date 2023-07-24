#include <iostream>
#include <numeric>

int main() {
    int lcm_result = 1;
    for (int i = 2; i <= 20; i++) {
        lcm_result = std::lcm(lcm_result, i);
    }

    std::cout << "The smallest positive number divisible by all numbers from 1 to 20 is: " << lcm_result << std::endl;
    return 0;
}
