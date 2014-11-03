#ifndef _QUOTA_H_
#define _QUOTA_H_

#include "data.h"
#include "modalidade.h"
#include <sstream>

class Quota{

public:
	Quota(int m, int ano, Modalidade* mod);
	const Data* getLastPayed() const;
	void setLastPayed(Data* lastPayed);
	const Modalidade * getModalidade() const;
	float getPreco() const;
	void setPreco(float preco);
	void pagarQuota(int meses);
	bool operator< (const Quota& quota);
	string showQuota() const;

protected:
	Modalidade * modalidade;
	Data * last_payed; // data da ultima quota paga
	static float preco;
};

#endif
