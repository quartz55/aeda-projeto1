#include "lugar.h"
#include <cstring>

Lugar::Lugar(unsigned int dia,unsigned int mes,unsigned int ano, string tipo, Socio* socio){
	this->socio = socio;
	this->last_payed = new Data(dia, mes, ano);
	if (tipo == "Camarote" || tipo == "camarote"){
		this->tipo = "Camarote";
		this->preco = 500;
	}
	if (tipo == "Cativo" || tipo == "cativo"){
		this->tipo = "Cativo";
		this->preco = 100;
	}
	if (tipo == "Anual" || tipo == "anual"){
		this->tipo = "Anual";
		this->preco = 60;
	}
}

bool Lugar::setTipo(string tipo){
	if (tipo == "Camarote" || tipo == "camarote"){
		this->tipo = "Camarote";
		this->preco = 500;
		return true;
	}
	if (tipo == "Cativo" || tipo == "cativo"){
		this->tipo = "Cativo";
		this->preco = 100;
		return true;
	}
	if (tipo == "Anual" || tipo == "anual"){
		this->tipo = "Anual";
		this->preco = 60;
		return true;
	}
	return false;
}

bool Lugar::operator==(Lugar* l){
	if (socio->getNIF() == l->getSocio()->getNIF())
		return true;
	else
		return false;
}

bool Lugar::operator<(Lugar* l){
	if (socio->getNome() < l->getSocio()->getNome())
		return true;
	else
		return false;
}

string Lugar::showInfo() const{
	std::stringstream ss;
	ss << socio->Pessoa::showInfo();
	ss << "Ultimo pagamento: " << last_payed->showData() << endl;
	ss << "Preco: " << preco << endl;
	ss << "Tipo: " << tipo << endl;
	ss << "--------------------------------------------\n";
	return ss.str();
}

void Lugar::setLast_payed(unsigned int dia, unsigned int mes, unsigned int ano){
	last_payed->setData(dia, ano, mes);
}