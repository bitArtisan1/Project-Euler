#include <iostream>
#include <map>
#include <string>

std::string number2Word() {
   static std::map<int, std::string> dictionary = {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "forty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"},
    {100, "one hundred"},
    {1000, "one thousand"}
};
    int totalLetters = 0;
    std::string spelling;
    
    for (int i = 1 ; i <= 1000 ; i++){
        int units, tenths, hundredths;
        units = i % 10;
        tenths = ((i / 10) % 10 )* 10;
        hundredths = (i / 100) % 10;

        if (hundredths != 0){
            spelling += dictionary[hundredths] + " hundred";

            if (tenths != 0 || units != 0)
                spelling += " and ";
        }
        if (tenths == 10)
            spelling += dictionary[tenths + units];
        else if (tenths != 0){
            spelling += dictionary[tenths];

            if (units != 0)
                spelling += " " + dictionary[units];
        }
        else if (units != 0)
            spelling += dictionary[units];
        if (i == 1000){
            spelling = "one thousand";
        }
        
        int letterCount = 0;
        for (char c : spelling){
            if (c != ' ')
                letterCount++;
        }
        totalLetters += letterCount;

        std::cout << spelling << " (" << letterCount << " letters)" << std::endl;
        spelling.clear();
    }
    std::cout << "Total letters: " << totalLetters << std::endl;
}

int main(){
    std::string word = number2Word();
    
    return 0;
}

