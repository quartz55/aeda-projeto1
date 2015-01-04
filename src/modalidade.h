/**
 * @file   modalidade.h
 * @author Joao Costa, Rui Vilares
 * 
 * @brief  Ficheiro responsável pela classe Modalidade
 * 
 * 
 */

#ifndef _MODALIDADE_H_
#define _MODALIDADE_H_

#include <vector>
#include <string>
#include <cstring>

using std::vector; using std::string;
/** Classe que representa uma modalidade. Cada objecto e uma modalidade
 *
 */

class Modalidade{

    string nome;
    unsigned int num_submods;
    float precoQuota;

    public:
    /**Construtor da classe. Cria uma modalidade.
     * @param nome string que contem o nome da modalidade.
     */
    Modalidade(string nome);

    //OPERATOR'S
    /**Overload de operador <. Retorna true se alfabeticamente o nome da modalidade for menor que o da modalidade a comparar.
     *@param mod referencia constante para a modalidade a comparar.
     */
    bool operator< (const Modalidade& mod);

    //GET
    /**Retorna o nome da modalidade.
     *
     */
    string getNome(){return nome;}
    /**Retorna o numero (inteiro sem sinal) de sub-modalidades da modalidade.
     *
     */
    unsigned int getNumSubs(){return num_submods;}
    /**Retorna um apontador (de float) para o preço da modalidade.
     *
     */
    float * getPrecoQuota(){float *pt;pt = &precoQuota; return pt;}
    /**Altera o preco da quota da modalidade. Retorna true se em caso de sucesso e false caso contrario.
     *@param novoPreco float com o novo preco da modalidade.
     */
    bool setPrecoQuota(float novoPreco) {this->precoQuota = novoPreco; return true;}
    //CHANGE
    /**Altera o nome da modalidade. Retorna true se em caso de sucesso e false caso contrario.
     *@param nome string com o novo nome da modalidade.
     */
	bool changeNome(string nome);
    /**Altera o numero de submodalides do objecto. Retorna true se em caso de sucesso e false caso contrario.
     *@param I inteiro sem sinal com o novo numero de sub-modalidades.
     */
    void setNumSubs(unsigned int I){this->num_submods = I;}

    /**Retorn uma string com o nome da modalidade.
     *
     */
	string showInfo() const;

    protected:
    //...
};

#endif
