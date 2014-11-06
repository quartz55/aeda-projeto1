#include "clube.h"

#include <algorithm>

string Clube::FILE_JOGADORES = "../txt/jogadores.txt";
string Clube::FILE_MODALIDADES = "../txt/modalidades.txt";
string Clube::FILE_SOCIOS = "../txt/socios.txt";
string Clube::FILE_DATA = "../txt/data.txt";
string Clube::FILE_DESPESAS = "../txt/despesas.txt";

Interface *Clube::iface = new Interface();

Clube::Clube(): dataActual(1,1,1900){
    readAll();
    update();
}

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
	iface->drawString("\n \n\tGD FEUP\n");
	iface->drawString(dataActual.showData());
	iface->drawString("\n\n\n");
	iface->drawString(name);
	iface->drawString("\n\n");
}

void Clube::main()
{
	while (1){
		iface->cleanScr();
		char command;
		iface->drawString("\n \n\tGD FEUP\n");
		iface->drawString(dataActual.showData());
		iface->drawString("\n\n\n\tMENU\n\n");
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
            while(infoPessoal());
        }
        else if (command == 'b'){
            if(socios.size() == 0){
                iface->drawString("\nO clube nao tem socios associados!\n");
				pressToContinue();
                continue;
            }
            while(1){
                if(!infoSocios()) break;
				pressToContinue();
            }
        }
		else if (command == 'c') {
			if (externos.size() == 0){
				iface->drawString("\nO clube nao tem externos associados!\n");
				pressToContinue();
				continue;
			}
			while (1){
				if (!listarExternos()) break;
				pressToContinue();
			}
		}
        else if (command == 'd'){
            if(modalidades.size() == 0){
                iface->drawString("\nO clube nao tem modalidades associados!\n");
				pressToContinue();
                continue;
            }
            while(1){
                if(!listarModalidades()) break;
				pressToContinue();
            }
        }
		if (command == 'e'){
			if (despesas.size() == 0){
				iface->drawString("\nO clube nao tem despesas associadas!\n");
				pressToContinue();
				continue;
			}
			while (1){
				if (!listarDespesas()) break;
				pressToContinue();
			}
		}
        if (command == 'f') manutencao();
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

bool Clube::addDespesa(Despesa* d) {
    for(unsigned int i = 0; i < despesas.size(); i++){
        if(despesas[i] == d)
            return false;
    }
    despesas.push_back(d);
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

bool Clube::removeDespesa(Despesa* d) {
    for(unsigned int i = 0; i < despesas.size(); i++)
        if(d == despesas[i]){
            despesas.erase(despesas.begin()+i);
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
bool Clube::changeDespesa(Despesa* d, string newInfo, Data* novaData, float novoValor) {
    if(despesas.size() < 1){
        iface->drawString("O clube nao tem despesas.\n");
        return false;
    }
    d->setInfo(newInfo);
    d->setData(novaData);
    d->setValor(novoValor);
    return true;
}




bool Clube::infoPessoal(){
    while(1){
        if(!listarJogadores())
            return false;
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
			TopMenu("INFORMACAO JOGADOR");
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
    return false;
}
bool Clube::infoSocios(){
    while(1){
        if(!listarSocios())
            return false;
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
			TopMenu("INFORMACAO SOCIO");
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
    return false;
}
void Clube::manutencao(){
    while(1){
        iface->cleanScr();
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
        else if (command == 'b') manutencaoSocios();
		else if (command == 'c') while (manutencaoExternos());
		else if (command == 'd') while (manutencaoModalidades());
        else if (command == 'e') manutencaoDespesas();
		else if (command == 'f') alterarData();
        else if(command == 'q') return;
    }
    return;
}


bool Clube::manutencaoSocios(){
	TopMenu("MANUTENCAO SOCIO");
	iface->drawString("a. Adicionar socio\n");
	iface->drawString("b. Alterar socio existente\n");
	iface->drawString("\n(q para sair)\n\n");
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
        if (addSocio(s1))
        {
            TopMenu("ADICIONAR SOCIO");
            iface->drawString(s1->showInfo());
            iface->drawString("\nO socio foi criado");
            pressToContinue();
        }
        else
        {
            TopMenu("ADICIONAR SOCIO");
            iface->drawString(s1->showInfo());
            iface->drawString("\nErro! O socio já existe");
            pressToContinue();
        }
        return true;

    }
    else if (command == 'b'){
        TopMenu("ALTERAR SOCIO");
        if (socios.size() == 0){
            iface->drawString("O clube nao tem socios associados!\n");
            pressToContinue();
            return false;
        }
        if (!listarSocios())
            return false;

        iface->drawString("\n(q para sair)\n\n");
        while (1){
            iface->drawString("Escolha o socio a gerir: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") return true;
            Socio *s1 = NULL;
            for (unsigned int i = 0; i < socios.size(); i++){
                if (socios[i]->getNome() == nome_input) s1 = socios[i];
            }
            if (s1 != NULL){
                manutencaoSocio(s1);
            }
            else {
                iface->drawString("\nSocio nao existe!\n");
                pressToContinue();
				return false;
            }
        }
        return false;
    }
    else if (command == 'q')
        return false;
    return false;
}

bool Clube::manutencaoSocio(Socio *s1){
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
        iface->drawString("(q para sair)\n\n");
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
                iface->drawString("\n\n\n\tINFORMACAO DO SOCIO\n\n");
                iface->drawString("\nIdade foi mudada com sucesso\n\n");
                pressToContinue();
                continue;
            }
            else{
                TopMenu("INFORMACAO DO SOCIO");
                iface->drawString("\nOcorreu um erro...\n\n");
                iface->drawString("\n\n\n* Carregue numa tecla para voltar... *\n");
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
            listarModalidades();
            iface->drawString("Escolha a modalidade a associar: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") return true;
            if(s1->QuotasAtrasadas(dataActual) == 0){
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
                return false;
            }
            iface->drawString("\nModalidade desassociada com sucesso\n\n");
            pressToContinue();
            return true;
        }
        if (command == 'f'){
            TopMenu("INFORMACAO DO SOCIO");
            s1->showModalidades();
            iface->drawString("Escolha a modalidade a remover: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") return true;
            for(size_t i = 0; i < modalidades.size(); i++){
                if(modalidades[i]->getNome() == nome_input){
                    s1->removeModalidade(modalidades[i]);
                    s1->removeQuota(modalidades[i]);
                    break;
                }
            }
            iface->drawString("\nModalidade desassociada com sucesso\n\n");
            pressToContinue();
            return true;
        }
        if (command == 'g'){
            TopMenu("INFORMACAO DO SOCIO");
            iface->drawString("O socio tem ");
            iface->drawString(s1->QuotasAtrasadas(dataActual));
            iface->drawString(" meses de quotas em atraso \n \n \n");
            iface->drawString("Quantos meses deseja pagar? (q para sair)\n\n");
            iface->drawString("   > ");
            string nome_input;
            iface->readLine(nome_input);
            int meses;
            std::stringstream ss;
            ss << nome_input;
            ss >> meses;
            if (nome_input == "q") return true;
            TopMenu("INFORMACAO DO SOCIO");
            iface->drawString("Quotas pagas: €");
            iface->drawString(s1->pagarQuotas(meses, dataActual));
            iface->drawString("\n\nQuotas pagas com sucesso\n\n");
            pressToContinue();
            return true;
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
            return true;
        }
    }
    return false;
}

bool Clube::manutencaoDespesas() {
    TopMenu("MANUTENCAO DE DESPESAS");
    iface->drawString("a. Adicionar despesa\n");
    iface->drawString("b. Alterar despesa existente\n");
    iface->drawString("\n(q para sair)\n\n");
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
        while (1){
            if (!listarDespesas())
                return false;
            iface->drawString("\n(q para sair)\n\n");
            iface->drawString("Escolha a despesa a gerir: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") return true;
            Despesa *d1 = NULL;
            for (unsigned int i = 0; i < despesas.size(); i++){
                if (despesas[i]->getInfo() == nome_input) d1 = despesas[i];
            }
            if (d1 != NULL) manutencaoDespesa(d1);
            else {
                iface->drawString("\nEssa despesa nao existe!\n");
                pressToContinue();
				return false;
            }
        }
        return false;
    }
    else if (command == 'q'){
        return true;
    }
    return false;
}

bool Clube::manutencaoDespesa(Despesa* d1) {
    while(1){
        TopMenu("ALTERAR DESPESA");
        iface->drawString(d1->showInfo());
        iface->drawString("\n\na. Mudar info\n");
        iface->drawString("b. Mudar valor\n");
        iface->drawString("c. Mudar data\n");
        iface->drawString("d. Remover despesa(!)\n");
        iface->drawString("q. Voltar...\n\n");
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
            return true;
        }
    }
    return false;

}


bool Clube::manutencaoExternos(){
    TopMenu("MANUTENCAO EXTERNOS");
    iface->drawString("a. Adicionar externo\n");
    iface->drawString("b. Alterar externo existente\n");
    iface->drawString("\n(q para sair)\n\n");
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

        if (sexo == "q") return true;
        unsigned int idade, nif;
        iface->drawString("Idade: ");
        iface->read(idade);
        iface->drawString("NIF: ");
        iface->read(nif);
        Pessoa *p1 = new Pessoa(nome, idade, nif, sexo);
        if (addExterno(p1))
        {
            TopMenu("ADICIONAR EXTERNO");
            iface->drawString(p1->showInfo());
            iface->drawString("\nO externo foi criado");
            pressToContinue();
        }
        else
        {
            TopMenu("ADICIONAR EXTERNO");
            iface->drawString(p1->showInfo());
            iface->drawString("\nErro! O externo já existe");
            pressToContinue();
        }
        return true;

    }
    else if (command == 'b') {
        if (externos.size() == 0){
            iface->drawString("\n\nO clube nao tem externos associados!\n");
            pressToContinue();
            return false;
        }
        if (!listarExternos())
            return false;
        iface->drawString("\n(q para sair)\n\n");
        while (1){
            iface->drawString("Escolha o externo a gerir: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") return true;
            Pessoa *p1 = NULL;
            for (unsigned int i = 0; i < externos.size(); i++){
                if (externos[i]->getNome() == nome_input) p1 = jogadores[i];
            }
            if (p1 != NULL){
                manutencaoExterno(p1);
                return true;
            }
            else {
                iface->drawString("\nExterno nao existe!\n");
                pressToContinue();
				return false;
            }
        }
        return false;
    }
    else if (command == 'q')
        return false;
    return false;
}
bool Clube::manutencaoExterno(Pessoa * p1){
    while (1){
        TopMenu("ALTERAR EXTERNO");
        iface->drawString(p1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar idade\n");
        iface->drawString("c. Mudar NIF\n");
        iface->drawString("d. Mudar sexo\n");
        iface->drawString("e. Remover externo(!)\n");
        iface->drawString("q. Voltar...\n");
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
            else if (sexo_c == 'q') return true;

            if (p1->changeSexo(sexo)){
                TopMenu("ADICIONAR EXTERNO");
                iface->drawString("\nSexo foi mudado com sucesso\n\n");
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
            return true;
        }
    }
    return false;
}


bool Clube::manutencaoJogadores(){
    TopMenu("MANUTENCAO JOGADORES");
    iface->drawString("a. Adicionar jogador\n");
    iface->drawString("b. Alterar jogador existente\n");
    iface->drawString("\n(q para sair)\n\n");
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
        if (addJogador(j1))
        {
            TopMenu("ADICIONAR JOGADOR");
            iface->drawString(j1->showInfo());
            iface->drawString("\nO jogador foi criado");
            pressToContinue();
        }
        else
        {
            TopMenu("ADICIONAR JOGADOR");
            iface->drawString(j1->showInfo());
            iface->drawString("\nO jogador já existe");
            pressToContinue();
        }
        return true;

    }
    else if (command == 'b') {
        if (jogadores.size() == 0){
            iface->drawString("O clube nao tem jogadores associados!\n");
            pressToContinue();
            return false;
        }
        if (!listarJogadores())
            return false;
        iface->drawString("(q para sair)\n\n");
        while (1){
            iface->drawString("Escolha o jogador a gerir: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") return true;
            Jogador *j1 = NULL;
            for (unsigned int i = 0; i < jogadores.size(); i++){
                if (jogadores[i]->getNome() == nome_input) j1 = jogadores[i];
            }
            if (j1 != NULL){
                manutencaoJogador(j1);
                return true;
            }
            else {
                iface->drawString("\nJogador nao existe!\n");
                pressToContinue();
				return false;
            }
        }
        return false;
    }
    else if (command == 'q')
        return false;
    return false;
}


bool Clube::manutencaoJogador(Jogador *j1){
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
        iface->drawString("q. Voltar...\n");
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
        if(command == 'b'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Nova idade? ");
            unsigned int idade;
            iface->read(idade);
            if(j1->changeIdade(idade)){
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nIdade foi mudada com sucesso\n\n");
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
        if(command == 'c'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Novo NIF? ");
            unsigned long NIF;
            iface->read(NIF);
            if(j1->changeNIF(NIF)){
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nNIF foi mudado com sucesso\n\n");
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
        if (command == 'd'){
            TopMenu("ALTERAR JOGADOR");
            string sexo;
            char sexo_c = ' ';
            while(sexo_c != 'm' && sexo_c != 'f' && sexo_c != 'q'){
                iface->drawString("Novo sexo(m/f)? ");
                iface->readChar(sexo_c);
            }
            if(sexo_c == 'm') sexo = "Macho";
            else if(sexo_c == 'f') sexo = "Femea";
            else if (sexo_c == 'q') return true;
            if (j1->changeSexo(sexo)){
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("\nSexo foi mudado com sucesso\n\n");
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
        if (command == 'e'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Nova modalidade? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") return true;
            Modalidade *m1 = NULL;
            for (unsigned int i = 0; i < modalidades.size(); i++){
                if (modalidades[i]->getNome() == nome) m1 = modalidades[i];
            }
            if (j1->addModalidade(m1))
            {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("A modalidade foi adicionada ao jogador");
                pressToContinue();
                return true;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A modalidade não existe");
                pressToContinue();
                return true;
            }
        }
        if (command == 'f'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Nova submodalidade? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") return true;
            SubModalidade *s1 = NULL;
            for (unsigned int i = 0; i < sub_modalidades.size(); i++){
                if (sub_modalidades[i]->getNome() == nome) s1 = sub_modalidades[i];
            }
            if (j1->addSubModalidade(s1))
            {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("A submodalidade foi adicionada ao jogador");
                pressToContinue();
                return true;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A submodalidade não existe");
                pressToContinue();
                return true;
            }
        }
        if (command == 'g'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Modalidade a remover do jogador? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") return true;
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
                pressToContinue();
                return true;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A modalidade não existe");
                pressToContinue();
                return true;
            }
        }
        if (command == 'h'){
            TopMenu("ALTERAR JOGADOR");
            iface->drawString("Submodalidade a remover do jogador? ");
            string nome;
            iface->readLine(nome);
            if (nome == "q") return true;
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
                pressToContinue();
                return true;
            }
            else {
                TopMenu("ALTERAR JOGADOR");
                iface->drawString("Erro! A submodalidade não existe");
                pressToContinue();
                return true;
            }
        }
        if (command == 'i'){
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
            return true;
        }
    }
    return false;
}

bool Clube::manutencaoModalidades(){
    TopMenu("MANUTENCAO MODALIDADES");
    iface->drawString("a. Adicionar modalidade\n");
    iface->drawString("b. Alterar modalidade existente\n");
    iface->drawString("\n(q para sair)\n\n");
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
        if (addModalidade(m1))
        {
            TopMenu("ADICIONAR MODALIDADE");
            iface->drawString(m1->showInfo());
            iface->drawString("\nA modalidade foi criada");
            pressToContinue();
        }
        else
        {
            TopMenu("ADICIONAR MODALIDADE");
            iface->drawString(m1->showInfo());
            iface->drawString("\nA modalidade já existe");
            pressToContinue();
        }
        return true;

    }
    else if (command == 'b') {
        if (modalidades.size() == 0){
            iface->drawString("O clube nao tem modalidades associadas!\n");
            pressToContinue();
            return false;
        }
        if (!listarModalidades())
            return false;
        iface->drawString("(q para sair)\n\n");
        while (1){
            iface->drawString("Escolha a modalidade a gerir: ");
            string nome_input;
            iface->readLine(nome_input);
            if (nome_input == "q") return true;
            Modalidade *m1 = NULL;
            for (unsigned int i = 0; i < modalidades.size(); i++){
                if (modalidades[i]->getNome() == nome_input) m1 = modalidades[i];
            }
            if (m1 != NULL){
                manutencaoModalidade(m1);
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
    else if (command == 'q')
        return false;
    return false;
}


bool Clube::manutencaoModalidade(Modalidade * m1){
    while (1){
        TopMenu("ALTERAR MODALIDADE");
        iface->drawString(m1->showInfo());
		std::stringstream s;
		for (unsigned int k = 0; k < sub_modalidades.size(); k++)
		if (sub_modalidades[k]->getMod()->getNome() == m1->getNome())
			s << "   -" << sub_modalidades[k]->getNome() << std::endl;
		iface->drawString(s.str());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Criar submodalidade\n");
        iface->drawString("c. Remover modalidade(!)\n");
        iface->drawString("q. Voltar...\n\n");
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
        if (command == 'b'){
            TopMenu("NOVA SUBMODALIDADE");
            iface->drawString("\nNome? ");
            string nome;
            iface->read(nome);
            SubModalidade *s1 = new SubModalidade(nome, m1);
            sub_modalidades.push_back(s1);
            iface->drawString("\n\nSubmodalidade criada com sucesso\n");
            pressToContinue();
            continue;
        }
        if (command == 'c'){
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
    iface->drawString("q. Voltar...\n\n");
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
