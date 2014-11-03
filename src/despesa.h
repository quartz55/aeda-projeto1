#ifndef _DESPESA_H_
#define _DESPESA_H_

#include "data.h"
#include <sstream>

using std::stringstream;

class Despesa{

public:
	Despesa(int d, int m, int y, float valor, string info);
	const Data* getData() const;
	bool setData(Data* data);
	const string& getInfo() const;
	bool setInfo(const string& info);
	float getValor() const;
	bool setValor(float valor);
	bool operator< (const Despesa& despesa) const;
	string showInfo();

protected:
	Data *data; // quando pagar
	float valor; //valor a pagar
	string info; // descricao da despesa
};

#endif
