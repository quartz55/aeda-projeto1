#ifndef _CALENDARIO_H_
#define _CALENDARIO_H_

#include <vector>
#include <string>

using std::vector; using std::string;
/** Classe que define os limites de um calendario e contem o nome dos meses.
 *
 */
class Calendario{
protected:

    static const string nomes[13]; //!< array com o nome dos meses.
    static const int daysOfMonth[13]; //!< array com o numero de dias maximos dos meses.
    static const int daysOfMonthL[13]; //!< array com onumero de dias maximos dos meses de um ano bissexto.

public:

    //Calendario();

};

#endif
