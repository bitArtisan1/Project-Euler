#include <iostream>

bool is_prime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    int count = 0;
    int number = 2;

    while (count < 10001) {
        if (is_prime(number)) {
            count++;
        }
        number++;
    }

    std::cout << "The 10,001st prime number is: " << number - 1 << std::endl;
    return 0;
}
