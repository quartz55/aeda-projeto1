#include "clube.h"

Clube::Clube(){};

bool Clube::addExterno(Pessoa *p){
    if(p->getClasse() == "Externo"){
        externos.push_back(p);
        return true;
    }
    else return false;
}

bool Clube::addJogador(Jogador *j){
    for(unsigned int i = 0; i<jogadores.size(); i++){
        if(jogadores[i] == j)
            return false;
    }
    jogadores.push_back(j);
    return true;
}

bool Clube::addSocio(Socio *s){
    for(unsigned int i = 0; i<socios.size(); i++){
        if(socios[i] == s)
            return false;
    }
    socios.push_back(s);
    return true;
}

bool Clube::removeJogador(Jogador *j){
    return true;
}

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

void Clube::listarPessoas(){
    cout << "-------------------------------\n";
    cout << "Listagem de todos os associados ao clube\n";
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    listarExternos();
    cout << "-------------------------------\n";
    listarJogadores();
    cout << "-------------------------------\n";
    listarSocios();
    cout << "-------------------------------\n";
    cout << endl;
}

void Clube::listarExternos(){
    cout << "Listagem de externos:\n";
    unsigned int counter = 0;
    for(unsigned int i = 0; i < externos.size(); i++){
        cout << externos[i]->getNome() << "    ";
        counter++;
        if(counter>3){ cout << endl; counter = 0;}
    }
    cout << endl;
}

void Clube::listarJogadores(){
    cout << "Listagem de jogadores\n";
    unsigned int counter = 0;
    for(unsigned int i = 0; i < jogadores.size(); i++){
        cout << jogadores[i]->getNome() << "    ";
        counter++;
        if(counter>3){ cout << endl; counter = 0;}
    }
    cout << endl;
}

void Clube::listarSocios(){
    cout << "Listagem de socios:\n";
    unsigned int counter = 0;
    for(unsigned int i = 0; i < socios.size(); i++){
        cout << socios[i]->getNome() << "    ";
        counter++;
        if(counter>3){ cout << endl; counter = 0;}
    }
    cout << endl;
}

bool Clube::manutencaoJogadores(){
    while(1){
        listarJogadores();
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
