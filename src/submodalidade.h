#ifndef _SUBMODALIDADE_H_
#define _SUBMODALIDADE_H_

#include "modalidade.h"

class SubModalidade: public Modalidade{

    Modalidade *mod;

    public:
    SubModalidade(string nome, Modalidade *mod);

    Modalidade* getMod() const {return mod;}
    protected:
    //...
};

#endif
