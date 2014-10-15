#ifndef _PESSOA_H
#define _PESSOA_H

#include "despesa.h"

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string; using std::endl;

class Pessoa{

    public:
    Pessoa(string nome, unsigned int idade, unsigned long NIF, string sexo);

    //GET
    string getNome() const {return nome;}
    unsigned int getIdade() const {return idade;}
    unsigned long getNIF() const {return NIF;}

    //CHANGE
    void changeNome(string nome){this->nome = nome;}
    void changeIdade(unsigned int idade){this->idade = idade;}
    void changeNIF(unsigned long NIF){this->NIF = NIF;}
    void setExterno(){this->classe = "Externo";}

    virtual void showInfo() const;

    protected:

    string nome;
    string sexo;
    unsigned int idade;
    unsigned long NIF;
    string classe;
    Despesa *despesa;

};

#endif
