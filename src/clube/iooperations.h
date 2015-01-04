/**
 * @file   iooperations.h
 * 
 * @brief  Ficheiro responsável pela funcoes de leitura e escrita em ficheiros da classe Clube
 * 
 * 
 */

#ifndef IOOPERATIONS_H
#define IOOPERATIONS_H

#include "../clube.h"
//##############################################
//##READ AND WRITE OPERATIONS RELATED TO CLUBE##
//##############################################

bool Clube::readModalidades(string filename){
	std::ifstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		string line;
		while (getline(file, line)){
			Modalidade *m1 = new Modalidade(line);
			modalidades.push_back(m1);
			getline(file, line);
			std::stringstream ss(line);
			string helper;
			ss >> helper;
			while (helper != "#"){
				std::stringstream sub;
				while (helper != "/"){
					sub << helper << " ";
					ss >> helper;
				}
				string nome_sub = sub.str();
				nome_sub.erase(nome_sub.size() - 1);
				SubModalidade *s1 = new SubModalidade(nome_sub, m1);
				sub_modalidades.push_back(s1);
				ss >> helper;
			}
			float valor;
			file >> valor;
			m1->setPrecoQuota(valor);
			getline(file, line);
		}
		file.close();
		return true;
	}
	throw filename;
	return false;
}
bool Clube::readData(string filename){
	int dia, mes, ano;
	string line;
	std::ifstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		file >> dia >> mes >> ano;
		dataActual.setData(dia, mes, ano);
		file.close();
		return true;
	}
	throw filename;
	return false;

}
bool Clube::readDespesas(string filename){
	int dia, mes, ano;
	float valor;
	string line, info;
	std::ifstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		while (getline(file, line)){
			std::stringstream ss;
			ss << line;
			ss >> dia >> mes >> ano;
			getline(file, info);
			file >> valor;
			getline(file, line);
			Despesa * d1 = new Despesa(dia, mes, ano, valor, info);
			despesas.push_back(d1);
		}
		file.close();
		return true;
	}
	throw filename;
	return false;
}
bool Clube::readJogadores(string filename){
	std::ifstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		string line;
		while (getline(file, line)){

			std::stringstream dados_jogador(line);

			//Ler nome jogador
			std::stringstream nome_jogador;
			string helper;
			dados_jogador >> helper;
			while (helper != "#"){
				nome_jogador << helper << " ";
				dados_jogador >> helper;
			}
			string nome = nome_jogador.str();
			nome.erase(nome.size() - 1);
			//------------
			//DADOS INICIAIS DO JOGADOR
			unsigned int idade;
			unsigned long NIF;
			string sexo;
			dados_jogador >> idade;
			dados_jogador >> sexo;
			dados_jogador >> NIF;
			Jogador *j1 = new Jogador(nome, idade, NIF, sexo);
			//------------
			addJogador(j1);


			//ATRIBUIR (SUB-)MODALIDADES
			getline(file, line);
			while (line != "--------"){
				for (unsigned int i = 0; i < modalidades.size(); i++){
					if (modalidades[i]->getNome() == line)
						j1->addModalidade(modalidades[i]);
				}

				string helper;
				getline(file, line);

				std::stringstream ss(line);

				ss >> helper;
				while (helper != "#"){
					std::stringstream sub;
					while (helper != "/"){
						sub << helper << " ";
						ss >> helper;
					}
					string nome_sub = sub.str();
					nome_sub.erase(nome_sub.size() - 1);
					for (unsigned int i = 0; i < sub_modalidades.size(); i++){
						if (sub_modalidades[i]->getNome() == nome_sub)
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
	throw filename;
	return false;
}
bool Clube::readExternos(string filename){
	std::ifstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		string line;
		while (getline(file, line)){

			std::stringstream dados_externo(line);

			//Ler nome jogador
			std::stringstream nome_externo;
			string helper;
			dados_externo >> helper;
			while (helper != "#"){
				nome_externo << helper << " ";
				dados_externo >> helper;
			}
			string nome = nome_externo.str();
			nome.erase(nome.size() - 1);
			//------------
			//DADOS INICIAIS DO JOGADOR
			unsigned int idade;
			unsigned long NIF;
			string sexo;
			dados_externo >> idade;
			dados_externo >> sexo;
			dados_externo >> NIF;
			Pessoa *p1 = new Pessoa(nome, idade, NIF, sexo);
			p1->setExterno();
			//------------
			addExterno(p1);
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
	if (file.is_open()){
		string line;
		while (getline(file, line)){

			std::stringstream dados_socio(line);

			//Ler nome socio
			std::stringstream nome_socio;
			string helper;
			dados_socio >> helper;
			while (helper != "#"){
				nome_socio << helper << " ";
				dados_socio >> helper;
			}
			string nome = nome_socio.str();
			nome.erase(nome.size() - 1);
			//------------
			//DADOS INICIAIS DO socio
			unsigned int idade;
			unsigned long NIF;
			string sexo;
			dados_socio >> idade;
			dados_socio >> sexo;
			dados_socio >> NIF;
			Socio *s1 = new Socio(nome, idade, NIF, sexo);
			//------------
			addSocio(s1);


			//ATRIBUIR (SUB-)MODALIDADES
			getline(file, line);
			while (line != "--------"){
				for (unsigned int i = 0; i < modalidades.size(); i++){
					if (modalidades[i]->getNome() == line){
						s1->addModalidade(modalidades[i], dataActual.getMonth(), dataActual.getYear());
						int dia, mes, ano;
						file >> dia >> mes >> ano;
						vector <Quota*> quotas = s1->getQuotas();
						for (size_t k = 0; k < quotas.size(); k++){
							if (quotas[k]->getModalidade() == modalidades[i]){
								Data *data = new Data(dia, mes, ano);
								quotas[k]->setLastPayed(data);
							}
						}
						getline(file, line);
					}
				}

				getline(file, line);
			}
			//------------
		}
		file.close();
		return true;
	}
	throw filename;
	return false;
}

bool Clube::readLugares(string filename){
	std::ifstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		string line;
		while (getline(file, line)){

			std::stringstream lugar(line);

			//Ler tipo de lugar 
			string tipo;
			lugar >> tipo;
			//------------
			//DADOS INICIAIS DO socio
			unsigned int dia;
			unsigned int mes;
			unsigned int ano;
			unsigned long NIF;
			lugar >> dia;
			lugar >> mes;
			lugar >> ano;
			lugar >> NIF;
			//ATRIBUIR SOCIO
			Socio* soc = NULL;
			for (size_t i = 0; i < socios.size(); i++){
				if (socios[i]->getNIF() == NIF){
					soc = socios[i];
					break;
				}
			}
			addLugar(new Lugar(dia, mes, ano, tipo, soc));
			//------------
		}
		file.close();
		return true;
	}
	throw filename;
	return false;
}

bool Clube::readEmpresas(string filename){
	std::ifstream file;
	file.open(filename.c_str());
	if(file.is_open()){
		string line;
		while(getline(file,line)){

			std::stringstream dados_empresa(line);

			//Ler nome empresa
			std::stringstream nome_empresa;
			string helper;
			dados_empresa >> helper;
			while(helper != "#"){
				nome_empresa << helper << " ";
				dados_empresa >> helper;
			}
			string nome = nome_empresa.str();
			nome.erase(nome.size()-1);
			//------------
			//DADOS INICIAIS DA EMPRESA
			unsigned long NIF;
			unsigned int localizacao, contrato;
			dados_empresa >> NIF;
			dados_empresa >> localizacao;
			dados_empresa >> contrato;
			Empresa *e1 = new Empresa(nome,NIF,localizacao);
      if(contrato) e1->changeContrato(true);
			//------------

			addEmpresa(e1);

			//ATRIBUIR SERVICOS
      string titulo, descricao;
			getline(file, line);
			while(line != "--------"){
        titulo = line;

				getline(file,line);
        descricao = line;

        Servico *serv = new Servico;
        serv->titulo = titulo;
        serv->descricao = descricao;

        if(!e1->hasService(titulo)) e1->addServico(serv);

        getline(file, line);
      }
      //------------
    }
    file.close();
    return true;
  }
  throw filename;
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
      float *p = modalidades[i]->getPrecoQuota();
      file << *p;
      file << endl;
    }
    file.close();
    return true;
  }
  throw filename;
  return false;
}
bool Clube::writeJogadores(vector<Jogador *> jogadores, string filename){
	std::ofstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		for (unsigned int i = 0; i<jogadores.size(); i++){
			std::stringstream ss;
			ss << jogadores[i]->getNome() << " # ";
			ss << jogadores[i]->getIdade() << " ";
			ss << jogadores[i]->getSexo() << " ";
			ss << jogadores[i]->getNIF();
			file << ss.str();
			file << endl;
			vector <Modalidade *> mods = jogadores[i]->getMods();
			vector <SubModalidade *> sub_mods = jogadores[i]->getSubMods();
			for (unsigned int k = 0; k < mods.size(); k++){
				string mod_nome = mods[k]->getNome();
				file << mod_nome << endl;;
				ss.str(string()); //Clears the stringstream
				for (unsigned int j = 0; j < sub_mods.size(); j++){
					if (sub_mods[j]->getMod()->getNome() == mod_nome)
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
	throw filename;
	return false;
}
bool Clube::writeExternos(vector<Pessoa *> externos, string filename){
	std::ofstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		for (unsigned int i = 0; i<externos.size(); i++){
			std::stringstream ss;
			ss << externos[i]->getNome() << " # ";
			ss << externos[i]->getIdade() << " ";
			ss << externos[i]->getSexo() << " ";
			ss << externos[i]->getNIF();
			file << ss.str();
			file << endl;
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
	if (file.is_open()){
		for (unsigned int i = 0; i<socios.size(); i++){
			std::stringstream ss;
			ss << socios[i]->getNome() << " # ";
			ss << socios[i]->getIdade() << " ";
			ss << socios[i]->getSexo() << " ";
			ss << socios[i]->getNIF();
			file << ss.str();
			file << endl;
			vector <Modalidade *> mods = socios[i]->getMods();
			vector<Quota *> quotas = socios[i]->getQuotas();
			for (unsigned int k = 0; k < mods.size(); k++){
				string mod_nome = mods[k]->getNome();
				file << mod_nome << endl;
				ss.str(string()); //Clears the stringstream
				for (size_t j = 0; j < quotas.size(); j++){
					if (quotas[j]->getModalidade() == mods[k]){
						file << quotas[j]->getLastPayed()->getDay() << " " << quotas[j]->getLastPayed()->getMonth() << " " << quotas[j]->getLastPayed()->getYear();
					}
				}
				file << endl;
			}
			file << "--------\n";
		}
		SociosHash::const_iterator it = socios_em_atraso.begin();
		while(it !=socios_em_atraso.end()){
			std::stringstream ss;
			ss << (*it)->getNome() << " # ";
			ss << (*it)->getIdade() << " ";
			ss << (*it)->getSexo() << " ";
			ss << (*it)->getNIF();
			file << ss.str();
			file << endl;
			vector <Modalidade *> mods = (*it)->getMods();
			vector<Quota *> quotas = (*it)->getQuotas();
			for (unsigned int k = 0; k < mods.size(); k++){
				string mod_nome = mods[k]->getNome();
				file << mod_nome << endl;
				ss.str(string()); //Clears the stringstream
				for (size_t j = 0; j < quotas.size(); j++){
					if (quotas[j]->getModalidade() == mods[k]){
						file << quotas[j]->getLastPayed()->getDay() << " " << quotas[j]->getLastPayed()->getMonth() << " " << quotas[j]->getLastPayed()->getYear();
					}
				}
				file << endl;
			}
			file << "--------\n";
			it++;
		}
		file.close();
		return true;
	}
	throw filename;
	return false;
}
bool Clube::writeData(string filename) {
	std::ofstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		file << dataActual.getDay() << " " << dataActual.getMonth() << " " << dataActual.getYear();
		file.close();
		return true;
	}
	throw filename;
	return false;
}
bool Clube::writeDespesas(string filename){
	string line, info;
	std::ofstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		for (size_t i = 0; i < despesas.size(); i++){
			file << despesas[i]->getData()->getDay() << " " << despesas[i]->getData()->getMonth() << " " << despesas[i]->getData()->getYear() << endl;
			file << despesas[i]->getInfo() << endl;
			file << despesas[i]->getValor() << endl;
		}
		file.close();
		return true;
	}
	throw filename;
	return false;
}

bool Clube::writeLugares(string filename){
	std::ofstream file;
	file.open(filename.c_str());
	if (file.is_open()){
		set<Lugar*>::const_iterator it = lugares.begin();
		while (it != lugares.end())
		{
			file << (*it)->getTipo() << " ";
			file << (*it)->getLast_payed()->getDay() << " " << (*it)->getLast_payed()->getMonth() << " " << (*it)->getLast_payed()->getYear() ;
			file << " " << (*it)->getSocio()->getNIF() << endl;
			it++;
		}
		file.close();
		return true;
	}
	throw filename;
	return false;
}

bool Clube::writeEmpresas(EMP_QUEUE empresas, string filename){
  std::ofstream file;
  file.open(filename.c_str());
  if(file.is_open()){
    EMP_QUEUE dummy = empresas;
    while(!dummy.empty()){
      std::stringstream ss;
      ss << dummy.top()->getNome() << " # ";
      ss << dummy.top()->getNIF() << " ";
      ss << dummy.top()->getLocalizacao() << " ";
      ss << dummy.top()->getContrato();
      file << ss.str();
      file << endl;
      vector <Servico *> serv = dummy.top()->getServicos();
      for(unsigned int k = 0; k < serv.size(); k++){
        file << serv[k]->titulo << std::endl;
        file << serv[k]->descricao << std::endl;
      }
      file << "--------\n";
      dummy.pop();
    }
    file.close();
    return true;
  }
  throw filename;
  return false;
}

bool Clube::readAll(){
  try{
    readData(FILE_DATA);
    readModalidades(FILE_MODALIDADES);
    readJogadores(FILE_JOGADORES);
    readSocios(FILE_SOCIOS);
    readDespesas(FILE_DESPESAS);
		readExternos(FILE_EXTERNOS);
    readEmpresas(FILE_EMPRESAS);
		readLugares(FILE_LUGARES);
  }
  catch(std::string file){
    iface->drawString("Unable to read file '"); iface->drawString(file); iface->drawString("'"); iface->newLine();
    return false;
  }
  return true;
}
bool Clube::writeAll(){
	try{
		writeModalidades(modalidades, FILE_MODALIDADES);
		writeJogadores(jogadores, FILE_JOGADORES);
		writeSocios(socios, FILE_SOCIOS);
		writeData(FILE_DATA);
		writeDespesas(FILE_DESPESAS);
		writeExternos(externos, FILE_EXTERNOS);
		writeLugares(FILE_LUGARES);
		writeEmpresas(empresas, FILE_EMPRESAS);
	}
	catch (std::string file){
		iface->drawString("Unable to write file '"); iface->drawString(file); iface->drawString("'"); iface->newLine();
		throw;
		return false;
	}
	return true;
}

#endif
