#include "jogador.h"

Jogador::Jogador(string nome, unsigned int idade, unsigned long NIF, string sexo):Pessoa(nome,idade,NIF, sexo){
    this->classe = "Jogador";
}
string Jogador::showInfo() const{
    std::stringstream s;
    s << Pessoa::showInfo();
    s << "--------------------------------------------\n";
    s << showSubModalidades();
    s << "--------------------------------------------\n";
    return s.str();
}

bool Jogador::addModalidade(Modalidade *mod){
    for(unsigned int i = 0; i<modalidades.size(); i++)
        if(mod->getNome() == modalidades[i]->getNome())
            return false;
    modalidades.push_back(mod);
    return true;
}

bool Jogador::addSubModalidade(SubModalidade *sub){
    //Verificar se o jogador ja pertence a submodalidade
    for(unsigned int i = 0; i<sub_modalidades.size(); i++)
        if(sub->getNome() == sub_modalidades[i]->getNome())
            return false;

    Modalidade *m1 = sub->getMod(); //Modalidade da sub-modalidade

    bool modExiste = false;

    //Verificar se o jogador pertence a modalidade da sub-modalidade
    for(unsigned int i = 0; i<modalidades.size();i++)
        if(m1->getNome() == modalidades[i]->getNome())
            modExiste = true;

    //Se nao pertence, adiciona modalidade as modalidades do jogador
    if(!modExiste)
        addModalidade(m1);

    //Adiciona submodalidade
    sub_modalidades.push_back(sub);

    return true;
}

string Jogador::showModalidades() const{
    std::stringstream s;
    if(modalidades.size() < 1) s << "O " << classe << " " << nome << " nao pertence a nenhuma modalidade\n";
    else{
        s << "Modalidades de " << nome << std::endl;
        s << "--------------------------\n";
        for(unsigned int i = 0; i<modalidades.size(); i++){
            s << "> " << modalidades[i]->getNome() << std::endl;
        }
    }
    return s.str();
}

string Jogador::showSubModalidades() const{
    std::stringstream s;
    if(modalidades.size() < 1) s << nome << " nao pertence a nenhuma modalidade\n";
    else{

        s << "Modalidades e sub-modalidades de " << nome << std::endl;
        s << "--------------------------------------------\n";
        for(unsigned int i = 0; i < modalidades.size(); i++){
            s << "> "<< modalidades[i]->getNome() << std::endl;
            for(unsigned int k = 0; k < sub_modalidades.size(); k ++)
                if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome())
                    s << "   -" << sub_modalidades[k]->getNome() << std::endl;
        }
    }
    return s.str();
}

bool Jogador::removeModalidade(Modalidade *mod)
{
	for (size_t i = 0; i < modalidades.size(); i++)
	{
		if (modalidades[i] == mod)
		{
			modalidades.erase(modalidades.begin() + i);
			return true;
		}
	}
	return false;
}

bool Jogador::removeSubModalidade(SubModalidade *mod)
{
	for (size_t i = 0; i < sub_modalidades.size(); i++)
	{
		if (sub_modalidades[i] == mod)
		{
			sub_modalidades.erase(sub_modalidades.begin() + i);
			return true;
		}
	}
	return false;
}

