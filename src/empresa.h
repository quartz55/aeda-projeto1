// -*-c++-*-

/**
 * @file   empresa.h
 * @author Joao Costa
 * 
 * @brief Ficheiro responsável pela classe Empresa e suas classes associadas
 * 
 */

#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <vector>
#include <sstream>

#include "interface.h"

using std::string; using std::vector;

/**
 * @defgroup empresa Empresa
 * @{
 */

/**
 * @defgroup servico Servico
 * @{
 */

/**
 * Classe responsavel por criar um servico e mostrar a informacao deste
 */
class Servico{
public:
  string titulo;                /**< Titulo do servico */
  string descricao;             /**< Descricao do servico */

  /** 
   * Guarda o titulo e a descricao do servico numa string para
   * mostrar no ecra.
   * 
   * @return String com o titulo e descricao
   */
  string showInfo(){
    std::ostringstream ss;
    ss << titulo << std::endl;
    ss << "Descricao: " << descricao << std::endl;
    return ss.str();
  }
};

/**
 * Classe responsavel por criar a classe ServiceNotFound usada em excecoes
 */
class ServiceNotFound{
  Servico s;                    /**< Servico nao encontrado */
public:
  /** 
   * Construtor da classe. Recebe o servico que nao foi encontrado
   * 
   * @param s Servico que nao foi encontrado
   */
  ServiceNotFound(Servico s){this->s = s;}

  /** 
   * Guarda o titulo e a descricao do servico nao encontrado numa string
   * para mostrar no ecra.
   * 
   * @return String com o titulo e descricao
   */
  string showInfo(){
    std::ostringstream ss;
    ss << s.titulo << std::endl << s.descricao;
    return ss.str();
  }
};
/**
 * @} end of servico */

/**
 * @defgroup empresaClass Classe Empresa
 * @{
 */

/**
 * Classe responsavel pela criacao de uma Empresa
 */
class Empresa{
  string nome;                  /**< Nome da empresa */
  unsigned long NIF;            /**< NIF da empresa */
  unsigned int localizacao;     /**< Localizacao (em km) da empresa */
  vector<Servico*> servicos;    /**< Servicos associados a empresa */
  bool contrato;                /**< TRUE se tiver um contrato com o clube */

public:
  /** 
   * Construtor da classe Empresa
   * 
   * @param nome Nome da empresa
   * @param NIF NIF da empresa
   * @param localizacao Localizacao da empresa
   */ 
  Empresa(string nome, unsigned long NIF, unsigned int localizacao){
    this->nome = nome; this->NIF = NIF; this->localizacao = localizacao;
    this->contrato = false;
  }
  /** 
   * Guarda a informacao basica e os servicos da empresa numa string
   * para mostrar no ecra.
   * 
   * 
   * @return String com a informacao da empresa
   */
  string showInfo();
  /** 
   * Guarda a informacao basica (Nome, NIF, Localizacao e Contrato) numa string
   * para mostrar no ecra.
   * 
   * 
   * @return String com a informacao basica da empresa
   */
  string showBasicInfo();
  /** 
   * Guarda os servicos da empresa numa string para mostrar no ecra
   * 
   * 
   * @return String com os servicos da empresa
   */
  string showServicos();

  // Gets
  string getNome() const {return nome;} /**< Retorna o nome da Empresa */
  unsigned long getNIF() const {return NIF;} /**< Retorna o NIF da Empresa */
  unsigned int getLocalizacao() const {return localizacao;} /**< Retorna a localizacao da Empresa */
  vector<Servico*> getServicos() const {return servicos;} /**< Retorna os servicos da Empresa */
  bool getContrato() const {return contrato;} /**< Retorna o estado do contrato da Empresa */

  // Changes
  void changeNome(string novo_nome){nome = novo_nome;} /**< Muda o nome da empresa */
  void changeNIF(unsigned long novo_NIF){NIF = novo_NIF;} /**< Muda o NIF da empresa */
  void changeLocalizacao(unsigned int nova_localizacao){localizacao = nova_localizacao;} /**< Muda a localizacao da empresa */
  void changeServicos(vector<Servico*> novos_servicos){servicos = novos_servicos;} /**< Muda o vetor servicos da empresa */
  void changeContrato(bool novo_contrato){contrato = novo_contrato;} /**< Muda o estado do contrato da empresa */

  // Add
  void addServico(Servico* novo_servico){servicos.push_back(novo_servico);} /**< Adiciona um servico ao vetor servicos da empresa */

  // Remove
  /** 
   * Remove um servico do vetor servicos da empresa
   * @note Lanca a excecao 'ServiceNotFound' se o servico nao for encontrado na empresa
   * 
   * @param s Servico a remover da empresa
   */
  void removeServico(Servico* s);
  /** 
   * Procura no vetor servicos da empresa pelo Servico dado
   * 
   * @param s Servico a procurar
   * 
   * @return TRUE se encontrar, FALSE se nao
   */
  bool hasService(Servico* s);
  /** 
   * Procura no vetor servicos da empresa pelo titulo do Servico dado
   * 
   * @param titulo Titulo do servico a procurar
   * 
   * @return TRUE se encontrar, FALSE se nao
   */
  bool hasService(string titulo);
};

inline void Empresa::removeServico(Servico* s){
  for(unsigned int i = 0; i < servicos.size(); i++){
    if(s == servicos[i]){
      servicos.erase(servicos.begin()+i); 
      return;
    }
  }
  throw(ServiceNotFound(*s)); // Throw exception if not found
}

/**
 * Classe necessaria para a fila de prioridade usada no ficheiro 'clube.h'
 */
class CompareEmpresas {
public:
  /** 
   * Operador necessario para a ordenacao da fila de prioridade
   * @note Ordena as empresas pela distancia a que se encontram do clube.
   * @note As empresas que se encontram mais proximas do clube ficarao mais proximas do topo da fila.
   * @note Se duas empresas estiverem a mesma distancia do clube, a empresa com maior numero de servicos disponivel tem prioridade.
   * 
   * 
   * @return TRUE se prioridade de e1 > e2, FALSE se prioridade e1 < e2
   */
  bool operator()(Empresa* e1, Empresa* e2){
    if(e1->getLocalizacao() != e2->getLocalizacao())
      return e1->getLocalizacao() > e2->getLocalizacao();
    else return e1->getServicos().size() < e2->getServicos().size();
  } 
};

/**
 * @} end of classEmpresa */

/**
 * @} end of empresa */

#endif
