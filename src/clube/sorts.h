#ifndef SORTS_H
#define SORTS_H


bool sortByName(const Pessoa *lhs, const Pessoa *rhs) { return lhs->getNome() < rhs->getNome();}

bool sortByIdade(const Pessoa *lhs, const Pessoa *rhs) { return lhs->getIdade() < rhs->getIdade();}

bool sortBySexo(const Pessoa *lhs, const Pessoa *rhs) { return lhs->getSexo() > rhs->getSexo();}

#endif
