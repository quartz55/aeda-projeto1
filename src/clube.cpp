#include "clube.h"

Clube::Clube(){};

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
