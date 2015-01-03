// -*-c++-*-
#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <vector>
#include <sstream>

#include "interface.h"

using std::string; using std::vector;

class Servico{
public:
  string titulo;
  string descricao;
  string showInfo(){
    std::ostringstream ss;
    ss << titulo << std::endl;
    ss << "Descricao: " << descricao << std::endl;
    return ss.str();
  }
};

class ServiceNotFound{
  Servico s;
public:
  ServiceNotFound(Servico s){this->s = s;}
  string showInfo(){
    std::ostringstream ss;
    ss << s.titulo << std::endl << s.descricao;
    return ss.str();
  }
};

class Empresa{
  string nome;
  unsigned long NIF;
  unsigned int localizacao;
  vector<Servico*> servicos;
  bool contrato;

public:
  Empresa(string nome, unsigned long NIF, unsigned int localizacao){
    this->nome = nome; this->NIF = NIF; this->localizacao = localizacao;
    this->contrato = false;
  }
  string showInfo();
  string showBasicInfo();
  string showServicos();

  /*
   * Basic Class methods
   */
  // Gets
  string getNome() const {return nome;}
  unsigned long getNIF() const {return NIF;}
  unsigned int getLocalizacao() const {return localizacao;}
  vector<Servico*> getServicos() const {return servicos;}
  bool getContrato() const {return contrato;}

  // Changes
  void changeNome(string novo_nome){nome = novo_nome;}
  void changeNIF(unsigned long novo_NIF){NIF = novo_NIF;}
  void changeLocalizacao(unsigned int nova_localizacao){localizacao = nova_localizacao;}
  void changeServicos(vector<Servico*> novos_servicos){servicos = novos_servicos;}
  void changeContrato(bool novo_contrato){contrato = novo_contrato;}

  // Add
  void addServico(Servico* novo_servico){servicos.push_back(novo_servico);}

  // Remove
  void removeServico(Servico* s);

  bool hasService(Servico* s);
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

// Needed for priority_queue
class CompareEmpresas {
    public:
  bool operator()(Empresa* e1, Empresa* e2){
    if(e1->getLocalizacao() != e2->getLocalizacao())
      return e1->getLocalizacao() > e2->getLocalizacao();
    else return e1->getServicos().size() < e2->getServicos().size();
  } 
};

#endif
