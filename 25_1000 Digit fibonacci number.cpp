#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int, string> fibMemo;

string addStrings(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0)
            sum += num1[i--] - '0';
        if (j >= 0)
            sum += num2[j--] - '0';

        carry = sum / 10;
        sum %= 10;

        result = to_string(sum) + result;
    }

    return result;
}

string generateFibonacci(int n) {
    if (n <= 1)
        return to_string(n);

    if (fibMemo.find(n) != fibMemo.end())
        return fibMemo[n];

    string fib = addStrings(generateFibonacci(n - 1), generateFibonacci(n - 2));
    fibMemo[n] = fib;

    return fib;
}

int fibonacciIndex(int numDigits) {
    int index = 0;
    while (true) {
        string fibonacci = generateFibonacci(index);
        if (fibonacci.length() == numDigits)
            return index;
        index++;
    }
}

int main() {
    int numDigits = 1000;
    int index = fibonacciIndex(numDigits);

    cout << "The first Fibonacci number with " << numDigits << " digits is at index: " << index << endl;

    return 0;
}

