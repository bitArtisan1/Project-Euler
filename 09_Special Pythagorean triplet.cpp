#include <iostream>

using namespace std;

int findPythagoreanTriplet(){
    int abc = 0;
    
    for(int i = 1 ; i < 1000 ; i++){
        for(int j = 1 ; j < 1000 ; j++){
            for(int k = 1 ; k < 1000 ; k++){
                if(k * k + j * j == i * i && i + j + k == 1000)
                return i * j * k;
            }
        }
    }
}

int main() {
   
    cout << findPythagoreanTriplet();
    return 0;
}
