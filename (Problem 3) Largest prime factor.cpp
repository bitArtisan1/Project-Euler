#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

vector<int> sieveOfEratosthenes(long long n){
    primes.push_back(2);
    
    for(int i = 3 ; i <= sqrt(n) ; i += 2){
        bool isPrime = true;
        
        for(int j = 2 ; j * j <= i ; j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        
        if(isPrime){
            primes.push_back(i);
        }
    }
    
    return primes;
}

vector<int> primeFactors(long long n){
    vector<int> factors;
    vector<int> primes = sieveOfEratosthenes(n);
    
    long long r = n;
    int i = 0;
    
    while(r > 1 && i < primes.size()){
        if(r % primes[i] == 0){
            factors.push_back(primes[i]);
            r /= primes[i];
        } else {
            i++;
        }
    }
    
    if(r > 1){
        factors.push_back(r);
    }
    
    return factors;
}

int main() {
    long long n = 600851475143;
    vector<int> factors = primeFactors(n);
    int largest = 0;
    for(int i = 0 ; i < factors.size() ; i++){
        if(factors[i] > largest)
        largest = factors[i];
        cout << factors[i] << " ";
    }
    cout << "\nLargest: " << largest;
    
    return 0;
}

