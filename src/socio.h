#ifndef _SOCIO_H_
#define _SOCIO_H_

#include <vector>

#include "pessoa.h"
#include "modalidade.h"

using std::vector;

class Socio: public Pessoa{

    vector<Modalidade *> modalidades;

    public:
    Socio(string nome, unsigned int idade, unsigned long NIF);

    void showInfo() const {Pessoa::showInfo();}

    protected:
    //...
};

#endif
