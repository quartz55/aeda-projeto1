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


void Clube::main()
{
	while (1){
		iface->cleanScr();
		char command;
		iface->drawString(dataActual.showData());
		iface->drawString("\n \n");
		iface->drawString("a. Jogadores\n");
		iface->drawString("b. Socios\n");
		iface->drawString("c. Externos\n");
		iface->drawString("d. Modalidades e submodalidades\n");
		iface->drawString("e. Despesas\n");
		iface->drawString("f. Manutencao\n");
		iface->drawString("q. Sair(!)\n");
		iface->drawString("   > ");
        iface->readChar(command);
        if (command == 'a'){
            if(jogadores.size() == 0){
                iface->drawString("O clube nao tem jogadores associados!\n");
                iface->getInput();
                continue;
            }
            while(infoPessoal());
        }
        else if (command == 'b'){
            if(socios.size() == 0){
                iface->drawString("O clube nao tem socios associados!\n");
                iface->getInput();
                continue;
            }
            while(1){
                if(!listarSocios()) break;
                iface->drawString("* Carregue numa tecla para voltar... *\n");
                iface->getInput();
            }
        }
		else if (command == 'c') {
			if (externos.size() == 0){
				iface->drawString("O clube nao tem externos associados!\n");
				iface->getInput();
				continue;
			}
			while (1){
				if (!listarExternos()) break;
				iface->drawString("* Carregue numa tecla para voltar... *\n");
				iface->getInput();
			}
		}
        else if (command == 'd'){
            if(modalidades.size() == 0){
                iface->drawString("O clube nao tem modalidades associados!\n");
                iface->getInput();
                continue;
            }
            while(1){
                if(!listarModalidades()) break;
				iface->drawString("* Carregue numa tecla para voltar... *\n");
                iface->getInput();
            }
        }
		if (command == 'e'){
			if (despesas.size() == 0){
				iface->drawString("O clube nao tem despesas associadas!\n");
				iface->getInput();
				continue;
			}
			while (1){
				if (!listarDespesas()) break;
				iface->drawString("* Press ANY key to continue... *\n");
				iface->getInput();
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
        iface->cleanScr();
        if(!listarJogadores())
            return false;
        iface->drawString("(q para sair)\n");
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
            iface->drawString(j1->showInfo());
			iface->drawString("* Carregue numa tecla para voltar... *\n");
            iface->getInput();
            continue;
        }
        else {
            iface->drawString("Jogador nao existe!\n");
            iface->getInput();
            continue;
        }
    }
    return false;
}
void Clube::manutencao(){
    while(1){
        iface->cleanScr();
        char command;
        iface->drawString("MANUTENCAO\n\n");
        iface->drawString("a. Manutencao de jogadores\n");
		iface->drawString("b. Manutencao de socios\n");
		iface->drawString("c. Manutencao de externos\n");
        iface->drawString("d. Manutencao de modalidades\n");
        iface->drawString("e. Manutencao de despesas\n");
		iface->drawString("f. Alterar data\n");
        iface->drawString("q. Voltar\n");
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
	iface->cleanScr();
	iface->drawString("a. Adicionar socio\n");
	iface->drawString("b. Alterar socio existente\n");
	iface->drawString("\n(q para sair)\n\n\n");
	iface->drawString("   > ");
	char command;
	iface->readChar(command);
	if (command == 'a')
	{
		iface->cleanScr();
		string nome, sexo;
		iface->drawString("Nome: ");
		iface->readLine(nome);
		if (nome == "q") return true;
		iface->drawString("Sexo: ");
		iface->readLine(sexo);
		if (sexo == "q") return true;
		unsigned int idade, nif;
		iface->drawString("Idade: ");
		iface->read(idade);
		iface->drawString("NIF: ");
		iface->read(nif);
		Socio *s1 = new Socio(nome, idade, nif, sexo);
		socios.push_back(s1);
		iface->cleanScr();
		iface->drawString(s1->showInfo());
		iface->drawString("\n");
		iface->drawString("O socio foi criado");
		iface->drawString("\n\n\n* Carregue numa tecla para voltar... *\n");
		iface->getInput();
		return true;

	}
	else if (command == 'b'){
		iface->cleanScr();
		if (socios.size() == 0){
			iface->drawString("O clube nao tem socios associados!\n");
			iface->getInput();
			return false;
		}
		if (!listarSocios())
			return false;

		iface->drawString("(q para sair)\n");
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
				return true;
			}
			else {
				iface->drawString("Socio nao existe!\n");
				iface->getInput();
				continue;
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
        iface->cleanScr();
        iface->drawString("Informacao do socio:\n");
        iface->drawString(s1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar idade\n");
        iface->drawString("c. Mudar NIF\n");
        iface->drawString("d. Mudar sexo\n");
        iface->drawString("e. Associacao de modalidades\n");
        iface->drawString("f. Remover modalidades\n");
        iface->drawString("g. Pagar quotas\n");
        iface->drawString("h. Remover socio(!)\n");
        iface->drawString("q. Voltar...\n");
        iface->drawString("   > ");
        char command;
        iface->readChar(command);
        if (command == 'a'){
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if (s1->changeNome(nome)){
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
        if (command == 'b'){
            iface->drawString("Nova idade? ");
            unsigned int idade;
            iface->read(idade);
            if (s1->changeIdade(idade)){
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
        if (command == 'c'){
            iface->drawString("Novo NIF? ");
            unsigned long NIF;
            iface->read(NIF);
            if (s1->changeNIF(NIF)){
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
        if (command == 'd'){
            iface->drawString("Novo sexo? ");
            string sexo;
            iface->readLine(sexo);
            if (s1->changeSexo(sexo)){
                iface->cleanScr();
                iface->drawString("\nSexo foi mudado com sucesso\n\n");
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
        if (command == 'e'){
        	iface->cleanScr();
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
        		iface->cleanScr();
        		iface->drawString("Nao se pode associar a uma nova modalidade com quotas em atraso\n");
        		iface->getInput();
        		return false;
        	}
        	iface->drawString("\nModalidade desassociada com sucesso\n\n");
        	iface->getInput();
        	return true;
        }
        if (command == 'f'){
        	iface->cleanScr();
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
        	iface->getInput();
        	return true;
        }
        if (command == 'g'){
        	iface->cleanScr();
        	iface->drawString("O socio tem ");
        	iface->drawString(s1->QuotasAtrasadas(dataActual));
        	iface->drawString(" meses de quotas em atraso \n \n \n");
        	iface->drawString("Quantos meses deseja pagar? (q para sair)");
        	iface->drawString("   > ");
        	string nome_input;
        	iface->readLine(nome_input);
        	int meses;
        	std::stringstream ss;
        	ss << nome_input;
        	ss >> meses;
        	if (nome_input == "q") return true;
        	iface->cleanScr();
        	iface->drawString("Quotas pagas: €");
        	iface->drawString(s1->pagarQuotas(meses, dataActual));
        	iface->drawString("\n");
        	iface->drawString("\nQuotas pagas com sucesso\n\n");
        	iface->getInput();
        	return true;
        }
        if (command == 'h'){
            for (size_t i = 0; i < socios.size(); i++)
            {
                if (socios[i] == s1)
                    socios.erase(socios.begin() + i);
            }
            iface->drawString("\nSocio removido com sucesso\n\n");
            iface->getInput();
            return true;
        }
        else if (command == 'q'){
            return true;
        }
    }
    return false;
}

bool Clube::manutencaoDespesas() {
	iface->cleanScr();
	iface->drawString("a. Adicionar despesa\n");
	iface->drawString("b. Alterar despesa existente\n");
	iface->drawString("\n(q para sair)\n\n\n");
	iface->drawString("   > ");
	char command;
	iface->readChar(command);
	if (command == 'a')
	{
		iface->cleanScr();
		string nome;
		iface->drawString("Info: ");
		iface->readLine(nome);
		if (nome == "q") return true;
		float valor;
		iface->drawString("Valor: ");
		iface->read(valor);
		if (valor < 0){
			iface->drawString("\n \nO valor não pode ser negativo\n \n");
			iface->getInput();
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
		despesas.push_back(despesa);
		iface->cleanScr();
		iface->drawString(despesa->showInfo());
		iface->drawString("\nA despesa foi criada");
		iface->drawString("\n\n\n* Carregue numa tecla para voltar... *\n");
		iface->getInput();
		return true;

	}
	else if (command == 'b'){
		while (1){
			iface->cleanScr();
			if (!listarDespesas())
				return false;
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
				iface->drawString("Essa despesa nao existe!\n");
				continue;
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
        iface->cleanScr();
        iface->drawString("Informacao da despesa:\n");
        iface->drawString(d1->showInfo());
        iface->drawString("\n\na. Mudar info\n");
        iface->drawString("b. Mudar valor\n");
        iface->drawString("c. Mudar data\n");
        iface->drawString("d. Remover despesa(!)\n");
        iface->drawString("q. Voltar...\n");
        iface->drawString("   > ");
        char command;
        iface->readChar(command);
        if(command == 'a'){
            iface->drawString("Nova info? ");
            string nome;
            iface->readLine(nome);
            if(d1->setInfo(nome)){
                iface->cleanScr();
                iface->drawString("\n Info foi mudada com sucesso\n\n");
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
            iface->drawString("Novo valor? ");
            float valor;
            iface->read(valor);
            if(d1->setValor(valor)){
                iface->cleanScr();
                iface->drawString("\nValor foi mudado com sucesso\n\n");
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
            iface->drawString(d1->getData()->showData());
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
                iface->cleanScr();
                iface->drawString("\nData alterada com sucesso\n\n");
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
        if (command == 'd'){
            for (unsigned int i = 0; i< despesas.size(); i++){
                if (despesas[i] == d1)
                {
                    despesas.erase(despesas.begin() + i);
                }
            }
            iface->drawString("\nDespesa removida\n\n");
            iface->getInput();
            return true;
        }
        else if(command == 'q'){
            return true;
        }
    }
    return false;

}


bool Clube::manutencaoExternos(){
	iface->cleanScr();
	iface->drawString("a. Adicionar externo\n");
	iface->drawString("b. Alterar externo existente\n");
	iface->drawString("\n(q para sair)\n\n\n");
	iface->drawString("   > ");
	char command;
	iface->readChar(command);
	if (command == 'a')
	{
		iface->cleanScr();
		string nome, sexo;
		iface->drawString("Nome: ");
		iface->readLine(nome);
		if (nome == "q") return true;
		iface->drawString("Sexo: ");
		iface->readLine(sexo);
		if (sexo == "q") return true;
		unsigned int idade, nif;
		iface->drawString("Idade: ");
		iface->read(idade);
		iface->drawString("NIF: ");
		iface->read(nif);
		Pessoa *p1 = new Pessoa(nome, idade, nif, sexo);
		externos.push_back(p1);
		iface->cleanScr();
		iface->drawString(p1->showInfo());
		iface->drawString("\nO externo foi criado");
		iface->drawString("\n\n\n* Carregue numa tecla para voltar... *\n");
		iface->getInput();
		return true;

	}
	else if (command == 'b') {
		if (externos.size() == 0){
			iface->drawString("O clube nao tem externos associados!\n");
			iface->getInput();
			return false;
		}
		if (!listarExternos())
			return false;
		iface->drawString("(q para sair)\n");
		while (1){
			iface->drawString("Escolha o externo a gerir: ");
			string nome_input;
			iface->readLine(nome_input);
			if (nome_input == "q") return true;
			Pessoa *p1 = NULL;
			for (unsigned int i = 0; i < externos.size(); i++){
				if (externos[i]->getNome() == nome_input) p1 = jogadores[i];
			}
			if (j1 != NULL){
				manutencaoExterno(p1);
				return true;
			}
			else {
				iface->drawString("Externo nao existe!\n");
				iface->getInput();
				continue;
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
		iface->cleanScr();
		iface->drawString("Informacao do externo:\n");
		iface->drawString(p1->showInfo());
		iface->drawString("\n\na. Mudar nome\n");
		iface->drawString("b. Mudar idade\n");
		iface->drawString("c. Mudar NIF\n");
		iface->drawString("d. Mudar sexo\n");
		iface->drawString("f. Remover externo(!)\n");
		iface->drawString("q. Voltar...\n");
		iface->drawString("   > ");
		char command;
		iface->readChar(command);
		if (command == 'a'){
			iface->drawString("Novo nome? ");
			string nome;
			iface->readLine(nome);
			if (p1->changeNome(nome)){
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
		if (command == 'b'){
			iface->drawString("Nova idade? ");
			unsigned int idade;
			iface->read(idade);
			if (p1->changeIdade(idade)){
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
		if (command == 'c'){
			iface->drawString("Novo NIF? ");
			unsigned long NIF;
			iface->read(NIF);
			if (p1->changeNIF(NIF)){
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
		if (command == 'd'){
			iface->drawString("Novo sexo? ");
			string sexo;
			iface->readLine(sexo);
			if (p1->changeSexo(sexo)){
				iface->cleanScr();
				iface->drawString("\nSexo foi mudado com sucesso\n\n");
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
		if (command == 'f'){
			for (size_t i = 0; i < externos.size(); i++)
			{
				if (externos[i] == p1)
					externos.erase(externos.begin() + i);
			}
			iface->drawString("\nExterno removido com sucesso\n\n");
			iface->getInput();
			return true;
		}
		else if (command == 'q'){
			return true;
		}
	}
	return false;
}


bool Clube::manutencaoJogadores(){
    iface->cleanScr();
    iface->drawString("a. Adicionar jogador\n");
    iface->drawString("b. Alterar jogador existente\n");
    iface->drawString("\n(q para sair)\n\n\n");
    iface->drawString("   > ");
    char command;
    iface->readChar(command);
    if (command == 'a')
    {
        iface->cleanScr();
        string nome, sexo;
        iface->drawString("Nome: ");
        iface->readLine(nome);
        if (nome == "q") return true;
        iface->drawString("Sexo: ");
        iface->readLine(sexo);
        if (sexo == "q") return true;
        unsigned int idade, nif;
        iface->drawString("Idade: ");
        iface->read(idade);
        iface->drawString("NIF: ");
        iface->read(nif);
        Jogador *j1 = new Jogador(nome, idade, nif, sexo);
        jogadores.push_back(j1);
        iface->cleanScr();
        iface->drawString(j1->showInfo());
        iface->drawString("\nO jogador foi criado");
        iface->drawString("\n\n\n* Press ANY key to continue... *\n");
        iface->getInput();
        return true;

    }
    else if (command == 'b') {
		if (jogadores.size() == 0){
			iface->drawString("O clube nao tem jogadores associados!\n");
			iface->getInput();
			return false;
		}
        if (!listarJogadores())
            return false;
        iface->drawString("(q para sair)\n");
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
                iface->drawString("Jogador nao existe!\n");
                iface->getInput();
                continue;
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
        iface->cleanScr();
        iface->drawString("Informacao do jogador:\n");
        iface->drawString(j1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Mudar idade\n");
        iface->drawString("c. Mudar NIF\n");
        iface->drawString("d. Mudar sexo\n");
        iface->drawString("d. Associacao de Modalidades\n");
        iface->drawString("e. Associacao de sub-modalidades\n");
        iface->drawString("d. Remover Modalidades\n");
        iface->drawString("e. Remover sub-modalidades\n");
        iface->drawString("f. Remover jogador(!)\n");
        iface->drawString("q. Voltar...\n");
        iface->drawString("   > ");
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
        if (command == 'd'){
            iface->drawString("Novo sexo? ");
            string sexo;
            iface->readLine(sexo);
            if (j1->changeSexo(sexo)){
                iface->cleanScr();
                iface->drawString("\nSexo foi mudado com sucesso\n\n");
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
        if (command == 'f'){
            for (size_t i = 0; i < jogadores.size(); i++)
            {
                if (jogadores[i] == j1)
                    jogadores.erase(jogadores.begin() + i);
            }
            iface->drawString("\nJogador removido com sucesso\n\n");
            iface->getInput();
            return true;
        }
        else if(command == 'q'){
            return true;
        }
    }
    return false;
}

bool Clube::manutencaoModalidades(){
    while (1){
        iface->cleanScr();
        if(!listarModalidades()) return false;
        iface->drawString("Escolha a modalidade a gerir: ");
        string nome_input;
        iface->readLine(nome_input);
        if (nome_input == "q") return true;
        Modalidade *m1 = NULL;
        for (unsigned int i = 0; i<modalidades.size(); i++){
            if (modalidades[i]->getNome() == nome_input) m1 = modalidades[i];
        }
        if (m1 != NULL) manutencaoModalidade(m1);
        else {
            iface->drawString("Modalidade nao existe!\n");
            iface->getInput();
            continue;
        }
    }
    return false;
}
bool Clube::manutencaoModalidade(Modalidade * m1){
    while (1){
        iface->cleanScr();
        iface->drawString("Informacao da modalidade:\n");
        iface->drawString(m1->showInfo());
        iface->drawString("\n\na. Mudar nome\n");
        iface->drawString("b. Criar submodalidade\n");
        iface->drawString("c. Remover modalidade(!)\n");
        iface->drawString("q. Voltar...\n");
        iface->drawString(" > ");
        char command;
        iface->readChar(command);
        if (command == 'a'){
            iface->drawString("Novo nome? ");
            string nome;
            iface->readLine(nome);
            if (m1->changeNome(nome)){
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
        if (command == 'b'){
            iface->drawString("Nova submodalidade\nNome? ");
            string nome;
            iface->read(nome);
            SubModalidade *s1 = new SubModalidade(nome, m1);
            sub_modalidades.push_back(s1);
            iface->drawString("Submodalidade criada com sucesso\n");
            iface->getInput();
            continue;
        }
        if (command == 'c'){
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
            iface->getInput();
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
    iface->cleanScr();
    iface->drawString(dataActual.showData());
	iface->drawString("\n\na. Avancar uma semana\n");
	iface->drawString("b. Avancar um mes\n");
	iface->drawString("c. Avancar um ano\n");
	iface->drawString("d. Escolher data manualmente\n");
	iface->drawString("q. Voltar...\n");
	iface->drawString("   > ");
	char command;
	iface->readChar(command);
	if (command == 'a') {
		iface->cleanScr();
		dataActual.addDays(7);
		iface->drawString("\n \nData alterada para ");
		iface->drawString(dataActual.showData());
		iface->drawString("\n\n\n* Press ANY key to continue... *\n");
		iface->getInput();
		return;
	}
	else if (command == 'b') {
		iface->cleanScr();
		dataActual.addMonths(1);
		iface->drawString("\n \nData alterada para ");
		iface->drawString(dataActual.showData());
		iface->drawString("\n\n\n* Press ANY key to continue... *\n");
		iface->getInput();
		return;
	}
	else if (command == 'c') {
		iface->cleanScr();
		dataActual.addYears(1);
		iface->drawString("\n \nData alterada para ");
		iface->drawString(dataActual.showData());
		iface->drawString("\n\n\n* Press ANY key to continue... *\n");
		iface->getInput();
		return;
	}
	else if (command == 'd')
	{
		iface->drawString("\n\n\n\nNovo Dia? ");
		unsigned int dia;
		iface->read(dia);
		if (dia < 1 || dia > 31){
			iface->drawString("Erro, dia invalido!");
			iface->getInput();
			return;
		}
		iface->drawString("Novo Mes (inteiro equivalente)? ");
		unsigned int mes;
		iface->read(mes);
		if (mes < 1 || mes > 12){
			iface->drawString("Erro, mes invalido!");
			iface->getInput();
			return;
		}
		iface->drawString("Novo Ano ? ");
		unsigned int ano;
		iface->read(ano);
		Data data = Data(dia, mes, ano);
		iface->drawString("Alterar data atual de ");
		iface->drawString(dataActual.showData());
		iface->drawString(" para ");
		iface->drawString(data.showData());
		iface->drawString("? (y/n)\n");
		iface->drawString("   > ");
		char command;
		iface->readChar(command);
		if (command == 'y')
		{
			dataActual.setData(dia, mes, ano);
			iface->cleanScr();
			iface->drawString("\nData alterada com sucesso\n\n");
			iface->getInput();
		}
		else
		{
			iface->drawString("\nOperacao cancelada\n\n");
			iface->getInput();
		}

		return;
	}
	else if (command == 'q')
		return;
}

bool Clube::quit(){
    iface->drawString("\n\n\n* Carregue numa tecla para sair... *\n");
    iface->getInput();
    iface->cleanScr();
    delete iface;
    return true;
}
