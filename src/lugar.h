#ifndef _LUGAR_H_
#define _LUGAR_H_

#include "interface.h"

#include <string>
#include "data.h"
#include "pessoa.h"
#include "jogador.h"
#include "socio.h"

using std::string;
/**
* Classe responsavel por criar uma reserva de lugar anual e mostrar a informacao desta
*/
class Lugar{
protected:
	string tipo; /**< Tipo de lugar (anual/camarote/cativo) */
	int preco; /**< Preco do lugar, dependendo do tipo */
	Socio* socio; /**< Socio proprietario do lugar anual */
	Data* last_payed; /**< Data do ultimo pagamento */
public:
	/**
	* Construtor da classe. Recebe a data, o tipo e o socio
	*
	* @param dia dia do ultimo pagamento
	* @param mes mes do ultimo pagamento
	* @param ano ano do ultimo pagamento
	* @param tipo tipo de lugar anual
	* @param socio socio proprietário do lugar 
	*/
	Lugar(unsigned int dia, unsigned int mes, unsigned int ano, string tipo, Socio* socio);
	/**Retorna tipo de lugar anual.
	*
	* @return string com o tipo
	*/
	string getTipo(){ return this->tipo; }
	/**Retorna preco de lugar anual.
	*
	* @return int com o preco
	*/
	int getPreco(){ return this->preco; }
	/**Retorna data do ultimo pagamento do lugar anual.
	*
	* @return Data do ultimo pagamento
	*/
	Data* getLast_payed(){ return this->last_payed; }
	/**Retorna o socio proprietario do lugar anual.
	*
	* @return Socio propietario
	*/
	Socio* getSocio(){ return this->socio; }
	/**Altera o tipo de lugar.
	*
	* @param tipo novo tipo de lugar anual
	* @return verifica se tipo introduzido e valido
	*/
	bool setTipo(string tipo);
	/**Altera a data do ultimo pagamento.
	*
	* @param dia novo dia realtivo ao ultimo pagamento
	* @param mes novo mes relativo ao ultimo pagamento 
	* @param ano novo ano relativo ao ultimo pagamanto
	*/
	void setLast_payed(unsigned int dia, unsigned int mes, unsigned int ano);
	/**Altera o socio proprietario do lugar.
	*
	* @param socio novo socio proprietario do lugar
	*/
	void setSocio(Socio* socio){ this->socio = socio; }
	/**Verifica a existência do lugar.
	*
	* @param l lugar para efectuar comparacao 
	* @return verifica a já existencia do lugar
	*/
	bool operator==(Lugar l)const;
	/**Compara o lugar, tendo em conta a ordem alfabetica do socio proprietario.
	*
	* @param l lugar para efectuar comparacao
	* @return verifica ordem alfabetica
	*/
	bool operator<(Lugar l) const;
	/**Retorna uma string com a informacao do lugar.
	*
	* @return informacao lugar
	*/
	string showInfo() const;
};

#endif
