#include <iostream>

using namespace std;

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int largestPalindrome = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int product = i * j;
            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }
    cout << largestPalindrome;
    return 0;
}

