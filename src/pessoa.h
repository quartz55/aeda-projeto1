#ifndef _PESSOA_H
#define _PESSOA_H

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string; using std::endl;

class Pessoa{
    std::string nome;
    unsigned int idade;
    unsigned long NIF;

    public:
    Pessoa(string nome, unsigned int idade, unsigned long NIF);
    string getNome() const {return nome;}
    unsigned int getIdade() const {return idade;}
    unsigned long getNIF() const {return NIF;}

    virtual void showInfo() const;

    protected:
    //...
};

#endif
