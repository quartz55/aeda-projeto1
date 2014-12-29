#include "empresa.h"

string Empresa::showInfo(){
  std::ostringstream ss;
  ss << showBasicInfo();

  string servicos_STRING = showServicos();
  ss << "----------------------------------------------\n";
  ss << "Servicos de " << nome << " disponiveis \n";
  ss << "----------------------------------------------\n";
  if(servicos_STRING != "") ss << servicos_STRING;
  else ss << "A empresa nao possui nenhum servico\n";
  ss << "----------------------------------------------\n";
  return ss.str();
}

string Empresa::showBasicInfo(){
  std::ostringstream ss;
  ss << nome << "\n";
  ss << "NIF: " << NIF << std::endl;
  ss << "Esta empresa encontra-se a " << localizacao << " km de distancia\n";
  if(contrato) ss << "Empresa ja tem um contrato assinado com o clube\n";
  else ss << "É possível assinar um contrato com esta empresa!\n";
  return ss.str();
}
string Empresa::showServicos(){
  if(servicos.size() == 0) return "";
  std::ostringstream ss;
  for(unsigned int i = 0; i < servicos.size(); i++){
    ss << "> " << servicos[i]->titulo << "\n";
    ss << "   -" << servicos[i]->descricao << "\n";
  }
  return ss.str();
}

bool Empresa::hasService(Servico* s){
  if(servicos.empty()) return false;
  for(unsigned int i = 0; i < servicos.size(); i++)
    if(s == servicos[i]) return true;
  return false;

}

bool Empresa::hasService(string titulo){
  if(servicos.empty()) return false;
  for(unsigned int i = 0; i < servicos.size(); i++)
    if(titulo == servicos[i]->titulo) return true;
  return false;
}
