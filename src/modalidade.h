#ifndef _MODALIDADE_H_
#define _MODALIDADE_H_

#include <vector>
#include <string>
#include <cstring>

using std::vector; using std::string;

class Modalidade{

    string nome;
    unsigned int num_submods;
    float precoQuota;

    public:
    Modalidade(string nome);

    //OPERATOR'S
    bool operator< (const Modalidade& mod);

    //GET
    string getNome(){return nome;}
    unsigned int getNumSubs(){return num_submods;}
    float * getPrecoQuota(){float *pt;pt = &precoQuota; return pt;}
    bool setPrecoQuota(float novoPreco) {this->precoQuota = novoPreco; return true;}
    //CHANGE
	bool changeNome(string nome);
    void setNumSubs(unsigned int I){this->num_submods = I;}

	string showSubModalidades();
	string showInfo() const;

    protected:
    //...
};

#endif
