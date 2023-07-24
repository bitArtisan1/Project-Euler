#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to swap two elements in a vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to reverse elements in a vector from start index to end index
void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr, start, end);
        start++;
        end--;
    }
}

// Function to generate lexicographic permutations
void generatePermutations(vector<int>& arr, vector<vector<int>>& permutations) {
    permutations.push_back(arr);

    while (true) {
        int n = arr.size();
        int i = n - 2;

        // Find the largest index i such that arr[i] < arr[i+1]
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        if (i < 0) {
            // No more permutations
            break;
        }
        int j = n - 1;
        // Find the largest index j such that arr[i] < arr[j]
        while (arr[j] <= arr[i]) {
            j--;
        }
        swap(arr, i, j);
        reverse(arr, i + 1, n - 1);

        permutations.push_back(arr);
    }
}

void printPermutation(const vector<int>& permutation) {
    for (const int digit : permutation) {
        cout << digit;
    }
    cout << endl;
}

int main() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<vector<int>> lexicographicPermutations;
    generatePermutations(digits, lexicographicPermutations);

        cout << "Millionth Permutation: ";
        printPermutation(lexicographicPermutations[999999]);
   
    return 0;
}

