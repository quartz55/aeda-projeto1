/**
 * @file   submodalidade.h
 * @author Joao Costa, Rui Vilares
 * 
 * @brief  Ficheiro responsável pela classe SubModalidade
 * 
 * 
 */

#ifndef _SUBMODALIDADE_H_
#define _SUBMODALIDADE_H_

#include "modalidade.h"
/** Classe em que o objecto e uma sub-modalidade.
 *
 */
class SubModalidade: public Modalidade{

    Modalidade *mod; //!< Apontador para a modalidade associada.

    public:
    /**Construtor da classe. Cria uma sub-modalidade
     *@param nome string com o nome da sub-modalidade.
     *@param mod apontador para a modalidade da qual o objecto e sub-modalidade.
     */
    SubModalidade(string nome, Modalidade *mod);
    /**Retorn um apontador para a modalidade a qual o objecto esta associado.
     *
     */
    Modalidade* getMod() const {return mod;}
    protected:
    //...
};

#endif
