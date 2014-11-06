#ifndef _MODALIDADE_H_
#define _MODALIDADE_H_

#include <vector>
#include <string>
#include <cstring>

using std::vector; using std::string;

class Modalidade{

    string nome;
    unsigned int num_submods;

    public:
    Modalidade(string nome);

    //OPERATOR'S
    bool operator< (const Modalidade& mod);

    //GET
    string getNome(){return nome;}
    unsigned int getNumSubs(){return num_submods;}

    //CHANGE
	bool changeNome(string nome);
    void setNumSubs(unsigned int I){this->num_submods = I;}

	string showSubModalidades();
	string showInfo() const;

    protected:
    //...
};

#endif
