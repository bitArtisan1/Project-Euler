#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

vector<int> primes;

vector<int> sieveOfEratosthenes(long long n){
    primes.push_back(2);
    
    for(int i = 3 ; i <= n ; i += 2){
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

long long sumPrime(vector<int> prime){
	
	long long sum = 0;
	
	for(int i = 0 ; i < prime.size() ; i++){
		
		sum += prime[i];
	}
	return sum;
}

int main(){
	
	long long n = 2000000;
    cout << sumPrime(sieveOfEratosthenes(n));

}
