#ifndef _DESPESA_H_
#define _DESPESA_H_

#include "data.h"

class Despesa{

    public:
        Despesa(int d, int m, int y, float valor, string info);


    protected:
    
    Data data;
    float valor; //valor a pagar
    string info; // descricao da despesa
};

#endif
