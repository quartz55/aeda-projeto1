#include "quota.h"

float Quota::preco = 3.0;
Quota::Quota(int m, int ano, Modalidade * mod): last_payed(new Data(8,m,ano)) { //preco de uma quota de uma modalidade
	modalidade =mod;
}

const Data* Quota::getLastPayed() const {
	return last_payed;
}

void Quota::setLastPayed(Data* lastPayed) {
	last_payed = lastPayed;
}

float Quota::getPreco() const{
	return preco;
}

void Quota::setPreco(float preco) {
	this->preco = preco;
}

void Quota::pagarQuota(int meses) {
	last_payed->addMonths(meses);
	last_payed->setData(8, last_payed->getMonth(), last_payed->getYear());
}

bool Quota::operator< (const Quota& quota)
{
	return (last_payed < quota.last_payed);
}

const Modalidade* Quota::getModalidade() const {
	return modalidade;
}

string Quota::showQuota() const {
	std::stringstream ss;
	ss << last_payed->showData() << " | " << preco << modalidade->getNome();
	return ss.str();
}
