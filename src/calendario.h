#ifndef _CALENDARIO_H_
#define _CALENDARIO_H_

#include <vector>
#include <string>

using std::vector; using std::string;

class Calendario{
protected:
    
    const string nomes[13] = {"null", "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro","Novembro", "Dezembro"};
    const int daysOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    const int daysOfMonthL[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    
public:
    
    //Calendario();

};

#endif
