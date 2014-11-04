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

bool sortByNum(Modalidade *lhs, Modalidade *rhs) { return lhs->getNumSubs() > rhs->getNumSubs();}


//############
//##DESPESAS##
//############

bool sortByData(Despesa *lhs, Despesa *rhs) {
	Data d1(lhs->getData()->getDay(),lhs->getData()->getMonth(), lhs->getData()->getYear());
	Data d2(rhs->getData()->getDay(),rhs->getData()->getMonth(), rhs->getData()->getYear());
	return  d1 < d2;
}

bool sortByValor(Despesa *lhs, Despesa *rhs) { return lhs->getValor() > rhs->getValor();}

#endif
