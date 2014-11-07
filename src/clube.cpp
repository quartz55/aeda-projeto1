#include "clube.h"

#include <algorithm>

string Clube::FILE_JOGADORES = "../txt/jogadores.txt";
string Clube::FILE_MODALIDADES = "../txt/modalidades.txt";
string Clube::FILE_SOCIOS = "../txt/socios.txt";
string Clube::FILE_DATA = "../txt/data.txt";
string Clube::FILE_DESPESAS = "../txt/despesas.txt";
string Clube::FILE_EXTERNOS = "../txt/externos.txt";

Interface *Clube::iface = new Interface();

Clube::Clube(): dataActual(1,1,1900){
    if(!readAll()){
        iface->newLine();
        iface->drawString("Deseja continuar o programa(y/n)? ");
        char cont;
        iface->readChar(cont);
        if(cont == 'n') quit();
        else{
            update();
            main();
        }
    }
    else{
        update();
        main();
    }
}

//ADD/REMOVE/CHANGE FUNCTIONS
#include "./clube/basefunctions.h"
//#############################

//SORT FUNCTIONS
#include "./clube/sorts.h"
//#############################

//LISTING FUNCTIONS
#include "./clube/listagens.h"
//#############################

//READ AND WRITE OPERATIONS
#include "./clube/iooperations.h"
//#############################

void Clube::TopMenu(string name)
{
    iface->cleanScr();
    iface->drawString("\n\n\tGD FEUP\n");
    iface->drawString(dataActual.showData());
    iface->drawString("\n\n\n\t");
    iface->drawString(name);
    iface->drawString("\n\n");
}

void Clube::main()
{
    while (1){
        iface->cleanScr();
        char command;
        TopMenu("MENU PRINCIPAL");
        iface->drawString("a. Jogadores\n");
        iface->drawString("b. Socios\n");
        iface->drawString("c. Externos\n");
        iface->drawString("d. Modalidades e submodalidades\n");
        iface->drawString("e. Despesas\n");
        iface->drawString("f. Manutencao\n");
        iface->drawString("q. Sair(!)\n\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if (command == 'a'){
            if(jogadores.size() == 0){
                iface->drawString("\nO clube nao tem jogadores associados!\n");
                pressToContinue();
                continue;
            }
            while(infoJogadores());
        }
        else if (command == 'b'){
            if(socios.size() == 0){
                iface->drawString("\nO clube nao tem socios associados!\n");
                pressToContinue();
                continue;
            }
            while(infoSocios());
        }
        else if (command == 'c') {
            if (externos.size() == 0){
                iface->drawString("\nO clube nao tem externos associados!\n");
                pressToContinue();
                continue;
            }
            while(infoExternos());
        }
        else if (command == 'd'){
            if(modalidades.size() == 0){
                iface->drawString("\nO clube nao tem modalidades associados!\n");
                pressToContinue();
                continue;
            }
            while(1){
                string lista;
                if(!listarModalidades(lista)) break;
                iface->drawString(lista);
                pressToContinue();
            }
        }
        else if (command == 'e'){
            if (despesas.size() == 0){
                iface->drawString("\nO clube nao tem despesas associadas!\n");
                pressToContinue();
                continue;
            }
            while (1){
                string lista;
                if (!listarDespesas(lista)) break;
                iface->drawString(lista);
                pressToContinue();
            }
        }
        else if (command == 'f') manutencao();
        else if (command == 'q'){
            iface->drawString("Tem a certeza que deseja sair? (y/n)\n");
            iface->drawString("   > ");
            iface->readChar(command);
            if (command == 'y'){
                iface->drawString("Deseja gravar todas as alteracoes que efetuou? (y/n)\n");
                iface->drawString("   > ");
                iface->readChar(command);
                if (command != 'n'){
                    iface->drawString("A gravar alteracoes...\n");
                    writeAll();
                    iface->drawString("Alteracoes gravadas com sucesso, a sair...\n");
                    quit();
                    return;
                }
                iface->drawString("A sair sem gravar alteracoes...\n");
                quit();
                return;
            }
            continue;
        }
    }
}


bool Clube::infoExternos(){
    while(1){
        string lista;
        if(!listarExternos(lista))
            return false;
        while(1){
            iface->cleanScr();
            TopMenu("LISTAGEM DE EXTERNOS");
            iface->drawString(lista);
            iface->drawString("(q para sair)\n\n");
            iface->drawString("Escolha o externo para mostrar mais informacao: ");
            string nome_input;
            iface->readLine(nome_input);
            if(nome_input == "q") return true;
            Pessoa *p1 = NULL;
            for(unsigned int i = 0; i<externos.size(); i++){
                if(externos[i]->getNome() == nome_input) p1 = externos[i];
            }
            if(p1 != NULL){
                iface->cleanScr();
                TopMenu("INFO DE EXTERNO");
                iface->drawString(p1->showInfo());
                pressToContinue();
                continue;
            }
            else {
                iface->drawString("\n\nExterno nao existe!\n");
                pressToContinue();
                continue;
            }
        }
    }
    return false;
}
bool Clube::infoJogadores(){
    while(1){
        string lista;
        if(!listarJogadores(lista))
            return false;
        while(1){
            iface->cleanScr();
            TopMenu("LISTAGEM DE JOGADORES");
            iface->drawString(lista);
            iface->drawString("(q para sair)\n\n");
            iface->drawString("Escolha o jogador para mostrar mais informacao: ");
            string nome_input;
            iface->readLine(nome_input);
            if(nome_input == "q") return true;
            Jogador *j1 = NULL;
            for(unsigned int i = 0; i<jogadores.size(); i++){
                if(jogadores[i]->getNome() == nome_input) j1 = jogadores[i];
            }
            if(j1 != NULL){
                iface->cleanScr();
                TopMenu("INFO DE JOGADOR");
                iface->drawString(j1->showInfo());
                pressToContinue();
                continue;
            }
            else {
                iface->drawString("\n\nJogador nao existe!\n");
                pressToContinue();
                continue;
            }
        }
    }
    return false;
}
bool Clube::infoSocios(){
    while(1){
        string lista;
        if(!listarSocios(lista))
            return false;
        while(1){
            iface->cleanScr();
            TopMenu("LISTAGEM DE SOCIOS");
            iface->drawString(lista);
            iface->drawString("(q para sair)\n\n");
            iface->drawString("Escolha o socio para mostrar mais informacao: ");
            string nome_input;
            iface->readLine(nome_input);
            if(nome_input == "q") return true;
            Socio *s1 = NULL;
            for(unsigned int i = 0; i<socios.size(); i++){
                if(socios[i]->getNome() == nome_input) s1 = socios[i];
            }
            if(s1 != NULL){
                iface->cleanScr();
                TopMenu("INFO DE SOCIO");
                iface->drawString(s1->showInfo());
                pressToContinue();
                continue;
            }
            else {
                iface->drawString("\n\nSocio nao existe!\n");
                pressToContinue();
                continue;
            }
        }
    }
    return false;
}
void Clube::manutencao(){
    while(1){
        char command;
        TopMenu("MANUTENCAO");
        iface->drawString("a. Manutencao de jogadores\n");
        iface->drawString("b. Manutencao de socios\n");
        iface->drawString("c. Manutencao de externos\n");
        iface->drawString("d. Manutencao de modalidades\n");
        iface->drawString("e. Manutencao de despesas\n");
        iface->drawString("f. Alterar data\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        iface->readChar(command);
        if(command == 'a') while(manutencaoJogadores());
        else if (command == 'b') while(manutencaoSocios());
        else if (command == 'c') while (manutencaoExternos());
        else if (command == 'd') while (manutencaoModalidades());
        else if (command == 'e') while(manutencaoDespesas());
        else if (command == 'f') alterarData();
        else if(command == 'q') return;
    }
    return;
}


bool Clube::manutencaoSocios(){
    TopMenu("MANUTENCAO SOCIO");
    iface->drawString("a. Adicionar socio\n");
    iface->drawString("b. Alterar socio existente\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    char command;
    iface->readChar(command);
    if (command == 'a')
    {
        TopMenu("ADICIONAR SOCIO");;
        string nome, sexo;
        char sexo_c = ' ';
        iface->drawString("Nome: ");
        iface->readLine(nome);
        if (nome == "q") return true;
        while(sexo_c != 'm' && sexo_c != 'f' && sexo_c != 'q'){
            iface->drawString("Sexo(m/f)? ");
            iface->readChar(sexo_c);
        }
        if(sexo_c == 'm') sexo = "Macho";
        else if(sexo_c == 'f')sexo = "Femea";
        else if (sexo_c == 'q') return true;

        unsigned int idade, nif;
        iface->drawString("Idade: ");
        iface->read(idade);
        iface->drawString("NIF: ");
        iface->read(nif);
        Socio *s1 = new Socio(nome, idade, nif, sexo);
        try{
        	addSocio(s1);
        }
        catch(unsigned int NIF){
        	TopMenu("ADICIONAR SOCIO");
        	iface->drawString("\nErro!Esse socio ja existe (NIF ja existente)\n \n");
        	pressToContinue();
        	return false;
        }
        catch(std::string nome){
        	TopMenu("ADICIONAR SOCIO");
        	iface->drawString("\nErro!Esse socio ja existe (Nome ja existente)\n \n");
        	pressToContinue();
        	return false;
        }
        TopMenu("ADICIONAR SOCIO");
        iface->drawString(s1->showInfo());
        iface->drawString("\nO socio foi criado");
        pressToContinue();
        return true;
    }
    else if (command == 'b'){
        TopMenu("ALTERAR SOCIO");
        if (socios.size() == 0){
            iface->drawString("O clube nao tem socios associados!\n");
            pressToContinue();
            return true;
        }
        string lista;
        while(1){
            if (!listarSocios(lista))
                return true;

            while (1){
                iface->cleanScr();
                TopMenu("LISTAGEM DE SOCIOS");
                iface->drawString(lista);
                iface->drawString("\nq. Voltar\n\n");
                iface->drawString("Escolha o socio a gerir: ");
                string nome_input;
                iface->readLine(nome_input);
                if (nome_input == "q") break;
                Socio *s1 = NULL;
                for (unsigned int i = 0; i < socios.size(); i++){
                    if (socios[i]->getNome() == nome_input) s1 = socios[i];
                }
                if (s1 != NULL){
                    if(manutencaoSocio(s1))
                        break;
                    continue;
                }
                else {
                    iface->drawString("\nSocio nao existe!\n");
                    pressToContinue();
                    continue;
                }
            }
        }
        return false;
    }
    else if (command == 'q')
        return false;
    return true;
}

bool Clube::manutencaoSocio(Socio *s1){
    bool alterado = false;
    while (1){
        TopMenu("INFORMACAO DO SOCIO");
        iface->drawString(s1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar idade\n");
        iface->drawString("c. Mudar NIF\n");
        iface->drawString("d. Mudar sexo\n");
        iface->drawString("e. Associacao de modalidades\n");
        iface->drawString("f. Remover modalidades\n");
        iface->drawString("g. Pagar quotas\n");
        iface->drawString("h. Remover socio(!)\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        char command;
        iface->readChar(command);
        if (command == 'a'){
            TopMenu("ALTERAR SOCIO");
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if (s1->changeNome(nome)){
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nNome foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'b'){
            TopMenu("ALTERAR SOCIO");
            iface->drawString("Nova idade? ");
            unsigned int idade;
            iface->read(idade);
            if (s1->changeIdade(idade)){
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nIdade foi mudada com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'c'){
            TopMenu("ALTERAR SOCIO");
            iface->drawString("Novo NIF? ");
            unsigned long NIF;
            iface->read(NIF);
            if (s1->changeNIF(NIF)){
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nNIF foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'd'){
            TopMenu("ALTERAR SOCIO");
            string sexo;
            char sexo_c = ' ';
            while(sexo_c != 'm' && sexo_c != 'f' && sexo_c != 'q'){
                iface->drawString("Novo sexo(m/f)? ");
                iface->readChar(sexo_c);
            }
            if(sexo_c == 'm') sexo = "Macho";
            else if(sexo_c == 'f') sexo = "Femea";
            else if (sexo_c == 'q') return true;

            if (s1->changeSexo(sexo)){
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nSexo foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'e'){
            TopMenu("INFORMACAO DO SOCIO");
            string lista;
            listarModalidades(lista);
            iface->drawString(lista);
            iface->drawString("Escolha a modalidade a associar: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") continue;
            if(s1->QuotasAtrasadas(dataActual, NULL) == 0){
                for(size_t i = 0; i < modalidades.size(); i++){
                    if(modalidades[i]->getNome() == nome_input){
                        s1->addModalidade(modalidades[i], dataActual.getMonth(),dataActual.getYear());
                        break;
                    }
                }
            }
            else{
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("Nao se pode associar a uma nova modalidade com quotas em atraso\n");
                pressToContinue();
                continue;
            }
            iface->drawString("\nModalidade associada com sucesso\n\n");
            alterado = true;
            pressToContinue();
            continue;
        }
        if (command == 'f'){
            TopMenu("INFORMACAO DO SOCIO");
            s1->showModalidades();
            iface->drawString("Escolha a modalidade a remover: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") continue;;
            for(size_t i = 0; i < modalidades.size(); i++){
                if(modalidades[i]->getNome() == nome_input){
                    s1->removeModalidade(modalidades[i]);
                    s1->removeQuota(modalidades[i]);
                    break;
                }
            }
            iface->drawString("\nModalidade desassociada com sucesso\n\n");
            alterado = true;
            pressToContinue();
            continue;
        }
        if (command == 'g'){
            TopMenu("INFORMACAO DO SOCIO");
            iface->drawString("Escolha a modalidade: \n\n");
            iface->drawString(s1->showModalidades());
            iface->drawString("\n\n   > ");
            string nome_input;
            iface->readLine(nome_input);
            Modalidade * mod = NULL;
            for(size_t i = 0;i < modalidades.size(); i++){
            	if(modalidades[i]->getNome() == nome_input)
            		mod = modalidades[i];
            }
            if(mod != NULL){
            	iface->drawString("O socio tem ");
            	iface->drawString(s1->QuotasAtrasadas(dataActual, mod));
            	iface->drawString(" meses de quotas em atraso \n \n \n");
            	iface->drawString("Quantos meses deseja pagar? (q para sair)\n\n");
            	iface->drawString("   > ");
            	iface->readLine(nome_input);
            	int meses;
            	std::stringstream ss;
            	ss << nome_input;
            	ss >> meses;
            	if (nome_input == "q") continue;;
            	while(1){
            		TopMenu("INFORMACAO DO SOCIO");
            		iface->drawString("Valor total a pagar: ");
            		iface->drawString(s1->pagarQuotas(meses, dataActual, false, mod));
            		iface->drawString("\n\n Confirmar pagamento? (y/n)\n\n");
            		iface->drawString("   > ");
            		char command;
            		iface->readChar(command);
            		if (command == 'y') {
            			s1->pagarQuotas(meses, dataActual, true, mod);
            			iface->drawString("\n\nQuotas pagas com sucesso\n\n");
            			alterado = true;
            			break;
            		}
            		else if(command == 'n'){
            			iface->drawString("\n\nOperacao cancelada\n\n");
            			pressToContinue();
            			break;
            		}
            	}
            }
            else{
            	TopMenu("INFORMACAO DO SOCIO");
            	iface->drawString("\n\nOperacao cancelada (nome invalido para modalidade)\n\n");
            	pressToContinue();
            }
        }
        if (command == 'h'){
            TopMenu("ALTERAR SOCIO");
            for (size_t i = 0; i < socios.size(); i++)
            {
                if (socios[i] == s1)
                    socios.erase(socios.begin() + i);
            }
            iface->drawString("\nSocio removido com sucesso\n\n");
            pressToContinue();
            return true;
        }
        else if (command == 'q'){
            return alterado;
        }
    }
    return false;
}

bool Clube::manutencaoDespesas() {
    TopMenu("MANUTENCAO DE DESPESAS");
    iface->drawString("a. Adicionar despesa\n");
    iface->drawString("b. Alterar despesa existente\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    char command;
    iface->readChar(command);
    if (command == 'a')
    {
        TopMenu("ADICIONAR DESPESA");
        string nome;
        iface->drawString("Info: ");
        iface->readLine(nome);
        if (nome == "q") return true;
        float valor;
        iface->drawString("Valor: ");
        iface->read(valor);
        if (valor < 0){
            iface->drawString("\n \nO valor não pode ser negativo\n \n");
            pressToContinue();
            return true;
        }
        iface->drawString("Dia? ");
        unsigned int dia;
        iface->read(dia);
        iface->drawString("Mes (inteiro equivalente)? ");
        unsigned int mes;
        iface->read(mes);
        iface->drawString("Ano ? ");
        unsigned int ano;
        iface->read(ano);
        Despesa * despesa = new Despesa(dia, mes, ano, valor, nome);
        if (addDespesa(despesa))
        {
            TopMenu("ADICIONAR DESPESA");
            iface->drawString(despesa->showInfo());
            iface->drawString("\nA despesa foi criada");
            pressToContinue();
        }
        else
        {
            TopMenu("ADICIONAR DESPESA");
            iface->drawString(despesa->showInfo());
            iface->drawString("\nErro! A despesa já existe");
            pressToContinue();
        }
        return true;

    }
    else if (command == 'b'){
        string lista;
        while (1){
            if (!listarDespesas(lista))
                return false;
            while(1){
                iface->cleanScr();
                TopMenu("LISTAGEM DE DESPESAS");
                iface->drawString(lista);
                iface->drawString("\nq. Voltar\n\n");
                iface->drawString("Escolha a despesa a gerir: ");
                string nome_input;
                iface->readLine(nome_input);
                if (nome_input == "q") break;
                Despesa *d1 = NULL;
                for (unsigned int i = 0; i < despesas.size(); i++){
                    if (despesas[i]->getInfo() == nome_input) d1 = despesas[i];
                }
                if (d1 != NULL){
                    if(manutencaoDespesa(d1))
                        break;
                    continue;
                }
                else {
                    iface->drawString("\nEssa despesa nao existe!\n");
                    pressToContinue();
                    continue;
                }
            }
        }
        return false;
    }
    else if (command == 'q'){
        return false;
    }
    return false;
}

bool Clube::manutencaoDespesa(Despesa* d1) {
    bool alterado = false;
    while(1){
        TopMenu("ALTERAR DESPESA");
        iface->drawString(d1->showInfo());
        iface->drawString("\n\na. Mudar info\n");
        iface->drawString("b. Mudar valor\n");
        iface->drawString("c. Mudar data\n");
        iface->drawString("d. Remover despesa(!)\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        char command;
        iface->readChar(command);
        if(command == 'a'){
            TopMenu("ALTERAR DESPESA");
            iface->drawString("Nova info? ");
            string nome;
            iface->readLine(nome);
            if(d1->setInfo(nome)){
                TopMenu("ALTERAR DESPESA");
                iface->drawString("\n Info foi mudada com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR DESPESA");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if(command == 'b'){
            TopMenu("ALTERAR DESPESA");
            iface->drawString("Novo valor? ");
            float valor;
            iface->read(valor);
            if(d1->setValor(valor)){
                TopMenu("ALTERAR DESPESA");
                iface->drawString("\nValor foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR DESPESA");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if(command == 'c'){
            TopMenu("ALTERAR DESPESA");
            iface->drawString("\nNovo Dia? ");
            unsigned int dia;
            iface->read(dia);
            iface->drawString("Novo Mes (inteiro equivalente)? ");
            unsigned int mes;
            iface->read(mes);
            iface->drawString("Novo Ano ? ");
            unsigned int ano;
            iface->read(ano);
            Data * data = new Data(dia, mes, ano);
            if(d1->setData(data)){
                TopMenu("ALTERAR DESPESA");
                iface->drawString("\nData alterada com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR DESPESA");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'd'){
            for (unsigned int i = 0; i< despesas.size(); i++){
                if (despesas[i] == d1)
                {
                    despesas.erase(despesas.begin() + i);
                }
            }
            TopMenu("ALTERAR DESPESA");
            iface->drawString("\nDespesa removida\n\n");
            pressToContinue();
            return true;
        }
        else if(command == 'q'){
            return alterado;
        }
    }
    return false;

}


bool Clube::manutencaoExternos(){
    TopMenu("MANUTENCAO EXTERNOS");
    iface->drawString("a. Adicionar externo\n");
    iface->drawString("b. Alterar externo existente\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    char command;
    iface->readChar(command);
    if (command == 'a')
    {
        TopMenu("ADICIONAR EXTERNO");
        string nome, sexo;
        char sexo_c = ' ';
        iface->drawString("Nome: ");
        iface->readLine(nome);
        if (nome == "q") return true;
        while(sexo_c != 'm' && sexo_c != 'f' && sexo_c != 'q'){
            iface->drawString("Novo sexo(m/f)? ");
            iface->readChar(sexo_c);
        }
        if(sexo_c == 'm') sexo = "Macho";
        else if(sexo_c == 'f') sexo = "Femea";
        else if (sexo_c == 'q') return true;

        unsigned int idade, nif;
        iface->drawString("Idade: ");
        iface->read(idade);
        iface->drawString("NIF: ");
        iface->read(nif);
        Pessoa *p1 = new Pessoa(nome, idade, nif, sexo);
        p1->setExterno();
        try{
        	addExterno(p1);
        }
        catch(unsigned int NIF){
        	TopMenu("ADICIONAR EXTERNO");
        	iface->drawString("\nErro!Esse externo ja existe (NIF ja existente)\n \n");
        	pressToContinue();
        	return false;
        }
        catch(std::string nome){
        	TopMenu("ADICIONAR EXTERNO");
        	iface->drawString("\nErro!Esse externo ja existe (Nome ja existente)\n \n");
        	pressToContinue();
        	return false;
        }
        TopMenu("ADICIONAR EXTERNO");
        iface->drawString(p1->showInfo());
        iface->drawString("\nO externo foi criado");
        pressToContinue();
        return true;

    }
    else if (command == 'b') {
        if (externos.size() == 0){
            iface->drawString("\n\nO clube nao tem externos associados!\n");
            pressToContinue();
            return true;
        }
        string lista;
        while(1){
            if (!listarExternos(lista))
                return true;
            while (1){
                iface->cleanScr();
                TopMenu("LISTAGEM DE EXTERNOS");
                iface->drawString(lista);
                iface->drawString("\nq. Voltar\n\n");
                iface->drawString("Escolha o externo a gerir: ");
                string nome_input;
                iface->readLine(nome_input);
                if (nome_input == "q") return true;
                Pessoa *p1 = NULL;
                for (unsigned int i = 0; i < externos.size(); i++){
                    if (externos[i]->getNome() == nome_input) p1 = externos[i];
                }
                if (p1 != NULL){
                    if(manutencaoExterno(p1))
                        break;
                    continue;
                }
                else {
                    iface->drawString("\nExterno nao existe!\n");
                    pressToContinue();
                    continue;
                }
            }
        }
        return false;
    }
    else if (command == 'q')
        return false;
    return false;
}
bool Clube::manutencaoExterno(Pessoa * p1){
    bool alterado = false;
    while (1){
        TopMenu("ALTERAR EXTERNO");
        iface->drawString(p1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar idade\n");
        iface->drawString("c. Mudar NIF\n");
        iface->drawString("d. Mudar sexo\n");
        iface->drawString("e. Remover externo(!)\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        char command;
        iface->readChar(command);
        if (command == 'a'){
            TopMenu("ALTERAR EXTERNO");
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if (p1->changeNome(nome)){
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nNome foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'b'){
            TopMenu("ALTERAR EXTERNO");
            iface->drawString("Nova idade? ");
            unsigned int idade;
            iface->read(idade);
            if (p1->changeIdade(idade)){
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nIdade foi mudada com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'c'){
            TopMenu("ALTERAR EXTERNO");
            iface->drawString("Novo NIF? ");
            unsigned long NIF;
            iface->read(NIF);
            if (p1->changeNIF(NIF)){
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nNIF foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'd'){
            TopMenu("ALTERAR EXTERNO");
            string sexo;
            char sexo_c = ' ';
            while(sexo_c != 'm' && sexo_c != 'f' && sexo_c != 'q'){
                iface->drawString("Novo sexo(m/f)? ");
                iface->readChar(sexo_c);
            }
            if(sexo_c == 'm') sexo = "Macho";
            else if(sexo_c == 'q') sexo = "Femea";
            else if (sexo_c == 'q') continue;

            if (p1->changeSexo(sexo)){
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nSexo foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        if (command == 'e'){
            for (size_t i = 0; i < externos.size(); i++)
            {
                if (externos[i] == p1)
                    externos.erase(externos.begin() + i);
            }
            TopMenu("ALTERAR EXTERNO");
            iface->drawString("\nExterno removido com sucesso\n\n");
            pressToContinue();
            return true;
        }
        else if (command == 'q'){
            return alterado;
        }
    }
    return false;
}


bool Clube::manutencaoJogadores(){
    TopMenu("MANUTENCAO JOGADORES");
    iface->drawString("a. Adicionar jogador\n");
    iface->drawString("b. Alterar jogador existente\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    char command;
    iface->readChar(command);
    if (command == 'a')
    {
        TopMenu("ADICIONAR JOGADOR");
        string nome, sexo;
        char sexo_c = ' ';
        iface->drawString("Nome: ");
        iface->readLine(nome);
        if (nome == "q") return true;
        while(sexo_c != 'm' && sexo_c != 'f' && sexo_c != 'q'){
            iface->drawString("Sexo(m/f): ");
            iface->readChar(sexo_c);
        }
        if(sexo_c == 'm') sexo = "Macho";
        else if(sexo_c == 'f')sexo = "Femea";
        else if (sexo_c == 'q') return true;

        unsigned int idade, nif;
        iface->drawString("Idade: ");
        iface->read(idade);
        iface->drawString("NIF: ");
        iface->read(nif);
        Jogador *j1 = new Jogador(nome, idade, nif, sexo);
        try{
        	addJogador(j1);
        }
        catch(unsigned int NIF){
        	TopMenu("ADICIONAR JOGADOR");
        	iface->drawString("\nErro!Esse jogador ja existe (NIF ja existente)\n \n");
        	pressToContinue();
        	return false;
        }
        catch(std::string nome){
        	TopMenu("ADICIONAR JOGADOR");
        	iface->drawString("\nErro!Esse jogador ja existe (Nome ja existente)\n \n");
        	pressToContinue();
        	return false;
        }
        TopMenu("ADICIONAR JOGADOR");
        iface->drawString(j1->showInfo());
        iface->drawString("\nO jogador foi criado");
        pressToContinue();
    }
    else if (command == 'b') {
        string lista;
        TopMenu("ALTERAR JOGADOR");
        if (jogadores.size() == 0){
            iface->drawString("O clube nao tem jogadores associados!\n");
            pressToContinue();
            return true;
        }
        while(1){
            if (!listarJogadores(lista))
                return true;
            while (1){
                iface->cleanScr();
                TopMenu("LISTAGEM DE JOGADORES");
                iface->drawString(lista);
                iface->drawString("\nq. Voltar\n\n");
                iface->drawString("Escolha o jogador a gerir: ");
                string nome_input;
                iface->readLine(nome_input);
                if (nome_input == "q") break;
                Jogador *j1 = NULL;
                for (unsigned int i = 0; i < jogadores.size(); i++){
                    if (jogadores[i]->getNome() == nome_input) j1 = jogadores[i];
                }
                if (j1 != NULL){
                    if(manutencaoJogador(j1))
                        break;
                    continue;
                }
                else {
                    iface->drawString("Jogador nao existe!\n");
                    pressToContinue();
                    continue;
                }
            }
        }
        return false;
    }
    else if (command == 'q')
        return false;
    return true;
}


bool Clube::manutencaoJogador(Jogador *j1){
    bool alterado = false;
    while(1){
        TopMenu("ALTERAR JOGADOR");
        iface->drawString(j1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar idade\n");
        iface->drawString("c. Mudar NIF\n");
        iface->drawString("d. Mudar sexo\n");
        iface->drawString("e. Associacao de Modalidades\n");
        iface->drawString("f. Associacao de sub-modalidades\n");
        iface->drawString("g. Remover Modalidades\n");
        iface->drawString("h. Remover sub-modalidades\n");
        iface->drawString("i. Remover jogador(!)\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString("   > ");
        char command;
        iface->readChar(command);
        if(command == 'a'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if(j1->changeNome(nome)){
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nNome foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        else if(command == 'b'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Nova idade? ");
            unsigned int idade;
            iface->read(idade);
            if(j1->changeIdade(idade)){
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nIdade foi mudada com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        else if(command == 'c'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Novo NIF? ");
            unsigned long NIF;
            iface->read(NIF);
            if(j1->changeNIF(NIF)){
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nNIF foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'd'){
            TopMenu("ALTERAR JOGADOR");
            string sexo;
            char sexo_c = ' ';
            while(sexo_c != 'm' && sexo_c != 'f' && sexo_c != 'q'){
                iface->drawString("Novo sexo(m/f)? ");
                iface->readChar(sexo_c);
            }
            if(sexo_c == 'm') sexo = "Macho";
            else if(sexo_c == 'f') sexo = "Femea";
            else if (sexo_c == 'q') continue;
            if (j1->changeSexo(sexo)){
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nSexo foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'e'){
            string lista;
            listarModalidades(lista);
            iface->drawString(lista);
            iface->drawString("Nova modalidade? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") continue;
            Modalidade *m1 = NULL;
            for (unsigned int i = 0; i < modalidades.size(); i++){
                if (modalidades[i]->getNome() == nome) m1 = modalidades[i];
            }
            if (j1->addModalidade(m1))
            {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("A modalidade foi adicionada ao jogador");
                alterado = true;
                pressToContinue();
                continue;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A modalidade não existe");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'f'){
            string lista;
            listarModalidades(lista);
            iface->drawString(lista);
            iface->drawString("Nova submodalidade? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") continue;
            SubModalidade *s1 = NULL;
            for (unsigned int i = 0; i < sub_modalidades.size(); i++){
                if (sub_modalidades[i]->getNome() == nome) s1 = sub_modalidades[i];
            }
            if (j1->addSubModalidade(s1))
            {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("A submodalidade foi adicionada ao jogador");
                alterado = true;
                pressToContinue();
                continue;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A submodalidade não existe");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'g'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString(j1->showModalidades());
            iface->drawString("\nModalidade a remover do jogador? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") continue;
            Modalidade *m1 = NULL;
            for (unsigned int i = 0; i < modalidades.size(); i++){
                if (modalidades[i]->getNome() == nome)
                {
                    m1 = modalidades[i];
                    break;
                }
            }
            if (j1->removeModalidade(m1))
            {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("A modalidade foi removida do jogador");
                alterado = true;
                pressToContinue();
                continue;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A modalidade não existe");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'h'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString(j1->showSubModalidades());
            iface->drawString("\nSubmodalidade a remover do jogador? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") continue;
            SubModalidade *s1 = NULL;
            for (unsigned int i = 0; i < sub_modalidades.size(); i++){
                if (sub_modalidades[i]->getNome() == nome)
                {
                    s1 = sub_modalidades[i];
                    break;
                }
            }
            if (j1->removeSubModalidade(s1))
            {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("A submodalidade foi removida do jogador");
                alterado = true;
                pressToContinue();
                continue;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A submodalidade não existe");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'i'){
            for (size_t i = 0; i < jogadores.size(); i++)
            {
                if (jogadores[i] == j1)
                    jogadores.erase(jogadores.begin() + i);
            }
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("\nJogador removido com sucesso\n\n");
            pressToContinue();
            return true;
        }
        else if(command == 'q'){
            return alterado;
        }
    }
    return false;
}

bool Clube::manutencaoModalidades(){
    TopMenu("MANUTENCAO MODALIDADES");
    iface->drawString("a. Adicionar modalidade\n");
    iface->drawString("b. Alterar modalidade existente\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    char command;
    iface->readChar(command);
    if (command == 'a')
    {
        TopMenu("ADICIONAR MODALIDADE");
        string nome;
        iface->drawString("Nome: ");
        iface->readLine(nome);
        if (nome == "q") return true;
        Modalidade *m1 = new Modalidade(nome);
        iface->drawString("Preco da quota: ");
        float preco;
        iface->read(preco);
        m1->setPrecoQuota(preco);
        try{
        	addModalidade(m1);
        }
        catch(std::string nome){
        	TopMenu("ADICIONAR MODALIDADE");
        	iface->drawString(m1->showInfo());
        	iface->drawString("\nA modalidade já existe ou uma com o mesmo nome)");
        	pressToContinue();
        }
        TopMenu("ADICIONAR MODALIDADE");
        iface->drawString(m1->showInfo());
        iface->drawString("\nA modalidade foi criada");
        pressToContinue();
        return true;

    }
    else if (command == 'b') {
        string lista;
        TopMenu("ALTERAR MODALIDADE");
        if (modalidades.size() == 0){
            iface->drawString("O clube nao tem modalidades associadas!\n");
            pressToContinue();
            return true;
        }
        while(1){
            if (!listarModalidades(lista))
                return true;
            while (1){
                iface->cleanScr();
                TopMenu("LISTAGEM DE MODALIDADES");
                iface->drawString(lista);
                iface->drawString("(q para sair)\n\n");
                iface->drawString("Escolha a modalidade a gerir: ");
                string nome_input;
                iface->readLine(nome_input);
                if (nome_input == "q") break;
                Modalidade *m1 = NULL;
                for (unsigned int i = 0; i < modalidades.size(); i++){
                    if (modalidades[i]->getNome() == nome_input) m1 = modalidades[i];
                }
                if (m1 != NULL){
                    if(manutencaoModalidade(m1))
                        break;
                    continue;
                }
                else {
                    iface->drawString("Modalidade nao existe!\n");
                    pressToContinue();
                    continue;
                }
            }
        }
        return false;
    }
    else if (command == 'q')
        return false;
    return true;
}


bool Clube::manutencaoModalidade(Modalidade * m1){
    bool alterado = false;
    while (1){
        TopMenu("ALTERAR MODALIDADE");
        iface->drawString(m1->showInfo());
        std::stringstream s;
        for (unsigned int k = 0; k < sub_modalidades.size(); k++)
            if (sub_modalidades[k]->getMod()->getNome() == m1->getNome())
                s << "   -" << sub_modalidades[k]->getNome() << std::endl;
        iface->drawString(s.str());
        iface->drawString("\n\nPreco Quota: ");
        float *p = m1->getPrecoQuota();
        iface->drawString(*p);
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar preco de quota\n");
        iface->drawString("c. Criar submodalidade\n");
        iface->drawString("d. Alterar submodalidade\n");
        iface->drawString("e. Remover modalidade(!)\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString(" > ");
        char command;
        iface->readChar(command);
        if (command == 'a'){
            TopMenu("ALTERAR MODALIDADE");
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if (m1->changeNome(nome)){
                TopMenu("ALTERAR MODALIDADE");
                iface->drawString("\nNome foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR MODALIDADE");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'b'){
            TopMenu("ALTERAR MODALIDADE");
            iface->drawString("Novo preco? ");
            float preco;
            iface->read(preco);
            if (m1->setPrecoQuota(preco)){
                TopMenu("ALTERAR MODALIDADE");
                iface->drawString("\nPreco foi mudado com sucesso\n\n");
                alterado = true;
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR MODALIDADE");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }
        else if (command == 'c'){
            TopMenu("NOVA SUBMODALIDADE");
            iface->drawString("\nNome? ");
            string nome;
            iface->read(nome);
            SubModalidade *s1 = new SubModalidade(nome, m1);
            sub_modalidades.push_back(s1);
            iface->drawString("\n\nSubmodalidade criada com sucesso\n");
            update();
            alterado = true;
            pressToContinue();
            continue;
        }
        else if (command == 'd'){
            manutencaoSubModalidade(m1);
            alterado = true;
            continue;
        }
        else if (command == 'e'){
            TopMenu("ALTERAR MODALIDADE");
            for (size_t i = 0; i < modalidades.size(); i++)
            {
                if (modalidades[i] == m1)
                    modalidades.erase(modalidades.begin() + i);
            }
            for (size_t i = 0; i < jogadores.size(); i++)
            {
                jogadores[i]->removeModalidade(m1);
            }
            for (size_t i = 0; i < socios.size(); i++)
            {
                socios[i]->removeModalidade(m1);
                socios[i]->removeQuota(m1);
            }
            iface->drawString("Modalidade removida com sucesso\n");
            pressToContinue();
            return true;
        }
        else if (command == 'q'){
            return alterado;
        }
    }
    return false;
}


bool Clube::manutencaoSubModalidade(Modalidade * m1){
    if (m1->getNumSubs() == 0){
        iface->drawString("A modalidade nao tem submodalidades associadas!\n");
        pressToContinue();
        return false;
    }
    else
    {
        TopMenu("ALTERAR SUBMODALIDADE");
        iface->drawString(" - ");
        iface->drawString(m1->getNome());
        iface->newLine();
        for (unsigned int k = 0; k < sub_modalidades.size(); k++){
            if (sub_modalidades[k]->getMod()->getNome() == m1->getNome()){
                iface->drawString("   > ");
                iface->drawString(sub_modalidades[k]->getNome());
                iface->newLine();
            }
        }
    }
    iface->drawString("\nq. Voltar\n\n");
    while (1){
        iface->drawString("Escolha a submodalidade a gerir: ");
        string nome_input;
        iface->readLine(nome_input);
        if (nome_input == "q") return true;
        SubModalidade *sm1 = NULL;
        for (unsigned int i = 0; i < sub_modalidades.size(); i++){
            if (sub_modalidades[i]->getNome() == nome_input) sm1 = sub_modalidades[i];
        }
        if (sm1 != NULL){
            manutencaoSubModalidade(sm1);
            return true;
        }
        else {
            iface->drawString("\nModalidade nao existe!\n");
            pressToContinue();
            return false;
        }
    }
    return false;
}


bool Clube::manutencaoSubModalidade(SubModalidade * sm1)
{
    while (1){
        TopMenu("ALTERAR SUBMODALIDADE");
        iface->drawString(sm1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Remover submodalidade(!)\n");
        iface->drawString("q. Voltar\n\n");
        iface->drawString(" > ");
        char command;
        iface->readChar(command);
        if (command == 'a'){
            TopMenu("ALTERAR SUBMODALIDADE");
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if (sm1->changeNome(nome)){
                TopMenu("ALTERAR SUBMODALIDADE");
                iface->drawString("\nNome foi mudado com sucesso\n\n");
                pressToContinue();
                continue;
            }
            else{
                TopMenu("ALTERAR SUBMODALIDADE");
                iface->drawString("\nOcorreu um erro...\n\n");
                pressToContinue();
                continue;
            }
        }

        else if (command == 'b'){
            TopMenu("ALTERAR SUBMODALIDADE");
            for (size_t i = 0; i < sub_modalidades.size(); i++)
            {
                if (sub_modalidades[i] == sm1)
                    sub_modalidades.erase(sub_modalidades.begin() + i);
            }
            for (size_t i = 0; i < jogadores.size(); i++)
            {
                jogadores[i]->removeSubModalidade(sm1);
            }
            for (size_t i = 0; i < socios.size(); i++)
            {
                socios[i]->removeSubModalidade(sm1);
            }
            iface->drawString("Submodalidade removida com sucesso\n");
            update();
            pressToContinue();
            return true;
        }
        else if (command == 'q'){
            return true;
        }
    }
    return false;
}


void Clube::update(){
    unsigned int m1 = 0;
    for(unsigned int k = 0; k < modalidades.size(); k++){
        for(unsigned int i = 0; i < sub_modalidades.size(); i++){
            if(sub_modalidades[i]->getMod() == modalidades[k]) m1++;
        }
        modalidades[k]->setNumSubs(m1);
        m1=0;
    }
}
void Clube::alterarData(){
    TopMenu("ALTERAR DATA");
    iface->drawString("a. Avancar uma semana\n");
    iface->drawString("b. Avancar um mes\n");
    iface->drawString("c. Avancar um ano\n");
    iface->drawString("d. Escolher data manualmente\n");
    iface->drawString("q. Voltar\n\n");
    iface->drawString("   > ");
    char command;
    iface->readChar(command);
    if (command == 'a') {
        TopMenu("ALTERAR DATA");
        dataActual.addDays(7);
        iface->drawString("\n \nData alterada para ");
        iface->drawString(dataActual.showData());
        pressToContinue();
        return;
    }
    else if (command == 'b') {
        TopMenu("ALTERAR DATA");
        dataActual.addMonths(1);
        iface->drawString("\n \nData alterada para ");
        iface->drawString(dataActual.showData());
        pressToContinue();
        return;
    }
    else if (command == 'c') {
        TopMenu("ALTERAR DATA");
        dataActual.addYears(1);
        iface->drawString("\n \nData alterada para ");
        iface->drawString(dataActual.showData());
        pressToContinue();
        return;
    }
    else if (command == 'd')
    {
        TopMenu("ALTERAR DATA");
        iface->drawString("\nNovo Dia? ");
        unsigned int dia;
        iface->read(dia);
        if (dia < 1 || dia > 31){
            iface->drawString("Erro, dia invalido!");
            pressToContinue();
            return;
        }
        iface->drawString("Novo Mes (inteiro equivalente)? ");
        unsigned int mes;
        iface->read(mes);
        if (mes < 1 || mes > 12){
            iface->drawString("Erro, mes invalido!");
            pressToContinue();
            return;
        }
        iface->drawString("Novo Ano ? ");
        unsigned int ano;
        iface->read(ano);
        Data data = Data(dia, mes, ano);
        TopMenu("ALTERAR DATA");
        iface->drawString("Alterar data atual de ");
        iface->drawString(dataActual.showData());
        iface->drawString(" para ");
        iface->drawString(data.showData());
        iface->drawString("? (y/n)\n\n");
        iface->drawString("   > ");
        char command;
        iface->readChar(command);
        if (command == 'y')
        {
            dataActual.setData(dia, mes, ano);
            TopMenu("ALTERAR DATA");
            iface->drawString("\nData alterada com sucesso\n\n");
            pressToContinue();
        }
        else
        {
            TopMenu("ALTERAR DATA");
            iface->drawString("\nOperacao cancelada\n\n");
            pressToContinue();
        }

        return;
    }
    else if (command == 'q')
        return;
}
void Clube::pressToContinue(){
    iface->drawString("\n\n* Carregue numa tecla para voltar... *\n");
    iface->getInput();
}

bool Clube::quit(){
    iface->drawString("\n\n\n* Carregue numa tecla para sair... *\n");
    iface->getInput();
    iface->cleanScr();
    delete iface;
    return true;
}
