//##############################################
//##READ AND WRITE OPERATIONS RELATED TO CLUBE##
//##############################################

string Clube::FILE_JOGADORES = "../txt/jogadores.txt";
string Clube::FILE_MODALIDADES = "../txt/modalidades.txt";
string Clube::FILE_SOCIOS = "../txt/socios.txt";
string Clube::FILE_DATA = "../txt/data.txt";



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
bool Clube::readData(string filename){
	int dia, mes, ano;
	string line;
	std::ifstream file;
	file.open(filename.c_str());
	if(file.is_open()){
		file >> dia >> mes >> ano;
		dataActual.setData(dia,mes,ano);
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
bool Clube::writeData(string filename) {
	std::ofstream file;
	file.open(filename.c_str());
	if(file.is_open()){
		file << dataActual.getDay() << " " << dataActual.getMonth() << " " << dataActual.getYear();
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
	if(!readData(FILE_DATA)) return false;

	return true;
}

bool Clube::writeAll(){
	if(!writeModalidades(modalidades, FILE_MODALIDADES)) return false;
	if(!writeJogadores(jogadores, FILE_JOGADORES)) return false;
	if(!writeSocios(socios, FILE_SOCIOS)) return false;
	if(!writeData(FILE_DATA)) return false;


	return true;
}

