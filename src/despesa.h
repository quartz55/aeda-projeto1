#ifndef _DESPESA_H_
#define _DESPESA_H_

#include "data.h"

class Despesa{

public:
	Despesa(int d, int m, int y, float valor, string info);
	const Data* getData() const;
	void setData(Data* data);
	const string& getInfo() const;
	void setInfo(const string& info);
	float getValor() const;
	void setValor(float valor);

protected:
	Data *data; // quando pagar
	float valor; //valor a pagar
	string info; // descricao da despesa
};

#endif
