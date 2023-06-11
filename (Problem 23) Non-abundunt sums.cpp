#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    vector<vector<int>> divisors(28124);
    vector<int> abundantNumbers;
    unordered_set<int> abundantSet;

    for (int j = 1; j < 28123; j++) {
        for (int i = 1; i <= sqrt(j); i++) {
            if (j % i == 0) {
                divisors[j].push_back(i);
                if (i != sqrt(j) && i != 1)
                    divisors[j].push_back(j / i);
            }
        }
    }

    for (int i = 0; i < divisors.size(); i++) {
        int sum = 0;
        for (int j = 0; j < divisors[i].size(); j++) {
            sum += divisors[i][j];
        }
        if (sum > i && abundantSet.find(i) == abundantSet.end()) {
            abundantNumbers.push_back(i);
            abundantSet.insert(i);
        }
    }

    vector<bool> isAbundantSum(28124, false);
    for (int i = 0; i < abundantNumbers.size(); i++) {
        for (int j = i; j < abundantNumbers.size(); j++) {
            int temp = abundantNumbers[i] + abundantNumbers[j];
            if (temp < 28124)
                isAbundantSum[temp] = true;
            else
                break;
        }
    }

    long nonAbundantSum = 0;
    for (int i = 1; i < 28124; i++) {
        if (!isAbundantSum[i])
            nonAbundantSum += i;
    }

    cout << "Sum of all positive non-abundant integers: " << nonAbundantSum << endl;

    return 0;
}

