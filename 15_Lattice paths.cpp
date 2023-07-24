//Using a dynamic programming approach instead of the binomial coefficient
#include <iostream>

using namespace std;

long long countRoutes(int gridSize){
	
    const int size = gridSize + 1;
    long long grid[size][size] = {0};
    
    for (int i = 0 ; i < size ; ++i){
        grid[0][i] = 1;
        grid[i][0] = 1;
    }
    for (int i = 1 ; i < size ; ++i){
        for (int j = 1 ; j < size ; ++j){
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    return grid[size - 1][size - 1];
}

int main(){
	
    int gridSize = 20;
    long long routes = countRoutes(gridSize);

    cout << routes;

    return 0;
}

