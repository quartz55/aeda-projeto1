#include "data.h"
#include <sstream>


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
	day = 1;
	while (months > 0) {
		if (month < 12) {
			month++;
			months--;
		}
		else{
			month = 1;
			year++;
		}
	}
}
void Data::addYears(int years){
	while(years > 0) {
		year++;
		years--;
	}
}



string Data::showData() const {
	stringstream ss;
	ss << day << " de " << nomes[month] << " de " << year;
	return ss.str();

}
bool Data::operator< (const Data &d1) const{

	if(year * 10000 + month * 100 + day  < d1.year * 10000 + d1.month * 100 + d1.day){
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

void Data::setData(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int Data::getYear() const {
	return year;
}
