#include <iostream>

int main() {
    int n = 100;
    int sum_of_squares = (n * (n + 1) * (2 * n + 1)) / 6;
    int square_of_sum = (n * (n + 1) / 2) * (n * (n + 1) / 2);

    int difference = square_of_sum - sum_of_squares;

    std::cout << "The difference between the sum of the squares and the square of the sum of the first 100 natural numbers is: " << difference << std::endl;
    return 0;
}
