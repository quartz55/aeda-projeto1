#ifndef _DESPESA_H_
#define _DESPESA_H_

#include "data.h"
#include <sstream>

using std::stringstream;

/**
 * Classe para representar uma despesa de um clube desportivo.
 */

class Despesa{

public:
	/** Construtor de uma despesa. Cria um despesa com data, valor, e descricao.
	 *
	 * @param d inteiro [0-31] para definir o dia da despesa
	 * @param m inteiro [0-12] para definir o mes da despesa
	 * @param y inteiro [0-31] para definir o ano da despesa
	 * @param valor float para definir o custo da despesa
	 * @param info string para descrever a despesa
	 */
	Despesa(int d, int m, int y, float valor, string info);
	/** Retorna a data da despesa.
	 *
	 */
	const Data* getData() const;
	/** Altera a data do objecto.Retorna true caso a alteracao seja efectuada com sucesso e falso caso contrario.
	 * @param data apontador para uma data(ver classe data).
	 */
	bool setData(Data* data);
	/** Retorna a descricao do objecto.
	 *
	 */
	const string& getInfo() const;
	/** Altera a descricao do objecto. Retorna true caso a alteracao seja efectuada com sucesso e falso caso contrario.
	 * @param info referencia para uma string com a nova descricao do objecto.
	 */
	bool setInfo(const string& info);
	/** Retorna o custo do objecto.
	 *
	 */
	float getValor() const;
	/** Altera o custo do objecto. Retorna true caso a alteracao seja efectuada com sucesso e falso caso contrario.
	 * @param valor float com o novo valor.
	 */
	bool setValor(float valor);
	/** Overload do operador <. Retorna true caso a data de um obejcto seja menor(ver classe data).
	 * @param despesa referencia da despesa a comparar.
	 */
	bool operator< (const Despesa& despesa) const;
	/** Retorna uma string com as informacoes da despesa(data,valor e info).
	 *
	 */
	string showInfo();

protected:
	Data *data; //!< Data do pagamento de uma despesa(ver classe data)
	float valor; //!< Valor a pagar da despesa
	string info; //!< Pequena descricao da despesa
};

#endif
