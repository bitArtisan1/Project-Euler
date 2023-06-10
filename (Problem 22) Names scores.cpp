#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int calculateNameScore(const string& name, const map<char, int>& alphabetDictionary) {
    int nameScore = 0;
    for (const auto& letter : name) {
        if (alphabetDictionary.find(letter) != alphabetDictionary.end()) {
            nameScore += alphabetDictionary.at(letter);
        }
    }
    return nameScore;
}

int main() {
    vector<string> names;
    string filename = "0022_names.txt";

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            while (pos < line.length()) {
                if (line[pos] == '"') {
                    size_t nextQuote = line.find('"', pos + 1);
                    if (nextQuote != string::npos) {
                        string name = line.substr(pos + 1, nextQuote - pos - 1);
                        names.push_back(name);
                        pos = nextQuote + 2;
                    }
                }
                else {
                    size_t nextComma = line.find(',', pos);
                    if (nextComma != string::npos) {
                        string name = line.substr(pos, nextComma - pos);
                        names.push_back(name);
                        pos = nextComma + 1;
                    }
                    else {
                        string name = line.substr(pos);
                        names.push_back(name);
                        break;
                    }
                }
            }
        }
        file.close();
    }
    else {
        cout << "Failed to open the file." << endl;
        return 0;
    }

    sort(names.begin(), names.end());

    for (const auto& name : names) { // Print sorted names
        cout << name << " ";
    }
    cout << endl;

    map<char, int> alphabetDictionary = {
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'D', 4},
        {'E', 5},
        {'F', 6},
        {'G', 7},
        {'H', 8},
        {'I', 9},
        {'J', 10},
        {'K', 11},
        {'L', 12},
        {'M', 13},
        {'N', 14},
        {'O', 15},
        {'P', 16},
        {'Q', 17},
        {'R', 18},
        {'S', 19},
        {'T', 20},
        {'U', 21},
        {'V', 22},
        {'W', 23},
        {'X', 24},
        {'Y', 25},
        {'Z', 26}
    };

    int totalScore = 0;
    for (size_t i = 0; i < names.size(); i++) { // Calculate total scores
        int nameScore = calculateNameScore(names[i], alphabetDictionary);
        int nameWeightedScore = nameScore * (i + 1);
        totalScore += nameWeightedScore;
    }

    cout << "Total score of all name scores: " << totalScore << endl;

    return 0;
}

