#include <iostream>

using namespace std;

int collatz_chain(long long n){
	
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
            
        length++;
    }
    return length;
}

int main(){
	
    int max_length = 0;
    long long max_starting_number = 0;

    for (long long starting_number = 1; starting_number < 1000000; starting_number++){
        int chain_length = collatz_chain(starting_number);
        
        if (chain_length > max_length){
            max_length = chain_length;
            max_starting_number = starting_number;
        }
    }

    cout << "Max Starting Num: " << max_starting_number << std::endl;
    cout << "Collatz Sequence Chain: " << max_length << std::endl;

    return 0;
}

