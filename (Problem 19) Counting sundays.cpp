#include <iostream>

bool isLeapYear(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int countSundaysOnFirstOfMonth(){
    int count = 0;
    int dayOfWeek = 1;  // 1 Jan 1901 was a Tuesday (0 for Sunday, 1 for Monday, ..., 6 for Saturday)

    for(int year = 1900 ; year <= 2000 ; year++){
        for(int month = 1 ; month <= 12 ; month++) {
            if(dayOfWeek == 0 && year > 1900){
                count++;
            }

            // Get the number of days in the current month
            int daysInMonth;
            if(month == 2){
                daysInMonth = isLeapYear(year) ? 29 : 28;
            } else if(month == 4 || month == 6 || month == 9 || month == 11){
                daysInMonth = 30;
            } else{
                daysInMonth = 31;
            }

            // Update the day of the week for the first day of the next month
            dayOfWeek = (dayOfWeek + daysInMonth) % 7;
        }
    }

    return count;
}

int main(){
    int sundaysOnFirstOfMonth = countSundaysOnFirstOfMonth();
    std::cout << "Number of Sundays that fell on the first of the month during the twentieth century: "
              << sundaysOnFirstOfMonth << std::endl;

    return 0;
}

