#include "empresa.h"

void manutentaoEmpresa(Interface* i){
  
}

bool Empresa::hasService(Servico* s){
  for(unsigned int i = 0; i < servicos.size(); i++)
    if(s == servicos[i]) return true;
  return false;
}

bool Empresa::hasService(string titulo){
  for(unsigned int i = 0; i < servicos.size(); i++)
    if(titulo == servicos[i]->titulo) return true;
  return false;
}
