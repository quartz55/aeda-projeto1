#include "clube.h"

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

void Clube::listarModalidades(){
    for(unsigned int i = 0; i < modalidades.size(); i++){
        cout << "» "<< modalidades[i]->getNome() << std::endl;
        for(unsigned int k = 0; k < sub_modalidades.size(); k ++)
            if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome())
                cout << "   -" << sub_modalidades[k]->getNome() << std::endl;
    }
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

bool Clube::readModalidades(string filename){
    std::ifstream file;
    file.open(filename.c_str());
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            Modalidade *m1 = new Modalidade(line);
            modalidades.push_back(m1);
            getline(file, line);
            std::stringstream ss(line);
            string helper;
            ss >> helper;
            while(helper != "#"){
                std::stringstream sub;
                while(helper != "/"){
                    sub << helper << " ";
                    ss >> helper;
                }
                string nome_sub = sub.str();
                nome_sub.erase(nome_sub.size()-1);
                SubModalidade *s1 = new SubModalidade(nome_sub, m1);
                sub_modalidades.push_back(s1);
                ss >> helper;
            }
        }
        file.close();
        return true;
    }
    cout << "Unable to open file '" << filename << "'\n";
    return false;
}

bool Clube::readJogadores(string filename){
    std::ifstream file;
    file.open(filename.c_str());
    if(file.is_open()){
        string line;
        while(getline(file,line)){

            std::stringstream dados_jogador(line);

            //Ler nome jogador
            std::stringstream nome_jogador;
            string helper;
            dados_jogador >> helper;
            while(helper != "#"){
                nome_jogador << helper << " ";
                dados_jogador >> helper;
            }
            string nome = nome_jogador.str();
            nome.erase(nome.size()-1);
            //------------
            //DADOS INICIAIS DO JOGADOR
            unsigned int idade;
            unsigned long NIF;
            string sexo;
            dados_jogador >> idade;
            dados_jogador >> sexo;
            dados_jogador >> NIF;
            Jogador *j1 = new Jogador(nome,idade,NIF,sexo);
            //------------
            addJogador(j1);


            //ATRIBUIR (SUB-)MODALIDADES
            getline(file, line);
            while(line != "--------"){
                for(unsigned int i = 0; i < modalidades.size(); i++){
                    if(modalidades[i]->getNome() == line)
                        j1->addModalidade(modalidades[i]);
                }

                string helper;
                getline(file,line);

                std::stringstream ss(line);

                ss >> helper;
                while(helper != "#"){
                    std::stringstream sub;
                    while(helper != "/"){
                        sub << helper << " ";
                        ss >> helper;
                    }
                    string nome_sub = sub.str();
                    nome_sub.erase(nome_sub.size()-1);
                    for(unsigned int i = 0; i < sub_modalidades.size(); i++){
                        if(sub_modalidades[i]->getNome() == nome_sub)
                            j1->addSubModalidade(sub_modalidades[i]);
                    }
                    ss >> helper;
                }

                getline(file, line);
            }
            //------------
        }
        file.close();
        return true;
    }
    cout << "Unable to open file '" << filename << "'\n";
    return false;
}

bool Clube::readSocios(string filename){
    std::ifstream file;
    file.open(filename.c_str());
    if(file.is_open()){
        string line;
        while(getline(file,line)){

            std::stringstream dados_socio(line);

            //Ler nome socio
            std::stringstream nome_socio;
            string helper;
            dados_socio >> helper;
            while(helper != "#"){
                nome_socio << helper << " ";
                dados_socio >> helper;
            }
            string nome = nome_socio.str();
            nome.erase(nome.size()-1);
            //------------
            //DADOS INICIAIS DO socio
            unsigned int idade;
            unsigned long NIF;
            string sexo;
            dados_socio >> idade;
            dados_socio >> sexo;
            dados_socio >> NIF;
            Socio *s1 = new Socio(nome,idade,NIF,sexo);
            //------------
            addSocio(s1);


            //ATRIBUIR (SUB-)MODALIDADES
            getline(file, line);
            while(line != "--------"){
                for(unsigned int i = 0; i < modalidades.size(); i++){
                    if(modalidades[i]->getNome() == line)
                        s1->addModalidade(modalidades[i]);
                }

                string helper;
                getline(file,line);

                std::stringstream ss(line);

                ss >> helper;
                while(helper != "#"){
                    std::stringstream sub;
                    while(helper != "/"){
                        sub << helper << " ";
                        ss >> helper;
                    }
                    string nome_sub = sub.str();
                    nome_sub.erase(nome_sub.size()-1);
                    for(unsigned int i = 0; i < sub_modalidades.size(); i++){
                        if(sub_modalidades[i]->getNome() == nome_sub)
                            s1->addSubModalidade(sub_modalidades[i]);
                    }
                    ss >> helper;
                }

                getline(file, line);
            }
            //------------
        }
        file.close();
        return true;
    }
    cout << "Unable to open file '" << filename << "'\n";
    return false;
}
bool Clube::writeModalidades(vector<Modalidade *> modalidades, string filename){
    std::ofstream file;
    file.open(filename.c_str());
    if(file.is_open()){
        for(unsigned int i = 0; i<modalidades.size(); i++){
            string modalidade_nome =  modalidades[i]->getNome();
            file << modalidade_nome << endl;
            std::stringstream ss;
            for(unsigned int k = 0; k<sub_modalidades.size(); k++){
                if(sub_modalidades[k]->getMod()->getNome() == modalidade_nome)
                    ss << sub_modalidades[k]->getNome() << " / ";
            }
            ss << "#";
            file << ss.str();
            file << endl;
        }
        file.close();
        return true;
    }
    cout << "Unable to open file '" << filename << "'\n";
    return false;
}

bool Clube::writeJogadores(vector<Jogador *> jogadores, string filename){
    std::ofstream file;
    file.open(filename.c_str());
    if(file.is_open()){
        for(unsigned int i = 0; i<jogadores.size(); i++){
            std::stringstream ss;
            ss << jogadores[i]->getNome() << " # ";
            ss << jogadores[i]->getIdade() << " ";
            ss << jogadores[i]->getSexo() << " ";
            ss << jogadores[i]->getNIF();
            file << ss.str();
            file << endl;
            vector <Modalidade *> mods = jogadores[i]->getMods();
            vector <SubModalidade *> sub_mods = jogadores[i]->getSubMods();
            for(unsigned int k = 0; k < mods.size(); k++){
                string mod_nome = mods[k]->getNome();
                file << mod_nome << endl;;
                ss.str(string()); //Clears the stringstream
                for(unsigned int j = 0; j < sub_mods.size(); j++){
                    if(sub_mods[j]->getMod()->getNome() == mod_nome)
                        ss << sub_mods[j]->getNome() << " / ";
                }
                ss << "#";
                file << ss.str();
                file << endl;
            }
            file << "--------\n";
        }
        file.close();
        return true;
    }
    cout << "Unable to open file '" << filename << "'\n";
    return false;
}

bool Clube::writeSocios(vector<Socio *> socios, string filename){
    std::ofstream file;
    file.open(filename.c_str());
    if(file.is_open()){
        for(unsigned int i = 0; i<socios.size(); i++){
            std::stringstream ss;
            ss << socios[i]->getNome() << " # ";
            ss << socios[i]->getIdade() << " ";
            ss << socios[i]->getSexo() << " ";
            ss << socios[i]->getNIF();
            file << ss.str();
            file << endl;
            vector <Modalidade *> mods = socios[i]->getMods();
            vector <SubModalidade *> sub_mods = socios[i]->getSubMods();
            for(unsigned int k = 0; k < mods.size(); k++){
                string mod_nome = mods[k]->getNome();
                file << mod_nome << endl;;
                ss.str(string()); //Clears the stringstream
                for(unsigned int j = 0; j < sub_mods.size(); j++){
                    if(sub_mods[j]->getMod()->getNome() == mod_nome)
                        ss << sub_mods[j]->getNome() << " / ";
                }
                ss << "#";
                file << ss.str();
                file << endl;
            }
            file << "--------\n";
        }
        file.close();
        return true;
    }
    cout << "Unable to open file '" << filename << "'\n";
    return false;
}
