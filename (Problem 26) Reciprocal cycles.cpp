#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void isRecurring(int numerator, int denominator, unordered_map<int, int>& remainders, string& cycle, int& longestCycle) {
    while (numerator != 0) {
        numerator *= 10;
        int quotient = numerator / denominator;
        int remainder = numerator % denominator;

        if (remainders.count(remainder) > 0) {
            int cycleStartIndex = remainders[remainder];
            cycle += ")";
            cycle.insert(cycleStartIndex, "(");
            cout << "1/" << denominator << ": " << cycle << endl;

            int cycleLength = cycle.size() - cycleStartIndex - 2;
            if (cycleLength > longestCycle) {
                longestCycle = cycleLength;
            }

            return;
        }

        remainders[remainder] = cycle.size();
        cycle += to_string(quotient);
        numerator = remainder;
    }

    cout << "1/" << denominator << ": Non-recurring" << endl;
}

void recurringCycles(int d) {
    int longestCycle = 0;
    string longestCycleFraction;

    for (int i = 2; i <= d; i++) {
        int numerator = 1;
        int denominator = i;

        unordered_map<int, int> remainders;
        string cycle;

        isRecurring(numerator, denominator, remainders, cycle, longestCycle);

        if (cycle.size() > longestCycle) {
            longestCycle = cycle.size();
            longestCycleFraction = "1/" + to_string(denominator) + ": " + cycle;
        }
    }

    cout << "Longest recurring cycle: " << longestCycleFraction << endl;
}

int main() {
    int d = 1000;
    recurringCycles(d);

    return 0;
}

