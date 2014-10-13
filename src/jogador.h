#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include <vector>

#include "pessoa.h"
#include "modalidade.h"
#include "submodalidade.h"

using std::vector;

class Jogador: public Pessoa{

    vector<Modalidade *> modalidades;
    vector<SubModalidade *> sub_modalidades;

    public:
    Jogador(string nome, unsigned int idade, unsigned long NIF);

    bool addModalidade(Modalidade *mod);
    void showInfo() const;
    void showModalidades() const;
    void showSubModalidades() const;
    bool addSubModalidade(SubModalidade *sub);

    protected:
    //...
};

#endif
