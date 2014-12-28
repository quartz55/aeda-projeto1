// -*-c++-*-
#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <vector>
#include <sstream>
using std::string; using std::vector;

#include "interface.h"

struct Servico{
  string titulo;
  string descricao;
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

public:
  Empresa(string nome, unsigned long NIF, unsigned int localizacao);
  void manutentaoEmpresa(Interface* i);

  /*
   * Basic Class methods
   */
  // Gets
  string getNome(){return nome;}
  unsigned long getNIF(){return NIF;}
  unsigned int getLocalizacao(){return localizacao;}
  vector<Servico*> getServicos(){return servicos;}

  // Changes
  void changeNome(string novo_nome){nome = novo_nome;}
  void changeNIF(unsigned long novo_NIF){NIF = novo_NIF;}
  void changeLocalizacao(unsigned int nova_localizacao){localizacao = nova_localizacao;}
  void changeServicos(vector<Servico*> novos_servicos){servicos = novos_servicos;}

  // Add
  void addServico(Servico* novo_servico){servicos.push_back(novo_servico);}

  // Remove
  void removeServico(Servico* s);

  bool hasService(Servico* s);
  bool hasService(string titulo);
  
  // Needed for priority_queue
  bool operator()(Empresa& e1, Empresa& e2){ return e1.localizacao < e2.localizacao;}
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

#endif
