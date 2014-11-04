#ifndef LISTAGENS_H
#define LISTAGENS_H

#include "sorts.h"
#include <algorithm>
#include <vector>

void Clube::listarPessoas(){
    iface->drawString("-------------------------------\n");
    iface->drawString("Listagem de todos os associados ao clube\n");
    iface->drawString("-------------------------------\n");
    iface->drawString("-------------------------------\n");
    listar(externos, false, false);
    iface->drawString("-------------------------------\n");
    listar(jogadores, false, false);
    iface->drawString("-------------------------------\n");
    listar(socios, false, false);
    iface->drawString("-------------------------------\n");
    iface->newLine();
}

template<class C>
void Clube::listar(vector<C *> pessoas, bool idade, bool sexo){
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
            iface->drawString("    Nenhum ");
            iface->drawString(pessoas[0]->getClasse());
            iface->drawString(" pertence a esta modalidade\n");
        }
        iface->newLine();
        existe = false;
    }
}

bool Clube::listarJogadores(){
    while(1){
        iface->cleanScr();
        char command;
        iface->drawString("LISTAGEM DE JOGADORES\n\n");
        iface->drawString("a. Listar por ordem alfabetica\n");
        iface->drawString("b. Listar por idade\n");
        iface->drawString("c. Listar por sexo\n");
        iface->drawString("d. Listar por modalidades\n");
        iface->drawString("q. Voltar\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if(command == 'a'){
            std::vector <Jogador *> ordenado(jogadores);
            std::sort(ordenado.begin(), ordenado.end(), sortByName);
            iface->cleanScr();
            iface->drawString("Jogadores ordenados por ordem alfabetica (A-Z):\n");
            listar(ordenado, false, false);
        }
        else if (command == 'b'){
            std::vector <Jogador *> ordenado = jogadores;
            std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
            iface->cleanScr();
            iface->drawString("Jogadores ordenados por ordem de idade:\n");
            listar(ordenado, true, false);
        }
        else if (command == 'c'){
            std::vector <Jogador *> ordenado = jogadores;
            std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
            iface->cleanScr();
            iface->drawString("Jogadores ordenados por sexo:\n");
            listar(ordenado, false, true);
        }
        else if (command == 'd'){
            iface->cleanScr();
            iface->drawString("Jogadores ordenados por modalidades:\n");
            listarPorModalidades(jogadores);
        }
        else if(command == 'q') return false;
        else continue;
        return true;
    }
}


bool Clube::listarSocios(){
    while (1){
        iface->cleanScr();
        char command;
        iface->drawString("LISTAGEM DE SOCIOS\n\n");
        iface->drawString("a. Listar por ordem alfabetica\n");
        iface->drawString("b. Listar por idade\n");
        iface->drawString("c. Listar por sexo\n");
        iface->drawString("d. Listar por modalidades\n");
        iface->drawString("q. Voltar\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if (command == 'a'){
            std::vector <Socio *> ordenado(socios);
            std::sort(ordenado.begin(), ordenado.end(), sortByName);
            iface->cleanScr();
            iface->drawString("Socios ordenados por ordem alfabetica (A-Z):\n");
            listar(ordenado, false, false);
        }
        else if (command == 'b'){
            std::vector <Socio *> ordenado = socios;
            std::sort(ordenado.begin(), ordenado.end(), sortByIdade);
            iface->cleanScr();
            iface->drawString("Socios ordenados por ordem de idade:\n");
            listar(ordenado, true, false);
        }
        else if (command == 'c'){
            std::vector <Socio *> ordenado = socios;
            std::sort(ordenado.begin(), ordenado.end(), sortBySexo);
            iface->cleanScr();
            iface->drawString("Socios ordenados por sexo:\n");
            listar(ordenado, false, true);
        }
        else if (command == 'd'){
            iface->cleanScr();
            iface->drawString("Socios ordenados por modalidades:\n");
            listarPorModalidades(socios);
        }
        else if(command == 'q') return false;
        else continue;
        return true;
    }
}

void Clube::listarModalidades(){
    for(unsigned int i = 0; i < modalidades.size(); i++){
        iface->drawString("> ");
        iface->drawString(modalidades[i]->getNome());
        iface->newLine();
        for(unsigned int k = 0; k < sub_modalidades.size(); k ++){
            if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome()){
                iface->drawString("   -");
                iface->drawString(sub_modalidades[k]->getNome());
                iface->newLine();
            }
        }
    }
}

#endif
