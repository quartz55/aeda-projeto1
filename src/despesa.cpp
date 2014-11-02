#include "despesa.h"
#include "data.h"


Despesa::Despesa(int d, int m, int y, float valor, string info): data(new Data(d,m,y)){
    this->valor = valor;
    this->info = info;
}

const Data* Despesa::getData() const {
	return data;
}

void Despesa::setData(Data* data) {
	this->data = data;
}

const string& Despesa::getInfo() const {
	return info;
}

void Despesa::setInfo(const string& info) {
	this->info = info;
}

float Despesa::getValor() const {
	return valor;
}

void Despesa::setValor(float valor) {
	this->valor = valor;
}

bool Despesa::operator< (const Despesa& despesa) const
{
	return data < despesa.data;
}

string Despesa::showInfo() {
	stringstream ss;
	ss <<  "» " << data->showData() << " | " << info << " | " << valor;
	return ss.str();
}
