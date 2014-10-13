#ifndef _MODALIDADE_H_
#define _MODALIDADE_H_

#include <vector>
#include <string>

using std::vector; using std::string;

class Modalidade{

    string nome;


    public:
        Modalidade(string nome);

    //GET
    string getNome(){return nome;}

    protected:
        //...
};

#endif
