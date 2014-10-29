#include "pessoa.h"

Pessoa::Pessoa(string nome, unsigned int idade, unsigned long NIF, string sexo){
    this->nome = nome;
    this->idade = idade;
    this->NIF = NIF;
    this->sexo = sexo;
    this->classe = "Pessoa";
}

bool Pessoa::changeNome(string nome){
    this->nome = nome;
    return true;
}
bool Pessoa::changeIdade(unsigned int idade){
    this->idade = idade;
    return true;
}
bool Pessoa::changeNIF(unsigned long NIF){
    this->NIF = NIF;
    return true;
}
bool Pessoa::changeSexo(string sexo){
    this->sexo = sexo;
    return true;
}

string Pessoa::showInfo() const{
    std::stringstream s;
    s << sexo << ", " << nome << ", " << idade << " anos\nNIF: " << NIF << std::endl;
    return s.str();
}
