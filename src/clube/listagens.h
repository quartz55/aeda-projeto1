#ifndef LISTAGENS_H
#define LISTAGENS_H

#include "../clube.h"
#include "sorts.h"
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

void Clube::listarPessoal(){
  iface->drawString("-------------------------------\n");
  iface->drawString("Listagem de todos os associados ao clube\n");
  iface->drawString("-------------------------------\n");
  iface->drawString("-------------------------------\n");
  iface->drawString(listarPessoas(externos, false, false));
  iface->drawString("-------------------------------\n");
  iface->drawString(listarPessoas(jogadores, false, false));
  iface->drawString("-------------------------------\n");
  iface->drawString(listarPessoas(socios, false, false));
  iface->drawString("-------------------------------\n");
  iface->newLine();
}

template<class C>
string Clube::listarPessoas(vector<C *> pessoas, bool idade, bool sexo){
  std::stringstream ss;
  for(unsigned int i = 0; i < pessoas.size(); i++){
    ss << "   > ";
    ss << pessoas[i]->getNome();
    if(idade){
      ss << ", ";
      ss << pessoas[i]->getIdade();
    }
    if(sexo){
      ss << " - ";
      ss << pessoas[i]->getSexo();
    }
    ss << "\n";
  }
  ss << "\n";
  return ss.str();
}

template<class C>
string Clube::listarPorModalidades(vector<C *> pessoas){
  std::stringstream ss;
  bool existe = false;
  for(unsigned int i = 0; i < modalidades.size(); i++){
    ss << " - ";
    ss << modalidades[i]->getNome();
    ss << "\n";
    for(unsigned int k = 0; k < pessoas.size(); k++){
      for(unsigned int j = 0; j < pessoas[k]->getMods().size(); j++){
        if(pessoas[k]->getMods()[j] == modalidades[i]){
          existe = true;
          ss << "   > ";
          ss << pessoas[k]->getNome();
          ss << "\n";
        }
      }
    }
    if(!existe){
      ss << "   * Nenhum ";
      ss << pessoas[0]->getClasse();
      ss << " pertence a esta modalidade\n";
    }
    ss << "\n";
    existe = false;
  }
  ss << " - Sem modalidades associadas\n";
  for (unsigned int i = 0; i < pessoas.size(); i++)
    {
      if (pessoas[i]->getMods().size() == 0)
        {
          ss << "   > ";
          ss << pessoas[i]->getNome();
          ss << "\n";
        }
    }

  return ss.str();
}

bool Clube::listarJogadores(string &lista){
  while(1){
    TopMenu("LISTAGEM DE JOGADORES");
    char command;
    iface->drawString("a. Listar por ordem alfabetica\n");
    iface->drawString("b. Listar por idade\n");
    iface->drawString("c. Listar por sexo\n");
    iface->drawString("d. Listar por modalidades\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    iface->readChar(command);
    std::stringstream ss;
    ss.str(string());
    if(command == 'a'){
      std::vector <Jogador *> ordenado(jogadores);
      std::sort(ordenado.begin(), ordenado.end(), sortByName);
      TopMenu("LISTAGEM DE JOGADORES");
      ss << "Jogadores ordenados por ordem alfabetica (A-Z):\n";
      ss << listarPessoas(ordenado, false, false);
      lista = ss.str();
    }
    else if (command == 'b'){
      std::vector <Jogador *> ordenado = jogadores;
      std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
      TopMenu("LISTAGEM DE JOGADORES");
      ss << "Jogadores ordenados por ordem de idade:\n";
      ss << listarPessoas(ordenado, true, false);
      lista = ss.str();
    }
    else if (command == 'c'){
      std::vector <Jogador *> ordenado = jogadores;
      std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
      TopMenu("LISTAGEM DE JOGADORES");
      ss << "Jogadores ordenados por sexo:\n";
      ss << listarPessoas(ordenado, false, true);
      lista = ss.str();
    }
    else if (command == 'd'){
      TopMenu("LISTAGEM DE JOGADORES");
      ss << "Jogadores ordenados por modalidades:\n";
      ss << listarPorModalidades(jogadores);
      lista = ss.str();
    }
    else if(command == 'q') return false;
    else continue;
    return true;
  }
}
bool Clube::listarSocios(string &lista){
  while (1){
    char command;
    TopMenu("LISTAGEM DE SOCIOS");
    iface->drawString("a. Listar por ordem alfabetica\n");
    iface->drawString("b. Listar por idade\n");
    iface->drawString("c. Listar por sexo\n");
    iface->drawString("d. Listar por modalidades\n");
    iface->drawString("e. Listar com quotas em atraso\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    iface->readChar(command);
    std::stringstream ss;
    ss.str(string());
    if(command == 'a'){
      std::vector <Socio *> ordenado(socios);
      SociosHash::const_iterator it = socios_em_atraso.begin();
      while(it != socios_em_atraso.end()){
    	 ordenado.push_back(*it);
    	 it++;
      }
      std::sort(ordenado.begin(), ordenado.end(), sortByName);
      TopMenu("LISTAGEM DE SOCIOS");
      ss << "Socios ordenados por ordem alfabetica (A-Z):\n";
      ss << listarPessoas(ordenado, false, false);
      lista = ss.str();
    }
    else if (command == 'b'){
      std::vector <Socio *> ordenado = socios;
      SociosHash::const_iterator it = socios_em_atraso.begin();
      while(it != socios_em_atraso.end()){
    	 ordenado.push_back(*it);
    	 it++;
      }
      std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
      TopMenu("LISTAGEM DE SOCIOS");
      ss << "Socios ordenados por ordem de idade:\n";
      ss << listarPessoas(ordenado, true, false);
      lista = ss.str();
    }
    else if (command == 'c'){
      std::vector <Socio *> ordenado = socios;
      SociosHash::const_iterator it = socios_em_atraso.begin();
      while(it != socios_em_atraso.end()){
    	 ordenado.push_back(*it);
    	 it++;
      }
      std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
      TopMenu("LISTAGEM DE SOCIOS");
      ss << "Socios ordenados por sexo:\n";
      ss << listarPessoas(ordenado, false, true);
      lista = ss.str();
    }
    else if (command == 'd'){
      std::vector <Socio *> ordenado = socios;
      SociosHash::const_iterator it = socios_em_atraso.begin();
      while(it != socios_em_atraso.end()){
    	ordenado.push_back(*it);
    	it++;
      }
      TopMenu("LISTAGEM DE SOCIOS");
      ss << "Socios ordenados por modalidades:\n";
      ss << listarPorModalidades(ordenado);
      lista = ss.str();
    }
    else if (command == 'e'){
      std::vector <Socio *> ordenado;
      SociosHash::const_iterator it = socios_em_atraso.begin();
      while(it != socios_em_atraso.end()){
    	ordenado.push_back(*it);
    	it++;
      }
      std::sort(ordenado.begin(), ordenado.end(), sortByName);
      TopMenu("LISTAGEM DE SOCIOS");
      ss << "Socios ordenados com quotas em atraso:\n";
      ss << listarComQuotas(ordenado);
      lista = ss.str();
    }
    else if(command == 'q') return false;
    else continue;
    return true;
  }
}
bool Clube::listarExternos(string &lista){
  while (1){
    char command;
    TopMenu("LISTAGEM DE EXTERNOS");
    iface->drawString("a. Listar por ordem alfabetica\n");
    iface->drawString("b. Listar por idade\n");
    iface->drawString("c. Listar por sexo\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    iface->readChar(command);
    std::stringstream ss;
    ss.str(string());
    if (command == 'a'){
      std::vector <Pessoa *> ordenado(externos);
      std::sort(ordenado.begin(), ordenado.end(), sortByName);
      TopMenu("LISTAGEM DE EXTERNOS");
      ss << "Externos ordenados por ordem alfabetica (A-Z):\n";
      ss << listarPessoas(ordenado, false, false);
    }
    else if (command == 'b'){
      std::vector <Pessoa *> ordenado = externos;
      std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
      TopMenu("LISTAGEM DE EXTERNOS");
      ss << "Externos ordenados por ordem de idade:\n";
      ss << listarPessoas(ordenado, true, false);
    }
    else if (command == 'c'){
      std::vector <Pessoa *> ordenado = externos;
      std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
      TopMenu("LISTAGEM DE EXTERNOS");
      ss << "Externos ordenados por sexo:\n";
      ss << listarPessoas(ordenado, false, true);
    }
    else if (command == 'q') return false;
    else continue;
    lista = ss.str();
    return true;
  }
}

string Clube::listarMods(vector <Modalidade *> modalidades){
  bool tem_subs = false;
  std::stringstream ss;
  for(unsigned int i = 0; i < modalidades.size(); i++){
    ss << " - ";
    ss << modalidades[i]->getNome();
    ss << "\n";
    for(unsigned int k = 0; k < sub_modalidades.size(); k ++){
      if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome()){
        tem_subs = true;
        ss << "   > ";
        ss << sub_modalidades[k]->getNome();
        ss << "\n";
      }
    }
    if(!tem_subs) ss << "   * Nao tem submodalidades associadas\n";
    ss << "\n";
    tem_subs = false;
  }
  return ss.str();
}

bool Clube::listarModalidades(string &lista){
  while (1){
    TopMenu("LISTAGEM DE MODALIDADES");
    char command;
    iface->drawString("a. Listar por ordem alfabetica\n");
    iface->drawString("b. Listar por numero de submodalidades\n");
    iface->drawString("c. Listar com jogadores\n");
    iface->drawString("d. Listar com socios\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    iface->readChar(command);
    std::stringstream ss;
    ss.str(string());
    if (command == 'a'){
      std::vector <Modalidade *> ordenado = modalidades;
      std::sort(ordenado.begin(), ordenado.end(), sortByNome);
      TopMenu("LISTAGEM DE MODALIDADES");
      ss << "Modalidades por ordem alfabetica (A-Z):\n";
      ss << listarMods(ordenado);
      lista = ss.str();
    }
    else if (command == 'b'){
      std::vector <Modalidade *> ordenado = modalidades;
      std::sort(ordenado.begin(), ordenado.end(), sortByNum);
      TopMenu("LISTAGEM DE MODALIDADES");
      ss << "Modalidades por numero de submodalidades:\n";
      ss << listarMods(ordenado);
      lista = ss.str();
    }
    else if (command == 'c'){
      if(jogadores.size() == 0){
        iface->drawString("\n\nO clube nao tem socios associados!\n");
        pressToContinue();
        continue;
      }
      TopMenu("LISTAGEM DE MODALIDADES");
      ss << "Modalidades com jogadores:\n";
      ss << listarPorModalidades(jogadores);
      lista = ss.str();
    }
    else if (command == 'd'){
      if(socios.size() == 0){
        iface->drawString("\n\nO clube nao tem socios associados!\n");
        pressToContinue();
        continue;
      }
      TopMenu("LISTAGEM DE MODALIDADES");
      ss << "Modalidades com socios:\n";
      ss << listarPorModalidades(socios);
      lista = ss.str();
    }
    else if(command == 'q') return false;
    else continue;
    return true;
  }
  return true;
}
bool Clube::listarDespesas(string &lista) {
  while(1){
    char command;
    TopMenu("LISTAGEM DE DESPESAS");
    iface->drawString("a. Listar por data\n");
    iface->drawString("b. Listar por valor\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    iface->readChar(command);
    std::stringstream ss;
    ss.str(string());
    if (command == 'a'){
      std::sort(despesas.begin(),despesas.end(),sortByData);
      while(1){
        TopMenu("LISTAGEM DE DESPESAS");
        iface->drawString("Alguma data especifica (y/n/q-voltar) \n\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if(command == 'y'){
          while(1){
            TopMenu("LISTAGEM DE DESPESAS");
            iface->drawString("a. Mes e Ano \n");
            iface->drawString("b. Ano \n");
            iface->drawString("q. Voltar\n\n");
            iface->drawString("   > ");
            iface->readChar(command);
            if (command == 'a'){
              TopMenu("LISTAGEM DE DESPESAS");
              iface->drawString("Mes (inteiro correspondente) :");
              int mes;
              iface->read(mes);
              if(mes < 0 || mes > 12){
                iface->drawString("\n\nMes invalido!\n\n");
                pressToContinue();
              }
              else {
                iface->drawString("Ano :");
                int ano;
                iface->read(ano);
                if(ano < 0 || ano > 3000){
                  iface->drawString("\n\nAno invalido!\n\n");
                  pressToContinue();
                }
                else{
                  TopMenu("LISTAGEM DE DESPESAS");
                  ss << "Despesas de ";
                  ss << mes;
                  ss << " de ";
                  ss << ano;
                  ss << ": \n\n";
                  float total = 0;
                  for(unsigned int i = 0; i < despesas.size(); i++){
                    if(despesas[i]->getData()->getMonth() == mes && despesas[i]->getData()->getYear() == ano){
                      total += despesas[i]->getValor();
                      ss << despesas[i]->showInfo();
                      ss << "\n";
                    }
                  }
                  ss << "\n";
                  ss << "Total do mes: ";
                  ss << total;
                  ss << "\n";
                  lista = ss.str();
                  return true;
                }
              }
            }
            else if (command == 'b'){
              TopMenu("LISTAGEM DE DESPESAS");
              iface->drawString("Ano :");
              int ano;
              iface->read(ano);
              if(ano < 0 || ano > 3000){
                iface->drawString("\n\nAno invalido!\n");
                pressToContinue();
              }
              else{
                TopMenu("LISTAGEM DE DESPESAS");
                ss << "Despesas de ";
                ss << ano;
                ss << ": \n\n";
                float total = 0;
                for(unsigned int i = 0; i < despesas.size(); i++){
                  if(despesas[i]->getData()->getYear() == ano){
                    total += despesas[i]->getValor();
                    ss << despesas[i]->showInfo();
                    ss << "\n";
                  }
                }
                ss << "\n";
                ss << "Total do ano: ";
                ss << total;
                ss << "\n";
                lista = ss.str();
                return true;
              }
            }
            else if(command == 'q'){
              break;
            }
          }
        }
        else if(command == 'n'){
          TopMenu("LISTAGEM DE DESPESAS");
          ss << "Despesas listadas por data\n\n";
          for(unsigned int i = 0; i < despesas.size(); i++){
            ss << despesas[i]->showInfo();
            ss << "\n";
          }
          lista = ss.str();
          return true;
        }
        else if(command == 'q'){
          break;
        }
      }
    }
    else if (command == 'b'){
      std::sort(despesas.begin(),despesas.end(),sortByValor);
      while(1){
        TopMenu("LISTAGEM DE DESPESAS");
        iface->drawString("Alguma data especifica (y/n/q-voltar) \n\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if(command == 'y'){
          while(1){
            TopMenu("LISTAGEM DE DESPESAS");
            iface->drawString("a. Mes e Ano \n");
            iface->drawString("b. Ano \n");
            iface->drawString("q. Voltar\n\n");
            iface->drawString("   > ");
            iface->readChar(command);
            if (command == 'a'){
              TopMenu("LISTAGEM DE DESPESAS");
              iface->drawString("Mes (inteiro correspondente) :");
              int mes;
              iface->read(mes);
              if(mes < 0 || mes > 12){
                iface->drawString("\n\nMes invalido!\n\n");
                pressToContinue();
              }
              else {
                TopMenu("LISTAGEM DE DESPESAS");
                iface->drawString("Ano :");
                int ano;
                iface->read(ano);
                if(ano < 0 || ano > 3000){
                  iface->drawString("\n\nAno invalido!\n");
                  pressToContinue();
                }
                else{
                  TopMenu("LISTAGEM DE DESPESAS");
                  ss << "Despesas de ";
                  ss << mes;
                  ss << " de ";
                  ss << ano;
                  ss << ": \n\n";
                  float total =0;
                  for(unsigned int i = 0; i < despesas.size(); i++){
                    if(despesas[i]->getData()->getMonth() == mes && despesas[i]->getData()->getYear() == ano){
                      total += despesas[i]->getValor();
                      ss << despesas[i]->showInfo();
                      ss << "\n";
                    }
                  }
                  ss << "\n";
                  ss << "Total do mes: ";
                  ss << total;
                  ss << "\n";
                  lista = ss.str();
                  return true;
                }
              }
            }
            if (command == 'b'){
              TopMenu("LISTAGEM DE DESPESAS");
              iface->drawString("Ano :");
              int ano;
              iface->read(ano);
              if(ano < 0 || ano > 3000){
                iface->drawString("\n\nAno invalido!\n\n");
                pressToContinue();
              }
              else{
                TopMenu("LISTAGEM DE DESPESAS");
                ss << "Despesas de ";
                ss << ano;
                ss << ": \n\n";
                float total=0;
                for(unsigned int i = 0; i < despesas.size(); i++){
                  if(despesas[i]->getData()->getYear() == ano){
                    total += despesas[i]->getValor();
                    ss << despesas[i]->showInfo();
                    ss << "\n";
                  }
                }
                ss << "\n";
                ss << "Total do ano: ";
                ss << total;
                ss << "\n";
                lista = ss.str();
                return true;
              }
            }
            else if(command == 'q'){
              break;
            }
          }
        }
        else if(command == 'n'){
          TopMenu("LISTAGEM DE DESPESAS");
          ss << "Despesas listadas por valor\n\n";
          for(unsigned int i = 0; i < despesas.size(); i++){
            ss << despesas[i]->showInfo();
            ss << "\n";
          }
          lista = ss.str();
          return true;
        }
        else if(command == 'q'){
          break;
        }
      }
    }
    else if (command == 'q') return false;
  }
  return true;
}

bool Clube::listarLugares(string &lista) {
	while (1){
		char command;
		TopMenu("LISTAGEM DE LUGARES");
		iface->drawString("a. Listar por tipo\n");
		iface->drawString("b. Listar por nome de socio\n");
		iface->drawString("c. Listar por ultimo pagamento\n");
		iface->drawString("q. Voltar\n\n");
		iface->drawString("   > ");
		iface->readChar(command);
		std::stringstream ss;
		ss.str(string());
		if (command == 'a'){
			//std::sort(lugares.begin(), lugares.end(), sortByTipo);
			while (1){
				TopMenu("LISTAGEM DE LUGARES");
				ss << "Lugares listados por tipo:\n\n";
				for (set<Lugar*>::iterator it = lugares.begin(); it != lugares.end(); it++){
					ss << (*it)->showInfo();
					ss << "\n";
				}
				lista = ss.str();
				return true;
			}
		}
		else if (command == 'b'){
			//std::sort(lugares.begin(), lugares.end(), sortBySocio);
			while (1){
				TopMenu("LISTAGEM DE LUGARES");
				ss << "Lugares listados por nome de socio:\n\n";
				for (set<Lugar*>::iterator it = lugares.begin(); it != lugares.end(); it++){
					ss << (*it)->showInfo();
					ss << "\n";
				}
				lista = ss.str();
				return true;
			}
		}
		else if (command == 'c'){
			//std::sort(lugares.begin(), lugares.end(), sortLugByData);
			while (1){
				TopMenu("LISTAGEM DE LUGARES");
				iface->drawString("Alguma data especifica (y/n/q-voltar) \n\n");
				iface->drawString("   > ");
				iface->readChar(command);
				if (command == 'y'){
					while (1){
						TopMenu("LISTAGEM DE LUGARES");
						iface->drawString("a. Mes e Ano \n");
						iface->drawString("b. Ano \n");
						iface->drawString("q. Voltar\n\n");
						iface->drawString("   > ");
						iface->readChar(command);
						if (command == 'a'){
							TopMenu("LISTAGEM DE LUGARES");
							iface->drawString("Mes (inteiro correspondente) :");
							int mes;
							iface->read(mes);
							if (mes < 0 || mes > 12){
								iface->drawString("\n\nMes invalido!\n\n");
								pressToContinue();
							}
							else {
								iface->drawString("Ano :");
								int ano;
								iface->read(ano);
								if (ano < 0 || ano > 3000){
									iface->drawString("\n\nAno invalido!\n\n");
									pressToContinue();
								}
								else{
									TopMenu("LISTAGEM DE LUGARES");
									ss << "Lugares com ultimo pagamento a ";
									ss << mes;
									ss << " de ";
									ss << ano;
									ss << ": \n\n";
									for (set<Lugar*>::iterator it = lugares.begin(); it != lugares.end(); it++){
										if ((*it)->getLast_payed()->getMonth() == mes && (*it)->getLast_payed()->getYear() == ano){
											ss << (*it)->showInfo();
											ss << "\n";
										}
									}
									ss << "\n";
									lista = ss.str();
									return true;
								}
							}
						}
						else if (command == 'b'){
							TopMenu("LISTAGEM DE LUGARES");
							iface->drawString("Ano :");
							int ano;
							iface->read(ano);
							if (ano < 0 || ano > 3000){
								iface->drawString("\n\nAno invalido!\n");
								pressToContinue();
							}
							else{
								TopMenu("LISTAGEM DE LUGARES");
								ss << "Lugares com ultimo pagamento em ";
								ss << ano;
								ss << ": \n\n";
								for (set<Lugar*>::iterator it = lugares.begin(); it != lugares.end(); it++){
									if ((*it)->getLast_payed()->getYear() == ano){
										ss << (*it)->showInfo();
										ss << "\n";
									}
								}
								ss << "\n";
								lista = ss.str();
								return true;
							}
						}
						else if (command == 'q'){
							break;
						}
					}
				}
				else if (command == 'n'){
					TopMenu("LISTAGEM DE LUGARES");
					ss << "Lugares listados por data\n\n";
					for (set<Lugar*>::iterator it = lugares.begin(); it != lugares.end(); it++){
						ss << (*it)->showInfo();
						ss << "\n";
					}
					lista = ss.str();
					return true;
				}
				else if (command == 'q'){
					break;
				}
			}
		}
		else if (command == 'q') return false;
	}
	return true;
}

string Clube::listarComQuotas(vector <Socio*> socios){
	std::stringstream ss;
	for(unsigned int i = 0; i < socios.size(); i++){
		ss << "   > ";
		ss << socios[i]->getNome() << "\n";
		vector<Quota*> quotas = socios[i]->getQuotas();
		for(size_t k = 0; k < quotas.size(); k++){
			ss << "       -" << quotas[k]->getModalidade()->getNome() << ": " << socios[i]->QuotasAtrasadas(dataActual, quotas[k]->getModalidade()) << " meses atrasados\n";
		}
	}
	ss << "\n";
	return ss.str();
}

bool Clube::listarEmpresas(string &lista){
  EMP_QUEUE final;
  bool ready = false;
  while(!ready){
    final = EMP_QUEUE(); //Clean final queue before using
    TopMenu("LISTAGEM DE EMPRESAS");
    char command;
    iface->drawString("a. Listar todas\n");
    iface->drawString("b. Listar por servico\n");
    iface->drawString("c. Listar por contratos\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    iface->readChar(command);
    if(command == 'a'){
      final = empresas;
      break;
    }
    else if (command == 'b'){
      if(!listarEmpresasPorServicos(lista)) continue;
      return true;
    }
    else if (command == 'c'){
      while(1){
        EMP_QUEUE dummy;
        dummy = empresas;
        TopMenu("LISTAGEM DE EMPRESAS");
        iface->drawString("a. Listar empresas contratadas\n");
        iface->drawString("b. Listar empresas nao contratadas\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        iface->readChar(command);
        bool contrato;
        if(command == 'a') contrato = true;
        else if(command == 'b') contrato = false;
        else if(command == 'q') break;
        else continue;
        while(!dummy.empty()){
          if(contrato){
            if(dummy.top()->getContrato()) final.push(dummy.top());
          }
          else if(!dummy.top()->getContrato()) final.push(dummy.top());
          dummy.pop();
        }
        ready = true;
        break;
      } 
    } 
    else if(command == 'q') return false;
  }
  std::ostringstream ss;
  ss << "Empresas por ordem crescente de distancia:\n";
  while(!final.empty()){
    ss << "   > " << final.top()->getNome() << " | " << final.top()->getLocalizacao() << " kms | " << final.top()->getServicos().size() << " servicos disponiveis";
    if(final.top()->getContrato()) ss << " **CONTRATO ASSINADO**";
    ss << std::endl;
    final.pop();
  }
  lista = ss.str();
  return true;
}
bool Clube::listarEmpresasPorServicos(string &lista){
  EMP_QUEUE final;
  while(1){
    TopMenu("LISTAGEM DE EMPRESAS");
    vector<std::string> vec;
    iface->drawString(listarServicos(vec));
    iface->drawString("\n\n(q para sair)\n\n");
    iface->drawString("Escolha o servico a procurar: ");
    string titulo="";
    while(titulo=="") iface->readLine(titulo);
    if(titulo == "q") return false;
    bool existe = false;
    for(unsigned int i = 0; i<vec.size(); i++)
      if(vec[i] == titulo){
        existe = true;
        break;
      }
    if(!existe){
      iface->drawString("Servico nao existente\n");
      pressToContinue();
      continue;
    }
    EMP_QUEUE dummy = empresas;
    while(!dummy.empty()){
      for(unsigned int i = 0; i < dummy.top()->getServicos().size(); i++)
        if(titulo == dummy.top()->getServicos()[i]->titulo) final.push(dummy.top());
      dummy.pop();
    }
    break;
  }
  std::ostringstream ss;
  ss << "Empresas por ordem crescente de distancia:\n";
  while(!final.empty()){
    ss << "   > " << final.top()->getNome() << " | " << final.top()->getLocalizacao() << " kms | " << final.top()->getServicos().size() << " servicos disponiveis";
    if(final.top()->getContrato()) ss << " **CONTRATO ASSINADO**";
    ss << std::endl;
    final.pop();
  }
  lista = ss.str();
  return true;
}
string Clube::listarServicos(vector<std::string> &vector_ref){
  vector<std::string> vec;
  EMP_QUEUE dummy = empresas;
  while(!dummy.empty()){
    for(unsigned int i = 0; i<dummy.top()->getServicos().size(); i++){
      bool existe = false;
      for(unsigned int k = 0; k<vec.size(); k++){
        if(dummy.top()->getServicos()[i]->titulo == vec[k]){
          existe = true;
          break;
        }
      }
      if(!existe) vec.push_back(dummy.top()->getServicos()[i]->titulo);
    }
    dummy.pop();
  }
  std::ostringstream ss;
  for(unsigned int i = 0; i < vec.size(); i++)
    ss << "   > " << vec[i] << std::endl;
  vector_ref = vec;
  return ss.str();
}

#endif
