#ifndef _DATA_H
#define _DATA_H


class Data: public Calendario{

	int day,month, year;
    public:
    Data(int day, int month, int year);
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);
    void showDAta() const;

};

#endif
