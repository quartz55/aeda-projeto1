#ifndef LISTAGENS_H
#define LISTAGENS_H

#include "sorts.h"
#include <algorithm>
#include <vector>

void Clube::listarPessoal(){
    iface->drawString("-------------------------------\n");
    iface->drawString("Listagem de todos os associados ao clube\n");
    iface->drawString("-------------------------------\n");
    iface->drawString("-------------------------------\n");
    listarPessoas(externos, false, false);
    iface->drawString("-------------------------------\n");
    listarPessoas(jogadores, false, false);
    iface->drawString("-------------------------------\n");
    listarPessoas(socios, false, false);
    iface->drawString("-------------------------------\n");
    iface->newLine();
}

template<class C>
void Clube::listarPessoas(vector<C *> pessoas, bool idade, bool sexo){
    for(unsigned int i = 0; i < pessoas.size(); i++){
        iface->drawString("   > ");
        iface->drawString(pessoas[i]->getNome());
        if(idade){
            iface->drawString(", ");
            iface->drawString(pessoas[i]->getIdade());
        }
        if(sexo){
            iface->drawString(" - ");
            iface->drawString(pessoas[i]->getSexo());
        }
        iface->newLine();
    }
    iface->newLine();
}

template<class C>
void Clube::listarPorModalidades(vector<C *> pessoas){
    bool existe = false;
    for(unsigned int i = 0; i < modalidades.size(); i++){
        iface->drawString(" - ");
        iface->drawString(modalidades[i]->getNome());
        iface->newLine();
        for(unsigned int k = 0; k < pessoas.size(); k++){
            for(unsigned int j = 0; j < pessoas[k]->getMods().size(); j++){
                if(pessoas[k]->getMods()[j] == modalidades[i]){
                    existe = true;
                    iface->drawString("   > ");
                    iface->drawString(pessoas[k]->getNome());
                    iface->newLine();
                }
            }
        }
        if(!existe){
            iface->drawString("   * Nenhum ");
            iface->drawString(pessoas[0]->getClasse());
            iface->drawString(" pertence a esta modalidade\n");
        }
        iface->newLine();
        existe = false;
    }
}

bool Clube::listarJogadores(){
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
        if(command == 'a'){
            std::vector <Jogador *> ordenado(jogadores);
            std::sort(ordenado.begin(), ordenado.end(), sortByName);
			TopMenu("LISTAGEM DE JOGADORES");
            iface->drawString("Jogadores ordenados por ordem alfabetica (A-Z):\n");
            listarPessoas(ordenado, false, false);
        }
        else if (command == 'b'){
            std::vector <Jogador *> ordenado = jogadores;
            std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
			TopMenu("LISTAGEM DE JOGADORES");
            iface->drawString("Jogadores ordenados por ordem de idade:\n");
            listarPessoas(ordenado, true, false);
        }
        else if (command == 'c'){
            std::vector <Jogador *> ordenado = jogadores;
            std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
			TopMenu("LISTAGEM DE JOGADORES");
            iface->drawString("Jogadores ordenados por sexo:\n");
            listarPessoas(ordenado, false, true);
        }
        else if (command == 'd'){
			TopMenu("LISTAGEM DE JOGADORES");
            iface->drawString("Jogadores ordenados por modalidades:\n");
            listarPorModalidades(jogadores);
        }
        else if(command == 'q') return false;
        else continue;
        return true;
    }
}

bool Clube::listarExternos(){
	while (1){
		iface->cleanScr();
		char command;
		TopMenu("LISTAGEM DE EXTERNOS");
		iface->drawString("a. Listar por ordem alfabetica\n");
		iface->drawString("b. Listar por idade\n");
		iface->drawString("c. Listar por sexo\n");
		iface->drawString("q. Voltar\n\n");
		iface->drawString("   > ");
		iface->readChar(command);
		if (command == 'a'){
			std::vector <Pessoa *> ordenado(externos);
			std::sort(ordenado.begin(), ordenado.end(), sortByName);
			TopMenu("LISTAGEM DE EXTERNOS");
			iface->drawString("Externos ordenados por ordem alfabetica (A-Z):\n");
			listarPessoas(ordenado, false, false);
		}
		else if (command == 'b'){
			std::vector <Pessoa *> ordenado = externos;
			std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
			TopMenu("LISTAGEM DE EXTERNOS");
			iface->drawString("Externos ordenados por ordem de idade:\n");
			listarPessoas(ordenado, true, false);
		}
		else if (command == 'c'){
			std::vector <Pessoa *> ordenado = externos;
			std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
			TopMenu("LISTAGEM DE EXTERNOS");
			iface->drawString("Externos ordenados por sexo:\n");
			listarPessoas(ordenado, false, true);
		}
		else if (command == 'q') return false;
		else continue;
		return true;
	}
}

bool Clube::listarSocios(){
    while (1){
        iface->cleanScr();
        char command;
		TopMenu("LISTAGEM DE SOCIOS");
        iface->drawString("a. Listar por ordem alfabetica\n");
        iface->drawString("b. Listar por idade\n");
        iface->drawString("c. Listar por sexo\n");
        iface->drawString("d. Listar por modalidades\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if (command == 'a'){
            std::vector <Socio *> ordenado(socios);
            std::sort(ordenado.begin(), ordenado.end(), sortByName);
			TopMenu("LISTAGEM DE SOCIOS");
            iface->drawString("Socios ordenados por ordem alfabetica (A-Z):\n");
            listarPessoas(ordenado, false, false);
        }
        else if (command == 'b'){
            std::vector <Socio *> ordenado = socios;
            std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
			TopMenu("LISTAGEM DE SOCIOS");
            iface->drawString("Socios ordenados por ordem de idade:\n");
            listarPessoas(ordenado, true, false);
        }
        else if (command == 'c'){
            std::vector <Socio *> ordenado = socios;
            std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
			TopMenu("LISTAGEM DE SOCIOS");
            iface->drawString("Socios ordenados por sexo:\n");
            listarPessoas(ordenado, false, true);
        }
        else if (command == 'd'){
			TopMenu("LISTAGEM DE SOCIOS");
            iface->drawString("Socios ordenados por modalidades:\n");
            listarPorModalidades(socios);
        }
        else if(command == 'q') return false;
        else continue;
        return true;
    }
}

void Clube::listarMods(vector <Modalidade *> modalidades){
    bool tem_subs = false;
    for(unsigned int i = 0; i < modalidades.size(); i++){
        iface->drawString(" - ");
        iface->drawString(modalidades[i]->getNome());
        iface->newLine();
        for(unsigned int k = 0; k < sub_modalidades.size(); k ++){
            if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome()){
                tem_subs = true;
                iface->drawString("   > ");
                iface->drawString(sub_modalidades[k]->getNome());
                iface->newLine();
            }
        }
        if(!tem_subs) iface->drawString("   * Nao tem submodalidades associadas\n");
        iface->newLine();
        tem_subs = false;
    }
}

bool Clube::listarModalidades(){
    while (1){
		TopMenu("LISTAGEM DE MODALIDADES");
        char command;
        iface->drawString("LISTAGEM DE MODALIDADES\n\n");
        iface->drawString("a. Listar por ordem alfabetica\n");
        iface->drawString("b. Listar por numero de submodalidades\n");
        iface->drawString("c. Listar com jogadores\n");
        iface->drawString("d. Listar com socios\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if (command == 'a'){
            std::vector <Modalidade *> ordenado = modalidades;
            std::sort(ordenado.begin(), ordenado.end(), sortByNome);
			TopMenu("LISTAGEM DE MODALIDADES");
            iface->drawString("Modalidades por ordem alfabetica (A-Z):\n");
            listarMods(ordenado);
        }
        else if (command == 'b'){
            std::vector <Modalidade *> ordenado = modalidades;
            std::sort(ordenado.begin(), ordenado.end(), sortByNum);
			TopMenu("LISTAGEM DE MODALIDADES");
            iface->drawString("Modalidades por numero de submodalidades:\n");
            listarMods(ordenado);
        }
        else if (command == 'c'){
            if(jogadores.size() == 0){
                iface->drawString("O clube nao tem socios associados!\n");
                iface->getInput();
                continue;
            }
            iface->cleanScr();
            iface->drawString("Modalidades com jogadores:\n");
            listarPorModalidades(jogadores);
        }
        else if (command == 'd'){
            if(socios.size() == 0){
                iface->drawString("O clube nao tem socios associados!\n");
                iface->getInput();
                continue;
            }
			TopMenu("LISTAGEM DE MODALIDADES");
            iface->drawString("Modalidades com socios:\n");
            listarPorModalidades(socios);
        }
        else if(command == 'q') return false;
        else continue;
        return true;
    }
    return true;
}
bool Clube::listarDespesas() {
	while(1){
		char command;
		TopMenu("LISTAGEM DE DESPESAS");
	    iface->drawString("a. Listar por data\n");
	    iface->drawString("b. Listar por valor\n");
	    iface->drawString("q. Voltar\n\n");
	    iface->drawString("   > ");
	    iface->readChar(command);
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
	    						iface->drawString("Mes invalido!\n\n");
								iface->drawString("\n* Carregue numa tecla para voltar... *\n");
								iface->getInput();
	    					}
	    					else {
	    						iface->drawString("Ano :");
	    						int ano;
	    						iface->read(ano);
	    						if(ano < 0 || ano > 3000){
	    							iface->drawString("Ano invalido!\n\n");
									iface->drawString("\n* Carregue numa tecla para voltar... *\n");
									iface->getInput();
	    						}
	    						else{
									TopMenu("LISTAGEM DE DESPESAS");
	    							iface->drawString("Despesas de ");
	    							iface->drawString(mes);
	    							iface->drawString(" de ");
	    							iface->drawString(ano);
	    							iface->drawString(": \n\n");
	    							for(unsigned int i = 0; i < despesas.size(); i++){
	    								if(despesas[i]->getData()->getMonth() == mes && despesas[i]->getData()->getYear() == ano){
	    									iface->drawString(despesas[i]->showInfo());
	    									iface->newLine();
	    								}
	    							}
	    							return true;
	    						}
	    					}
	    				}
	    				if (command == 'b'){
	    					iface->cleanScr();
	    					iface->drawString("Ano :");
	    					int ano;
	    					iface->read(ano);
	    					if(ano < 0 || ano > 3000){
	    						iface->drawString("Ano invalido!\n");
								iface->getInput();
	    					}
	    					else{
								TopMenu("LISTAGEM DE DESPESAS");
	    						iface->drawString("Despesas de ");;
	    						iface->drawString(ano);
	    						iface->drawString(": \n\n");
	    						for(unsigned int i = 0; i < despesas.size(); i++){
	    							if(despesas[i]->getData()->getYear() == ano){
	    								iface->drawString(despesas[i]->showInfo());
	    								iface->newLine();
	    							}
	    						}
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
	    			iface->drawString("Despesas listadas por data\n\n");
	    			for(unsigned int i = 0; i < despesas.size(); i++){
	    				iface->drawString(despesas[i]->showInfo());
	    				iface->newLine();
	    			}
		    		return true;
	    		}
	    		else if(command == 'q'){
	    			break;
	    		}
	    	}
	    }
	    if (command == 'b'){
	    	std::sort(despesas.begin(),despesas.end(),sortByValor);
	    	while(1){
				TopMenu("LISTAGEM DE DESPESAS");
	    		iface->drawString("Alguma data especifica (y/n/q-voltar) \n\n");
	    		iface->drawString("   > ");
	    		iface->readChar(command);
	    		if(command == 'y'){
	    			while(1){
	    				iface->cleanScr();
	    				iface->drawString("a. Mes e Ano \n");
	    				iface->drawString("b. Ano \n");
	    				iface->drawString("q. Voltar\n\n");
	    				iface->drawString("   > ");
	    				iface->readChar(command);
	    				if (command == 'a'){
	    					iface->cleanScr();
	    					iface->drawString("Mes (inteiro correspondente) :");
	    					int mes;
	    					iface->read(mes);
	    					if(mes < 0 || mes > 12){
	    						iface->drawString("Mes invalido!\n\n");
								iface->drawString("\n* Carregue numa tecla para voltar... *\n");
								iface->getInput();
	    					}
	    					else {
	    						iface->drawString("Ano :");
	    						int ano;
	    						iface->read(ano);
	    						if(ano < 0 || ano > 3000){
	    							iface->drawString("Ano invalido!\n");
									iface->drawString("* Carregue numa tecla para voltar... *\n\n");
									iface->getInput();
	    						}
	    						else{
									TopMenu("LISTAGEM DE DESPESAS");
	    							iface->drawString("Despesas de ");
	    							iface->drawString(mes);
	    							iface->drawString(" de ");
	    							iface->drawString(ano);
	    							iface->drawString(": \n\n");
	    							for(unsigned int i = 0; i < despesas.size(); i++){
	    								if(despesas[i]->getData()->getMonth() == mes && despesas[i]->getData()->getYear() == ano){
	    									iface->drawString(despesas[i]->showInfo());
	    									iface->newLine();
	    								}
	    							}
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
	    						iface->drawString("Ano invalido!\n\n");
								iface->drawString("\n* Carregue numa tecla para voltar... *\n");
								iface->getInput();
	    					}
	    					else{
								TopMenu("LISTAGEM DE DESPESAS");
	    						iface->drawString("Despesas de ");
	    						iface->drawString(ano);
	    						iface->drawString(": \n\n");
	    						for(unsigned int i = 0; i < despesas.size(); i++){
	    							if(despesas[i]->getData()->getYear() == ano){
	    								iface->drawString(despesas[i]->showInfo());
	    								iface->newLine();
	    							}
	    						}
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
	    			iface->drawString("Despesas listadas por valor\n\n");
	    			for(unsigned int i = 0; i < despesas.size(); i++){
	    				iface->drawString(despesas[i]->showInfo());
	    				iface->newLine();
	    			}
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

#endif
