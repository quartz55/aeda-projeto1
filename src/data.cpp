#include "data.h"


Data::Data(int day, int month, int year){
	this->day = day;
	this->month = month;
	this->year = year;
}

bool Data::leapYear() const {
    return year % 4 == 0 ? true : false;
}

void Data::addDays(int days){
    if(leapYear()){
        while(days > 0){
            if(day < daysOfMonthL[month-1]){
                day++;
                days--;
            }
            else {
                if (month < 12) {
                    month++;
                    days--;
                    day = 1;
                }
                else{
                    year++;
                    day = 1;
                    month = 1;
                    days--;
                }
            }
        }
    }
    else {
        while(days > 0){
            if(day < daysOfMonth[month-1]){
                day++;
                days--;
            }
            else {
                if (month < 12) {
                    month++;
                    days--;
                    day = 1;
                }
                else{
                    year++;
                    day = 1;
                    month = 1;
                    days--;
                }
            }
        }

    }
}
void Data::addMonths(int months) {
    while (months > 0) {
        addDays(31);
        months--;
    }
}
void Data::addYears(int years){
    while(years > 0) {
        year++;
        years--;
    }
}


void Data::showData() const {
    cout << day << "/" << month << "/" << year << endl;
    
}
