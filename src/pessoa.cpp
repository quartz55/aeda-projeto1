#include "pessoa.h"

Pessoa::Pessoa(string nome, unsigned int idade, unsigned long NIF, string sexo){
    this->nome = nome;
    this->idade = idade;
    this->NIF = NIF;
    this->sexo = sexo;
    this->classe = "Pessoa";
}


bool Pessoa::operator< (const Pessoa& pessoa)
{
	if (strcmp(nome.c_str(), pessoa.nome.c_str()) < 0)
		return false;
	else
		return true;
}

bool Pessoa::changeNome(string nome){
	if (nome != "")
	{
		this->nome = nome;
		return true;
	}
		return false;
}
bool Pessoa::changeIdade(unsigned int idade){
	if (idade < 120)
	{
		this->idade = idade;
		return true;
	}
	return false;
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
