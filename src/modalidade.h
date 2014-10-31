#ifndef _MODALIDADE_H_
#define _MODALIDADE_H_

#include <vector>
#include <string>

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
    void changeNome(string nome){this->nome = nome;}

    protected:
        //...
};

#endif
