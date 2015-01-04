/**
 * @file   jogador.h
 * @author Joao Costa
 * 
 * @brief  Ficheiro responsável pela classe Jogador
 * 
 * 
 */

#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include <vector>

#include "pessoa.h"
#include "modalidade.h"
#include "submodalidade.h"

using std::vector;
/**Classe que representa um jogador.
 *
 */

class Jogador: public Pessoa{
	protected:
    vector<Modalidade *> modalidades;//!< vector de apontadores das modalidades associadas ao jogador.
    vector<SubModalidade *> sub_modalidades;//!< vector de apontadores das sub-modalidades associadas ao jogador.

    public:
    /**Construtor da classe. Cria um jogador.
     *@param nome string com o nome do jogador.
     *@param idade inteiro sem sinal com a idade do jogador.
     *@param NIF inteiro sem sinal com o NIF do jogador.
     *@param sexo string com o genero do jogador.
     */
    Jogador(string nome, unsigned int idade, unsigned long NIF, string sexo);

    /** Retorna um vector com apontadores para as modalidades que o jogador esta associado.
     *
     */
    vector <Modalidade *> getMods(){return modalidades;}
    /** Retorna um vector com apontadores para as sub-modalidades que o jogador esta associado.
     *
     */
    vector <SubModalidade *> getSubMods(){return sub_modalidades;}

    /**Metodo virtual que associa uma modalidade ao jogador. Retorna true em caso de sucesso e false caso contrario.
     *@param mod apontador para a modalidade a associar.
     */
    virtual bool addModalidade(Modalidade *mod);
    /**Associa uma sub-modalidade ao jogador. Retorna true em caso de sucesso e false caso contrario.
     *@param sub apontador para a sub-modalidade a associar.
     */
    bool addSubModalidade(SubModalidade *sub);

    /** Retorna uma string com os dados pessoais do jogador.
     *
     */
    string showInfo() const;
    /** Retorna uma string com as modalidades do jogador.
     *
     */
    string showModalidades() const;
    /** Retorna uma string com as sub-modalidades do jogador.
     *
     */
    string showSubModalidades() const;

    /** Remove uma modalidade do jogador. Retorna true em caso de sucesso e false caso contrario.
     *@param mod apontador para a modalidade a remover.
     */
	bool removeModalidade(Modalidade *mod);
    /** Remove uma sub-modalidade do jogador. Retorna true em caso de sucesso e false caso contrario.
     *@param mod apontador para a sub-modalidade a remover.
     */
	bool removeSubModalidade(SubModalidade *mod);

};

#endif
