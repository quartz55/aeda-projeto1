#include "jogador.h"

Jogador::Jogador(string nome, unsigned int idade, unsigned long NIF, string sexo):Pessoa(nome,idade,NIF, sexo){
    this->classe = "Jogador";
}
void Jogador::showInfo() const{
    Pessoa::showInfo();
    cout << "--------------------------------------------\n";
    showSubModalidades();
    cout << "--------------------------------------------\n";
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

void Jogador::showModalidades() const{
    if(modalidades.size() < 1) cout << "O jogador " << nome << " nao pertence a nenhuma modalidade\n";
    else{
        cout << "Modalidades de " << nome << std::endl;
        cout << "--------------------------\n";
        for(unsigned int i = 0; i<modalidades.size(); i++){
            cout << "» " << modalidades[i]->getNome() << std::endl;
        }
    }
}

void Jogador::showSubModalidades() const{
    if(modalidades.size() < 1) cout << "O jogador " << nome << " nao pertence a nenhuma modalidade\n";
    else{

        cout << "Modalidades e sub-modalidades de " << nome << std::endl;
        cout << "--------------------------------------------\n";
        for(unsigned int i = 0; i < modalidades.size(); i++){
            cout << "» "<< modalidades[i]->getNome() << std::endl;
            for(unsigned int k = 0; k < sub_modalidades.size(); k ++)
                if(sub_modalidades[k]->getMod()->getNome() == modalidades[i]->getNome())
                    cout << "   -" << sub_modalidades[k]->getNome() << std::endl;
        }
    }
}


