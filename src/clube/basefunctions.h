#ifndef BASEFUNCTIONS_H
#define BASEFUNCTIONS_H

#include "../clube.h"

//#############################
//##          ADD            ##
//#############################
bool Clube::addExterno(Pessoa *p){
    if(p->getClasse() == "Externo"){
        for(unsigned int i = 0; i<externos.size(); i++){
            if(externos[i]->getNIF() == p->getNIF() || externos[i] == p)
                throw p->getNIF();
            if(externos[i]->getNome() == p->getNome())
                throw p->getNome();
        }
        externos.push_back(p);
        return true;
    }
    else return false;
}
bool Clube::addJogador(Jogador *j){
    for(unsigned int i = 0; i<jogadores.size(); i++){
        if(jogadores[i]->getNIF() == j->getNIF() || jogadores[i] == j)
            throw j->getNIF();
        if(jogadores[i]->getNome() == j->getNome())
            throw j->getNome();
    }
    jogadores.push_back(j);
    return true;
}
bool Clube::addSocio(Socio *s){
    for(unsigned int i = 0; i<socios.size(); i++){
        if(socios[i] == s || socios[i]->getNIF() == s->getNIF())
            throw s->getNIF();
        if(socios[i]->getNome() == s->getNome())
        	throw s->getNome();
    }
    socios.push_back(s);
    return true;
}
bool Clube::addDespesa(Despesa* d) {
    for(unsigned int i = 0; i < despesas.size(); i++){
        if(despesas[i] == d)
            return false;
    }
    despesas.push_back(d);
    return true;
}
bool Clube::addEmpresa(Empresa *e){
  if(empresas.empty()){
    empresas.push(e);
    return true;
  }
  EMP_QUEUE dummy = empresas;
  while(!dummy.empty()){
    if(dummy.top()->getNome()==e->getNome() ||
       dummy.top()->getNIF()==e->getNIF()){
      return false;
    }
    dummy.pop();
  }
  empresas.push(e);
  return true;
}

//#############################
//##          REMOVE         ##
//#############################
bool Clube::removeExterno(Pessoa *p){
  for(unsigned int i = 0; i < externos.size(); i++)
    if(p == externos[i]){
      externos.erase(externos.begin()+i);
      return true;
    }
  return false;
}

bool Clube::removeJogador(Jogador *j){
  for(unsigned int i = 0; i < jogadores.size(); i++)
    if(j == jogadores[i]){
      jogadores.erase(jogadores.begin()+i);
      return true;
    }
  return false;
}
bool Clube::removeSocio(Socio *s){
  for(unsigned int i = 0; i < socios.size(); i++)
    if(s == socios[i]){
      socios.erase(socios.begin()+i);
      return true;
    }
  return false;
}

bool Clube::removeDespesa(Despesa* d) {
  for(unsigned int i = 0; i < despesas.size(); i++)
    if(d == despesas[i]){
      despesas.erase(despesas.begin()+i);
      return true;
    }
  return false;
}


//#############################
//##          CHANGE         ##
//#############################

bool Clube::changeModalidade(string name, string new_name){
  if(modalidades.size() < 1){
    iface->drawString("O clube nao tem modalidades associadas.\n");
    return 1;
  }
  for(unsigned int i = 0; i < modalidades.size(); i++){
    if(name == modalidades[i]->getNome()){
      modalidades[i]->changeNome(new_name);
      return 0;
    }
  }
  iface->drawString("Modalidade nao encontrada.\n");
  return 1;
}
bool Clube::changeSubModalidade(string name, string new_name){
  if(sub_modalidades.size() < 1){
    iface->drawString("O clube nao tem sub-modalidades associadas.\n");
    return 1;
  }
  for(unsigned int i = 0; i < sub_modalidades.size(); i++){
    if(name == sub_modalidades[i]->getNome()){
      sub_modalidades[i]->changeNome(new_name);
      return 0;
    }
  }
  iface->drawString("Sub-modalidade nao encontrada.\n");
  return 1;
}
bool Clube::changeDespesa(Despesa* d, string newInfo, Data* novaData, float novoValor) {
  if(despesas.size() < 1){
    iface->drawString("O clube nao tem despesas.\n");
    return false;
  }
  d->setInfo(newInfo);
  d->setData(novaData);
  d->setValor(novoValor);
  return true;
}

#endif
