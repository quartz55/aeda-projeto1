/**
 * @file   data.h
 * @author Diogo Trindade
 * 
 * @brief Ficheiro responsável pela classe Data
 * 
 */

#ifndef _DATA_H
#define _DATA_H

#include "calendario.h"
#include <iostream>

using std::stringstream;
/**
 * Classe para representar uma data(dd/mm/yyyy)
 */

class Data : public Calendario{

    int day; //!< inteiro com o dia do mes do objecto.
    int month; //!< inteiro com o mes do ano do objecto.
    int year; //!< inteiro com ano do objecto.

    public:
    /**Construtor da classe.
     * @param day inteiro com o dia do objecto.
     * @param month inteiro com o mes do objecto.
     * @param year inteiro com o ano do objecto.
     */
    Data(int day, int month, int year);
    /**Retorna true se o ano do objecto for bissexto e falso caso contrario.
     *
     */
    bool leapYear() const;
    /**Adiciona dias a data. Tem em atencao ao limite dos dias de cada mes e ao limite de meses.
     * @param days inteiro com o numero de dias a adicionar ao objecto.
     */
    void addDays(int days);
    /**Avanca meses a data. Vai para o primeiro dia do mes dessa data e tem em atencao ao limite de meses.
     * @param months inteiro com o numero de meses a adicionar ao objecto.
     */
    void addMonths(int months);
    /**Adiciona anos a data.
     * @param years inteiro com o numero de anos a adicionar ao objecto.
     */
    void addYears(int years);
    /**Retorna uma string com a data. String contem o dia, o nome do mes e o ano.
     *
     */
    string showData() const;
    /**Altera a os membros da data. Altera o dia, mes e ano do objecto
     * @param day inteiro com o novo dia.
     * @param month inteiro com o novo mes.
     * @param year inteiro com o novo ano.
     */
    void setData(int day, int month, int year);
    /** Overload do operador <. Retorna true se a data anterior a data a comparar.
     *@param d1 refercia da data a pagar
     */
    bool operator< (const Data &d1) const;
    /** Retorna um inteiro com o dia do mes da data.
     *
     */
    int getDay() const;
    /** Retorna um inteiro com o mes do ano da data.
     *
     */
    int getMonth() const;
    /** Retorna um inteiro com o ano da data.
     *
     */
    int getYear() const;
};

#endif
