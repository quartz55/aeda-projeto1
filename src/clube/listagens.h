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
            std::sort(ordenado.begin(), ordenado.end(), sortByName);
            TopMenu("LISTAGEM DE SOCIOS");
            ss << "Socios ordenados por ordem alfabetica (A-Z):\n";
            ss << listarPessoas(ordenado, false, false);
            lista = ss.str();
        }
        else if (command == 'b'){
            std::vector <Socio *> ordenado = socios;
            std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
            TopMenu("LISTAGEM DE SOCIOS");
            ss << "Socios ordenados por ordem de idade:\n";
            ss << listarPessoas(ordenado, true, false);
            lista = ss.str();
        }
        else if (command == 'c'){
            std::vector <Socio *> ordenado = socios;
            std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
            TopMenu("LISTAGEM DE SOCIOS");
            ss << "Socios ordenados por sexo:\n";
            ss << listarPessoas(ordenado, false, true);
            lista = ss.str();
        }
        else if (command == 'd'){
            TopMenu("LISTAGEM DE SOCIOS");
            ss << "Socios ordenados por modalidades:\n";
            ss << listarPorModalidades(socios);
            lista = ss.str();
        }
        else if (command == 'e'){
        	std::vector <Socio *> ordenado(socios);
        	std::sort(ordenado.begin(), ordenado.end(), sortByName);
              TopMenu("LISTAGEM DE SOCIOS");
              ss << "Socios ordenados por modalidades:\n";
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
  EMP_QUEUE dummy = empresas;
  std::ostringstream ss;
  ss << "Empresas por ordem crescente de distancia:\n";
  while(!dummy.empty()){
    ss << "   > " << dummy.top()->getNome() << ", " << dummy.top()->getLocalizacao() << " kms (" << dummy.top()->getServicos().size() << " servicos disponiveis)\n";
    dummy.pop();
  }
  lista = ss.str();
  return true;
}

#endif
