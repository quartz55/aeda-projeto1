#include "clube.h"

Clube::Clube(){};

bool Clube::changeModalidade(string name, string new_name){
    if(modalidades.size() < 1){
        cout << "O clube nao tem modalidades associadas.\n";
        return 1;
    }
    for(unsigned int i = 0; i < modalidades.size(); i++){
        if(name == modalidades[i]->getNome()){
            modalidades[i]->changeNome(new_name);
            return 0;
        }
    }
    cout << "Modalidade nao encontrada.\n";
    return 1;
}
bool Clube::changeSubModalidade(string name, string new_name){
    if(sub_modalidades.size() < 1){
        cout << "O clube nao tem sub-modalidades associadas.\n";
        return 1;
    }
    for(unsigned int i = 0; i < sub_modalidades.size(); i++){
        if(name == sub_modalidades[i]->getNome()){
            sub_modalidades[i]->changeNome(new_name);
            return 0;
        }
    }
    cout << "Sub-modalidade nao encontrada.\n";
    return 1;
}

void Clube::CRUD(){
    while(1){
        char command;
        cout << "a. Manutencao\n";
        cout << "   » ";
        cin >> command;
        cout << "a. Manutencao Jogadores\n";
        cout << "   » ";
        cin >> command;
        if(command == 'a') manutencaoJogadores();
    }
}

bool Clube::manutencaoJogadores(){
    while(1){
        cout << "Listagem de jogadores\n";
        unsigned int counter = 0;
        for(unsigned int i = 0; i < jogadores.size(); i++){
            cout << jogadores[i]->getNome() << "    ";
            counter++;
            if(counter>3){ cout << endl; counter = 0;}
        }
        cout << endl;
        cout << "Escolha o jogador a gerir: ";
        string nome_input;
        cin.get();
        getline(cin, nome_input);
        if(nome_input == "q") return true;
        Jogador *j1 = NULL;
        for(unsigned int i = 0; i<jogadores.size(); i++){
            if(jogadores[i]->getNome() == nome_input) j1 = jogadores[i];
        }
        if(j1 != NULL) manutencaoJogador(j1);
        else {
            cout << "Jogador nao existe!\n";
            continue;
        }
    }
    return false;
}

bool Clube::manutencaoJogador(Jogador *j1){
    cout << "Informacao do jogador:\n";
    j1->showInfo();
    cout << "\n\na. Mudar nome\n";
    cout << "b. Mudar idade\n";
    cout << "c. Mudar NIF\n";
    cout << "d. Associacao de (sub-)modalidades\n";
    cout << "e. Remover jogador(!)\n";
    char command;
    cout << "   » ";
    cin >> command;
    return true;
}
