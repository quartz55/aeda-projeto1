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
            if(day < daysOfMonthL[month]){
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
            if(day < daysOfMonth[month]){
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
    cout << day << " de " << nomes[month] << " de " << year << endl;

}
bool Data::operator< (const Data &d1) const{
    if(year * 10000 + month * 10 + day  < d1.year * 10000 + d1.month * 10 + d1.day){
        return true;
    }
    else {
        return false;
    }
}

int Data::getDay() const {
	return day;
}

int Data::getMonth() const {
	return month;
}

int Data::getYear() const {
	return year;
}
