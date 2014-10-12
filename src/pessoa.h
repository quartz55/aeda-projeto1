#ifndef _PESSOA_H
#define _PESSOA_H

#include <string>

class Pessoa{
    string nome;
    unsigned int idade;
    unsigned long NIF;

    public:
    Pessoa(string nome, unsigned int idade, unsigned long NIF);
    string getNome() const {return nome;}
    unsigned int getIdade() const {return idade;}
    unsigned long getNIF() const {return NIF;}

    protected:
    //...
}

#endif
