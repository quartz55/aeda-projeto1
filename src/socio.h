/**
 * @file   socio.h
 * 
 * @brief Ficheiro responsável pela classe Socio
 * 
 */

#ifndef _SOCIO_H_
#define _SOCIO_H_

#include <vector>

#include "jogador.h"
#include "quota.h"
#include "data.h"

using std::vector;
/** Classe em que o objecto e um socio.
 *
 */

class Socio: public Jogador{

    vector <Quota *> quotas;//!< Vector de apontadores para cada quota do socio.

    public:
    /** Construtor da classe. Cria um socio.
     *@param nome string com o nome do socio.
     *@param idade inteiro sem sinal com a idado do socio.
     *@param NIF inteiro sem sinal com o NIF do socio.
     *@param sexo string com o genero do socio.
     */
    Socio(string nome, unsigned int idade, unsigned long NIF, string sexo);
    /** Associa uma modalidade ao socio.
     * Adiciona tambem a quota correspondente retornando true em caso de sucesso e false caso contrario.
     *@param mod apontador para a modalidade a associar
     *@param mes inteiro com o mes actual para criar a quota correspondente da modalidade.
     *@param ano inteiro com o ano actual para criar a quota correspondente da modalidade.
     */
    bool addModalidade(Modalidade *mod, int mes, int ano);
    /** Retorna um inteiro com numero de quotas atrasadas de uma modalidade.
     *@param dataActual data actual para poder calcular o numero de quotas atrasadas.
     *@param mod apontador para a modalidade com ou sem quotas atrasadas.
     */
    int QuotasAtrasadas(Data dataActual, Modalidade *mod);
    /** Retorna um float com o valor a pagar para liquidar certas quotas.
     *@param meses Numero de meses a pagar.
     *@param dataActual data actual para calcular as quotas atrasadas e respectiva multa.
     *@param pagar boleano para saber se apenas e para fazer um orcamento(false) ou se e para realmente pagar(true).
     *@param mod apontador para a modalidade da quota a pagar.
     */
    float pagarQuotas(int meses, Data dataActual, bool pagar, Modalidade *mod);
    /**Remove a quota de uma modalidade.
     *@param mod modalidade que vai ser retirada a quota.
     */
    bool removeQuota(Modalidade* mod);
    /** Retorna o vector com apontadores para as quotas de todas as modalidades.
     *
     */
    vector <Quota *> getQuotas() const {return quotas;};
    /**Retorna uma string com os dados pessoais, modalidades associadas e quotas.
     *
     */
    string showInfo() const;

    bool supportsMod(string modalidade);
};

#endif
