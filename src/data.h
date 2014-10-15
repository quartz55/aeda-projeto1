#ifndef _DATA_H
#define _DATA_H

#include "calendario.h"
#include <iostream>

using std::cout; using std::endl;

class Data : public Calendario{

	int day, month, year;
    
    public:
    Data(int day, int month, int year);
    bool leapYear() const;
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);
    void showData() const;
    bool operator< (Data &d1) const;

};

#endif
