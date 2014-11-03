#include "clube.h"

#include <algorithm>

string Clube::FILE_JOGADORES = "../txt/jogadores.txt";
string Clube::FILE_MODALIDADES = "../txt/modalidades.txt";
string Clube::FILE_SOCIOS = "../txt/socios.txt";
string Clube::FILE_DATA = "../txt/data.txt";

Interface *Clube::iface = new Interface();

Clube::Clube(): dataActual(1,1,1900){
	readAll();
}

//SORT FUNCTIONS
#include "./clube/sorts.h"
//#############################


//READ AND WRITE OPERATIONS
#include "./clube/iooperations.h"
//#############################

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

void Clube::CRUD(){
	while(1){
		iface->cleanScr();
		char command;
		iface->drawString(dataActual.showData());
		iface->drawString("\n \n");
		iface->drawString("a. Manutencao\n");
		iface->drawString( "q. Sair(!)\n");
		iface->drawString( "   > ");
		iface->readChar(command);
		if(command == 'a') manutencao();
		else if(command == 'q'){
			iface->drawString( "Tem a certeza que deseja sair? (y/N)\n");
			iface->drawString( "   > ");
			iface->readChar(command);
			if(command == 'y'){
				iface->drawString( "Deseja gravar todas as alteracoes que efetuou? (Y/n)\n");
				iface->drawString( "   > ");
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
		iface->drawString("a. Manutencao de jogadores\n");
		iface->drawString("b. Manutencao de modalidades\n");
		iface->drawString("c. Manutencao de socios\n");
		iface->drawString("d. Manutencao de despesas\n");
		iface->drawString("e. Manutencao de quotas\n");
		iface->drawString("q. Voltar\n");
		iface->drawString("   > ");
		iface->readChar(command);
		if(command == 'a') manutencaoJogadores();
		if (command == 'b') manutencaoModalidades();
		if (command == 'c'); //manutencaoSocios();
		if (command == 'd'); //manutencaoDespesas();
		if (command == 'e'); //manutencaoQuotas();
		else if(command == 'q') return;
	}
}

void Clube::listarPessoas(){
	iface->drawString("-------------------------------\n");
	iface->drawString("Listagem de todos os associados ao clube\n");
	iface->drawString("-------------------------------\n");
	iface->drawString("-------------------------------\n");
	listarExternos(externos);
	iface->drawString("-------------------------------\n");
	listarJogadores(jogadores);
	iface->drawString("-------------------------------\n");
	listarSocios(socios);
	iface->drawString("-------------------------------\n");
	iface->newLine();
}

void Clube::listarExternos(vector<Pessoa *> externos){
	iface->drawString("Listagem de externos:\n");
	unsigned int counter = 0;
	for(unsigned int i = 0; i < externos.size(); i++){
		iface->drawString(externos[i]->getNome()); iface->drawString("    ");
		counter++;
		if(counter>3){ iface->newLine(); counter = 0;}
	}
	iface->newLine();
}

void Clube::listarJogadores(vector<Jogador *> jogadores){
	iface->drawString("Listagem de jogadores\n");
	unsigned int counter = 0;
	for(unsigned int i = 0; i < jogadores.size(); i++){
		iface->drawString(jogadores[i]->getNome()); iface->drawString("    ");
		counter++;
		if(counter>3){ iface->newLine(); counter = 0;}
	}
	iface->newLine();
}

void Clube::listarSocios(vector<Socio *> socios){
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
		iface->drawString("> "); iface->drawString(modalidades[i]->getNome());
		iface->newLine();
		for(unsigned int k = 0; k < sub_modalidades.size(); k ++)
			if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome()){
				iface->drawString("   -"); iface->drawString(sub_modalidades[k]->getNome()); iface->newLine();
			}
	}
}

void Clube::listarDespesas() {
	for(unsigned int i = 0; i < despesas.size(); i++){
		iface->drawString(despesas[i]->showInfo());
	}
}
bool Clube::manutencaoJogadores(){
	while(1){
		iface->cleanScr();
        vector <Jogador *> teste = jogadores;
        std::sort(teste.begin(), teste.end(), sortByIdade);
		listarJogadores(teste);
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
		else if(command == 'q'){
			return true;
		}
	}
	return false;
}

bool Clube::manutencaoModalidades(){
	while (1){
		iface->cleanScr();
		listarModalidades();
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
		iface->drawString("   > ");
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
			SubModalidade sm1(nome, m1);
			//sub_modalidades.push_back(sm1);
			iface->drawString("Submodalidade criada com sucesso\n");
			continue;
		}
		else if (command == 'q'){
			return true;
		}
	}
	return false;
}


bool Clube::quit(){
	iface->drawString("\n\n\n*Press ANY KEY to exit...*\n");
	iface->getInput();
	delete iface;
	return true;
}
