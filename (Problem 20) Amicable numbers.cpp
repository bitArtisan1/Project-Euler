#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> amicableNumber() {
    vector<int> amicableNums;
    int divisors_A, divisors_B;
    for (int j = 1; j <= 10000; j++) {
        divisors_A = 0;
        divisors_B = 0;
        for (int i = 1; i <= sqrt(j); i++) {
            if (j % i == 0) {
                divisors_A += i;
                if (i != sqrt(j) && i != 1)
                    divisors_A += j / i;
            }
        }
        for (int i = 1; i <= sqrt(divisors_A); i++) {
            if (divisors_A % i == 0) {
                divisors_B += i;
                if (i != sqrt(divisors_A) && i != 1)
                    divisors_B += divisors_A / i;
            }
        }
        if(divisors_B == j && divisors_A != j){
            amicableNums.push_back(j);
            amicableNums.push_back(divisors_A);
        }
    }
    return amicableNums;
}

int amicableSum(vector<int> D){
    int sum = 0;
    for(int i = 0; i < D.size(); i += 2) {
        sum += D[i];
    }
    return sum;
}


int main(){
    vector<int> amicableNums = amicableNumber();
    for(int i = 0; i < amicableNums.size(); i += 2) {
        cout << amicableNums[i] << endl;
    }
    
    cout << "Sum of the amicable numbers below 10000: " << amicableSum(amicableNums);
    return 0;
}


