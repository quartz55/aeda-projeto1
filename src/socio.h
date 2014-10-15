#ifndef _SOCIO_H_
#define _SOCIO_H_

#include <vector>

#include "jogador.h"
#include "quota.h"

using std::vector;

class Socio: public Jogador{

    vector <Quota *> quotas;

    public:
    Socio(string nome, unsigned int idade, unsigned long NIF, string sexo);

    void showInfo() const {Jogador::showInfo();}
};

#endif
