#include "despesa.h"
#include "data.h"


Despesa::Despesa(int d, int m, int y, float valor, string info): data(new Data(d,m,y)){
    this->valor = valor;
    this->info = info;
}

const Data* Despesa::getData() const {
	return data;
}

bool Despesa::setData(Data* data) {
	this->data = data;
	return true;
}

const string& Despesa::getInfo() const {
	return info;
}

bool Despesa::setInfo(const string& info) {
	this->info = info;
	return true;
}

float Despesa::getValor() const {
	return valor;
}

bool Despesa::setValor(float valor) {
	this->valor = valor;
	return true;
}

bool Despesa::operator< (const Despesa& despesa) const
{
	return *data < *despesa.data;
}

string Despesa::showInfo() {
	stringstream ss;
	ss <<  "	" << data->showData() << " | " << info << " | " << valor;
	return ss.str();
}
