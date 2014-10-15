#include "quota.h"

float Quota::preco = 3.0;
Quota::Quota(int m, int ano): last_payed(Data(8,m,ano)) { //preco de uma quota de uma modalidade
}

const Data*& Quota::getLastPayed() const {
	return last_payed;
}

void Quota::setLastPayed(const Data*& lastPayed) {
	last_payed = lastPayed;
}

float Quota::getPreco() const {
	return preco;
}

void Quota::setPreco(float preco) {
	this->preco = preco;
}

void Quota::pagarQuota(int meses) {
	last_payed->addMonths(meses);
}
