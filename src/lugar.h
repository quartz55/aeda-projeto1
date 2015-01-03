#ifndef _LUGAR_H_
#define _LUGAR_H_

#include "interface.h"

#include <string>
#include "data.h"
#include "pessoa.h"
#include "jogador.h"
#include "socio.h"

using std::string;

class Lugar{
protected:
	string tipo;
	int preco;
	Socio* socio;
	Data* last_payed;
public:
	Lugar(unsigned int dia, unsigned int mes, unsigned int ano, string tipo, Socio* socio);
	string getTipo(){ return this->tipo; }
	int getPreco(){ return this->preco; }
	Data* getLast_payed(){ return this->last_payed; }
	Socio* getSocio(){ return this->socio; }
	bool setTipo(string tipo);
	void setLast_payed(unsigned int dia, unsigned int mes, unsigned int ano);
	void setSocio(Socio* socio){ this->socio = socio; }
	bool operator==(Lugar* l);
	bool operator<(Lugar* l);
	string showInfo() const;
};

#endif