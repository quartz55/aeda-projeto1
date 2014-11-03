#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include <vector>

#include "pessoa.h"
#include "modalidade.h"
#include "submodalidade.h"

using std::vector;

class Jogador: public Pessoa{
	protected:
    vector<Modalidade *> modalidades;
    vector<SubModalidade *> sub_modalidades;

    public:
    Jogador(string nome, unsigned int idade, unsigned long NIF, string sexo);

    vector <Modalidade *> getMods(){return modalidades;}
    vector <SubModalidade *> getSubMods(){return sub_modalidades;}

    virtual bool addModalidade(Modalidade *mod);
    bool addSubModalidade(SubModalidade *sub);

    string showInfo() const;
    string showModalidades() const;
    string showSubModalidades() const;

};

#endif
