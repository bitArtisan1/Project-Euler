#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    if (number < 2)
        return false;

    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int countPrimeRange(int a, int b) {
    int n = 0;
    while (isPrime(n * n + a * n + b))
        ++n;
    return n;
}

int main() {
    int max = 0;
    int product = 0;

    for (int a = -999; a < 1000; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            int count = countPrimeRange(a, b);
            if (count > max) {
                max = count;
                product = a * b;
            }
        }
    }
    cout << "Product of the coefficients: " << product << endl;

    return 0;
}

