#include <iostream>
#include <cstring>

const int MAX_DIGITS = 10000; // Maximum number of digits in the result

void multiply(int result[], int& resultSize, int num){
	
    int carry = 0; 
    for (int i = 0 ; i < resultSize ; i++){
        int prod = result[i] * num + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    
    while (carry > 0){
        result[resultSize] = carry % 10;
        carry /= 10;
        resultSize++;
    }
}

void power(int base, int exponent){
	
    int result[MAX_DIGITS];
    std::memset(result, 0, sizeof(result));
    result[0] = 1;
    int resultSize = 1, sum = 0;
    
    for (int i = 0 ; i < exponent ; i++){
        multiply(result, resultSize, base);
    }
    
    for (int i = resultSize - 1 ; i >= 0 ; i--){
        std::cout << result[i];
        sum += result[i];
    }
    std::cout<< "\n Sum of all terms:" << sum;
}

int main(){
	
    int base = 2;
    int exponent = 1000;
    
    power(base, exponent);    
    return 0;
}

