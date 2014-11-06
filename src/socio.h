#ifndef _SOCIO_H_
#define _SOCIO_H_

#include <vector>

#include "jogador.h"
#include "quota.h"
#include "data.h"

using std::vector;

class Socio: public Jogador{

    vector <Quota *> quotas;

    public:
    Socio(string nome, unsigned int idade, unsigned long NIF, string sexo);
    bool addModalidade(Modalidade *mod, int mes, int ano);
    int QuotasAtrasadas(Data dataActual);
    float pagarQuotas(int meses, Data dataActual);
    bool removeQuota(Modalidade* mod);

    string showInfo() const;
};

#endif
