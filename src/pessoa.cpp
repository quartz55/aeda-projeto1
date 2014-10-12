#include "pessoa.h"

Pessoa::Pessoa(string nome, unsigned int idade, unsigned long NIF){
    this->nome = nome;
    this->idade = idade;
    this->NIF = NIF;
}

void Pessoa::showInfo() const{
    cout << nome << ", " << idade << " anos\n";
    cout << "NIF: " << NIF;

    cout << endl;
}
