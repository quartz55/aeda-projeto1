#ifndef _DATA_H
#define _DATA_H

#include "calendario.h"
#include <iostream>

using std::stringstream;

class Data : public Calendario{

    int day, month, year;

    public:
    Data(int day, int month, int year);
    bool leapYear() const;
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);
    string showData() const;
    void setData(int day, int month, int year);
    bool operator< (const Data &d1) const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};

#endif
