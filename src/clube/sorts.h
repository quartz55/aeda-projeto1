#ifndef SORTS_H
#define SORTS_H

//###########
//##PESSOAS##
//###########

bool sortByName(Pessoa *lhs, Pessoa *rhs) { return lhs->getNome() < rhs->getNome();}

bool sortByIdade(Pessoa *lhs, Pessoa *rhs) { return lhs->getIdade() < rhs->getIdade();}

bool sortBySexo(Pessoa *lhs, Pessoa *rhs) { return lhs->getSexo() > rhs->getSexo();}

//###############
//##MODALIDADES##
//###############

bool sortByNome(Modalidade *lhs, Modalidade *rhs) { return lhs->getNome() < rhs->getNome();}

//bool sortByIdade(const Modalidade *lhs, const Modalidade *rhs) { return lhs->getIdade() < rhs->getIdade();}

#endif
