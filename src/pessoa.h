#ifndef _PESSOA_H
#define _PESSOA_H

#include "despesa.h"

#include <sstream>
#include <stdio.h>
#include <string>

using std::cout; using std::cin; using std::string; using std::endl;

class Pessoa{

    protected:

    string nome;
    string sexo;
    unsigned int idade;
    unsigned long NIF;
    string classe;
    Despesa *despesa;

    public:
    Pessoa(string nome, unsigned int idade, unsigned long NIF, string sexo);

	//OPERATOR'S
	bool operator< (const Pessoa& pessoa);

    //GET
    string getNome() const {return nome;}
    unsigned int getIdade() const {return idade;}
    unsigned long getNIF() const {return NIF;}
    string getSexo() const {return sexo;}
    string getClasse() const {return classe;}


    //CHANGE
    bool changeNome(string nome);
    bool changeIdade(unsigned int idade);
    bool changeNIF(unsigned long NIF);
    bool changeSexo(string sexo);
    void setExterno(){this->classe = "Externo";}

    virtual string showInfo() const;

};

#endif
