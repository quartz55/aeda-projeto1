#include "modalidade.h"
#include <sstream>

Modalidade::Modalidade(string nome){
    this->nome = nome;
}

bool Modalidade::operator< (const Modalidade& mod)
{
	if (strcmp(nome.c_str(), mod.nome.c_str()) < 0)
		return false;
	else
		return true;
}

bool Modalidade::changeNome(string nome)
{
	this->nome = nome; 
	return true; 
}

string Modalidade::showInfo() const
{
	std::stringstream s;
	s << nome << std::endl;
	return s.str();
}