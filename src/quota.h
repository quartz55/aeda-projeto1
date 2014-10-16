#ifndef _QUOTA_H_
#define _QUOTA_H_

#include "data.h"

class Quota{

public:
	Quota(int m, int ano);
	const Data*& getLastPayed() const;
	void setLastPayed(const Data*& lastPayed);
	float getPreco() const;
	void setPreco(float preco);
	void pagarQuota(int meses);

protected:
	Data * last_payed; // data da ultima quota paga
	static float preco;
};

#endif
