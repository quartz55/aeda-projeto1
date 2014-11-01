#include "clube.h"

string Clube::FILE_JOGADORES = "txt/jogadores.txt";
string Clube::FILE_MODALIDADES = "txt/modalidades.txt";
string Clube::FILE_SOCIOS = "txt/socios.txt";
Interface *Clube::iface = new Interface();

Clube::Clube(){
    readAll();
}

//#############################
//##          ADD            ##
//#############################
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

void Clube::CRUD(){
    while(1){
        iface->cleanScr();
        char command;
        iface->drawString("a. Manutencao\n");
        iface->drawString( "q. Sair(!)\n");
        iface->drawString( "   » ");
        iface->readChar(command);
        if(command == 'a') manutencao();
        else if(command == 'q'){
            iface->drawString( "Tem a certeza que deseja sair? (y/N)\n");
            iface->drawString( "   » ");
            iface->readChar(command);
            if(command == 'y'){
                iface->drawString( "Deseja gravar todas as alteracoes que efetuou? (Y/n)\n");
                iface->drawString( "   » ");
                iface->readChar(command);
                if(command != 'n'){
                    iface->drawString( "A gravar alteracoes...\n");
                    writeAll();
                    iface->drawString( "Alteracoes gravadas com sucesso, a sair...\n");
                    quit();
                    return;
                }
                iface->drawString( "A sair sem gravar alteracoes...\n");
                quit();
                return;
            }
            continue;
        }
    }
}

void Clube::manutencao(){
    while(1){
        iface->cleanScr();
        char command;
        iface->drawString("a. Manutencao Jogadores\n");
        iface->drawString("q. Voltar\n");
        iface->drawString("   » ");
        iface->readChar(command);
        if(command == 'a') manutencaoJogadores();
        else if(command == 'q') return;
    }
}

void Clube::listarPessoas(){
    iface->drawString("-------------------------------\n");
    iface->drawString("Listagem de todos os associados ao clube\n");
    iface->drawString("-------------------------------\n");
    iface->drawString("-------------------------------\n");
    listarExternos();
    iface->drawString("-------------------------------\n");
    listarJogadores();
    iface->drawString("-------------------------------\n");
    listarSocios();
    iface->drawString("-------------------------------\n");
    iface->newLine();
}

void Clube::listarExternos(){
    iface->drawString("Listagem de externos:\n");
    unsigned int counter = 0;
    for(unsigned int i = 0; i < externos.size(); i++){
        iface->drawString(externos[i]->getNome()); iface->drawString("    ");
        counter++;
        if(counter>3){ iface->newLine(); counter = 0;}
    }
    iface->newLine();
}

void Clube::listarJogadores(){
    iface->drawString("Listagem de jogadores\n");
    unsigned int counter = 0;
    for(unsigned int i = 0; i < jogadores.size(); i++){
        iface->drawString(jogadores[i]->getNome()); iface->drawString("    ");
        counter++;
        if(counter>3){ iface->newLine(); counter = 0;}
    }
    iface->newLine();
}

void Clube::listarSocios(){
    iface->drawString("Listagem de socios:\n");
    unsigned int counter = 0;
    for(unsigned int i = 0; i < socios.size(); i++){
        iface->drawString(socios[i]->getNome()); iface->drawString("    ");
        counter++;
        if(counter>3){ iface->newLine(); counter = 0;}
    }
    iface->newLine();
}

void Clube::listarModalidades(){
    for(unsigned int i = 0; i < modalidades.size(); i++){
        iface->drawString("» "); iface->drawString(modalidades[i]->getNome());
        iface->newLine();
        for(unsigned int k = 0; k < sub_modalidades.size(); k ++)
            if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome()){
                iface->drawString("   -"); iface->drawString(sub_modalidades[k]->getNome()); iface->newLine();
            }
    }
}

bool Clube::manutencaoJogadores(){
    while(1){
        iface->cleanScr();
        listarJogadores();
        iface->drawString("Escolha o jogador a gerir: ");
        string nome_input;
        iface->readLine(nome_input);
        if(nome_input == "q") return true;
        Jogador *j1 = NULL;
        for(unsigned int i = 0; i<jogadores.size(); i++){
            if(jogadores[i]->getNome() == nome_input) j1 = jogadores[i];
        }
        if(j1 != NULL) manutencaoJogador(j1);
        else {
            iface->drawString("Jogador nao existe!\n");
            continue;
        }
    }
    return false;
}

bool Clube::manutencaoJogador(Jogador *j1){
    while(1){
        iface->cleanScr();
        iface->drawString("Informacao do jogador:\n");
        iface->drawString(j1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar idade\n");
        iface->drawString("c. Mudar NIF\n");
        iface->drawString("d. Mudar sexo\n");
        iface->drawString("e. Associacao de (sub-)modalidades\n");
        iface->drawString("f. Remover jogador(!)\n");
        iface->drawString("q. Voltar...\n");
        iface->drawString("   » ");
        char command;
        iface->readChar(command);
        if(command == 'a'){
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if(j1->changeNome(nome)){
                iface->cleanScr();
                iface->drawString("\nNome foi mudado com sucesso\n\n");
                iface->getInput();
                continue;
            }
            else{
                iface->cleanScr();
                iface->drawString("\nOcorreu um erro...\n\n");
                iface->getInput();
                continue;
            }
        }
        if(command == 'b'){
            iface->drawString("Nova idade? ");
            unsigned int idade;
            iface->read(idade);
            if(j1->changeIdade(idade)){
                iface->cleanScr();
                iface->drawString("\nIdade foi mudada com sucesso\n\n");
                iface->getInput();
                continue;
            }
            else{
                iface->cleanScr();
                iface->drawString("\nOcorreu um erro...\n\n");
                iface->getInput();
                continue;
            }
        }
        if(command == 'c'){
            iface->drawString("Novo NIF? ");
            unsigned long NIF;
            iface->read(NIF);
            if(j1->changeNIF(NIF)){
                iface->cleanScr();
                iface->drawString("\nNIF foi mudado com sucesso\n\n");
                iface->getInput();
                continue;
            }
            else{
                iface->cleanScr();
                iface->drawString("\nOcorreu um erro...\n\n");
                iface->getInput();
                continue;
            }
        }
        else if(command == 'q'){
            return true;
        }
    }
    return false;
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
    iface->drawString("Unable to open file '"); iface->drawString(filename); iface->drawString("'"); iface->newLine();
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
    iface->drawString("Unable to open file '"); iface->drawString(filename); iface->drawString("'"); iface->newLine();
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
    iface->drawString("Unable to open file '"); iface->drawString(filename); iface->drawString("'"); iface->newLine();
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
    iface->drawString("Unable to open file '"); iface->drawString(filename); iface->drawString("'"); iface->newLine();
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
    iface->drawString("Unable to open file '"); iface->drawString(filename); iface->drawString("'"); iface->newLine();
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
    iface->drawString("Unable to open file '"); iface->drawString(filename); iface->drawString("'"); iface->newLine();
    return false;
}

bool Clube::readAll(){
    if(!readModalidades(FILE_MODALIDADES)) return false;
    if(!readJogadores(FILE_JOGADORES)) return false;
    if(!readSocios(FILE_SOCIOS)) return false;

    return true;
}

bool Clube::writeAll(){
    if(!writeModalidades(modalidades, FILE_MODALIDADES)) return false;
    if(!writeJogadores(jogadores, FILE_JOGADORES)) return false;
    if(!writeSocios(socios, FILE_SOCIOS)) return false;

    return true;
}

bool Clube::quit(){
    iface->drawString("\n\n\n*Press ANY KEY to exit...*\n");
    iface->getInput();
    delete iface;
    return true;
}
