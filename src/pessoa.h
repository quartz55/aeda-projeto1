/**
 * @file   pessoa.h
 * @author Joao Costa
 * 
 * @brief  Ficheiro responsável pela classe Pessoa
 * 
 * 
 */

#ifndef _PESSOA_H
#define _PESSOA_H

#include "despesa.h"

#include <sstream>
#include <string>
#include <cstring>

using std::cout; using std::cin; using std::string; using std::endl;
/**Classe que representa uma pessoa.
 *
 */

class Pessoa{

    protected:

    string nome;//!< string com o nome da pessoa
    string sexo;//!< string com o genero da pessoa
    unsigned int idade;//!< inteiro sem sinal com a idade
    unsigned long NIF;//!< inteiro sem sinal com o Numero de Identificacao Fiscal
    string classe;//!< Tipo de pessoa: jogador,socio ou externo

    public:
    /**Construtor da classe pessoa.
     *@param nome string com o nome da pessoa
     *@param idade inteiro sem sinal com a idade da pessoa
     *@param NIF inteiro sem sinal com o NIF da pessoa
     *@param sexo string com o genero da pessoa
     */
    Pessoa(string nome, unsigned int idade, unsigned long NIF, string sexo);

	//OPERATOR'S
    /**Overload do operador <. Retorna true se o nome for alfabeticamente menor que o nome da pessoa a comparar e falso caso contrario.
     *@param pessoa objecto a comparar.
     */
	bool operator< (const Pessoa& pessoa);

    //GET
	/**Retorna o nome da pessoa.
	 *
	 */
    string getNome() const {return nome;}
	/**Retorna a idade da pessoa.
	 *
	 */
    unsigned int getIdade() const {return idade;}
	/**Retorna o NIF da pessoa.
	 *
	 */
    unsigned long getNIF() const {return NIF;}
	/**Retorna o genero da pessoa.
	 *
	 */
    string getSexo() const {return sexo;}
	/**Retorna a classe da pessoa.
	 *
	 */
    string getClasse() const {return classe;}


    //CHANGE
	/**Altera o nome da pessoa. Retorna true em caso de sucesso e false caso contrario.
	 * @param nome string com o novo nome da pessoa.
	 */
    bool changeNome(string nome);
	/**Altera a idade da pessoa. Retorna true em caso de sucesso e false caso contrario.
	 *@param idade inteiro sem sinal com a nova idade.
	 */
    bool changeIdade(unsigned int idade);
	/**Altera o NIF da pessoa. Retorna true em caso de sucesso e false caso contrario.
	 *@param NIF inteiro sem sinal com o novo NIF.
	 */
    bool changeNIF(unsigned long NIF);
	/**Altera o genero da pessoa. Retorna true em caso de sucesso e false caso contrario.
	 *@param sexo string com o novo genero da pessoa.
	 */
    bool changeSexo(string sexo);
    /**Altera a classe da pessoa para externo.
	 *
	 */
    void setExterno(){this->classe = "Externo";}

    /**Metodo virtual (tem classes derivadas, funcao correcta chamada e grantida).
     * Retorna uma string com as informacoes pessoais (nome,nif...) da pessoa.
     */
    virtual string showInfo() const;

};

#endif
