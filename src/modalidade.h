#ifndef _MODALIDADE_H_
#define _MODALIDADE_H_

#include <vector>
#include <string>
#include <cstring>

using std::vector; using std::string;

class Modalidade{

    string nome;


    public:
    Modalidade(string nome);

    //OPERATOR'S
    bool operator< (const Modalidade& mod);

    //GET
    string getNome(){return nome;}

    //CHANGE
	bool changeNome(string nome);

	string showInfo() const;

    protected:
    //...
};

#endif
