/**
 * @file  quota.h
 * @author Diogo Trindade
 * 
 * @brief Ficheiro responsável pela classe Quota
 * 
 */

#ifndef _QUOTA_H_
#define _QUOTA_H_

#include "data.h"
#include "modalidade.h"
#include <sstream>

/** Classe que represanta uma quota de um modalidade de um determinado socio.
 *
 */

class Quota{

public:
	/**Construtor da classe. Cria um objecto que e uma quota (Todas as quotas esta associados ao dia 8 de cada mes);
	 *@param m inteiro com o mes actual (aquando da criacao da quota).
	 *@param ano inteiro com o ano actual (aquando da criacao da quota).
	 *@param mod apontador para a modalidade da quota.
	 *@param valor apontador para o custo da quota.
	 */
	Quota(int m, int ano, Modalidade* mod, float *valor);
	/** Retorna um apontador para a data da ultima quota paga.
	 *
	 */
	const Data* getLastPayed() const;
	/** Altera a data da ultima quota paga.
	 *@param lastPayed apontador para a nova data.
	 */
	void setLastPayed(Data* lastPayed);
	/** Retorna um apontador para a modalidade que o objecto se refere.
	 *
	 */
	Modalidade * getModalidade() const;
	/** Retorna o custo da quota (membro preco).
	 *
	 */
	float getPreco() const;
	/** Altera o preco da quota.
	 * @param preco float com o novo preco da quota
	 */
	void setPreco(float preco);
	/** Avanca a data o numero de meses que a quota foi paga.
	 *@param meses inteiro com o numero de quotas mensais que foram pagas.
	 */
	void pagarQuota(int meses);
	/** Overload do operador <. Retorna true se a data da ultima quota paga for menor que a da quota a comparar.
	 *@param quota referencia constante da quota a comparar.
	 */
	bool operator< (const Quota& quota) const;
	/**Retorna uma string com as informacoes da quota. Contem a modalidade, o seu preco e a data do ultimo pagamento.
	 *
	 */
	string showQuota() const;

protected:
	Modalidade * modalidade; //!< Apontador para a modalidade a qual a quota se refere
	Data * last_payed; //!< Apontador para a data da ultima quota paga
	float* preco; //!< Apontador para o preco de quota da modalidade a ele associado
};

#endif
