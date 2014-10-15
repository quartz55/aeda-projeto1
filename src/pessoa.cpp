#include "pessoa.h"

Pessoa::Pessoa(string nome, unsigned int idade, unsigned long NIF, string sexo){
    this->nome = nome;
    this->idade = idade;
    this->NIF = NIF;
    this->sexo = sexo;
    this->classe = "Pessoa";
}

void Pessoa::showInfo() const{
    cout << nome << ", " << idade << " anos\n";
    cout << "NIF: " << NIF << endl;;
    cout << classe << endl;
}
