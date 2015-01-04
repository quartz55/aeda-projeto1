/**
 * @file   interface.h
 * @author Joao Costa
 * 
 * @brief  Ficheiro responsável pela classe Interface
 * 
 * 
 */

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <iostream>
#include <string>
#include <sstream>

#ifdef _WIN32
#include <stdlib.h>
#endif
/**Classe com funcoes de interface com o terminal.
 *
 */
class Interface{
    public:
	/**Construtor da interface.
	 *
	 */
    Interface();
	/**Destrutor da interface.
	 *
	 */
    ~Interface();

    /**Espera que o utilizador pressione uma tecla.
     *
     */
    void getInput();
    /**Le um char dado pelo utilizador na linha de comandos.
     *
     */
    template<typename Type>
    void readChar(Type &var);
    /**Le uma linha dado pelo utilizador na linha de comandos.
     *@param STRING referencia da string que vai guardar a linha introduzida pelo utilizador.
     */
    void readLine(std::string &STRING);
    /**Le da linha de comandos o input do utilizador
     *
     */
    template<typename Type>
    void read(Type &var);
    /**Imprime um char na linha de commandos
     *
     */
    void drawChar(char CHAR);
    /**Imprime no ecra todas as variaveis (int,string,float,etc...)
     *
     */
    template<typename Type>
    void drawString(Type STRING);
    /**Muda para a linha seguinte da linha de comandos
     *
     */
    void newLine();
    /** Limpa a linha de comandos
     *
     */
    void cleanScr();
};

template<typename Type>
void Interface::readChar(Type &var){
    std::cin >> var;
    std::cin.ignore(1000, '\n');
    if (std::cin.fail())
        std::cin.clear();
}

template<typename Type>
void Interface::read(Type &var){
    std::cin >> var;
    std::cin.ignore(1000, '\n');
	if (std::cin.fail())
		std::cin.clear();
}

template<typename Type>
void Interface::drawString(Type STRING){
    std::cout << STRING;
}

#endif
