#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include <vector>

#include "pessoa.h"
#include "modalidade.h"

using std::vector;

class Jogador: public Pessoa{

    vector<Modalidade *> modalidades;

    public:
    Jogador(string nome, unsigned int idade, unsigned long NIF);

    void showInfo() const {Pessoa::showInfo();}

    protected:
    //...
};

#endif
