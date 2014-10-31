#include "modalidade.h"

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