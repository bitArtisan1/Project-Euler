#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

cpp_int largeFactorial(int n){
    cpp_int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
int sumDigits(cpp_int number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10; 
        number /= 10;       
    }
    return sum;
}
int main(){
    int n = 100;
    cpp_int factorialValue = largeFactorial(n);
    
    std::cout << "Sum of the digits of " << n << "! :" << sumDigits(factorialValue) << std::endl;

    return 0;
}

