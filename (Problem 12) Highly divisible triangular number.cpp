#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
vector<int> getFactors(int num){

    vector<int> factors;
    
    for(int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){
            factors.push_back(i); // Obtain the divider
        if(i != num / i) // Avoid Repetition (Perfect squares)
            factors.push_back(num / i); // Obtain the corresponding quotient
        }
    }

    return factors;
}

int triangleFactors(){
	
    int i = 1;
    
    while(true){
        int triangle = (i * (i + 1)) / 2;
        vector<int> factors = getFactors(triangle);
        i++;
        if (factors.size() > 500)
            return triangle;

    }
}

int main(){
	
	int result = triangleFactors();
	cout << "First Triangle Number With Over 500 Divisors: "<< result << "\n";
	// A quick example on how you can order the factors of n = 400 
    vector<int> allFactors = getFactors(400);
    
	sort(allFactors.begin(), allFactors.end());
    for(auto i : allFactors ){
    	cout << i << "  ";
	}
	
    return 0;
}

