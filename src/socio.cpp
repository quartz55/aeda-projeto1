#include "socio.h"
#include <algorithm>

Socio::Socio(string nome, unsigned int idade, unsigned long NIF, string sexo):Jogador(nome,idade,NIF, sexo){
	this->classe = "Socio";
}

bool Socio::addModalidade(Modalidade* mod, int mes, int ano) {
	Quota* quota = new Quota(mes,ano, mod, mod->getPrecoQuota());
	quotas.push_back(quota);
	return Jogador::addModalidade(mod);
}

int Socio::QuotasAtrasadas(Data dataActual, Modalidade * mod) {
    int meses_atrasados = 0;
    if(mod == NULL){
    	for(size_t i = 0; i < quotas.size(); i++){
    		if(dataActual.getDay() <= 8){
    			if(quotas[i]->getLastPayed()->getMonth() < dataActual.getMonth() - 1 && quotas[i]->getLastPayed()->getYear() <= dataActual.getYear() ){
    				meses_atrasados = 1;
    				return meses_atrasados;
    			}
    		}
    		else{
    			if(quotas[i]->getLastPayed()->getMonth() < dataActual.getMonth() && quotas[i]->getLastPayed()->getYear() <= dataActual.getYear()){
    				meses_atrasados = 1;
    				return meses_atrasados;
    			}
    		}
    	}
    }
    for(size_t i = 0; i < quotas.size(); i++){
    	if(quotas[i]->getModalidade() == mod){
    		if(dataActual.getDay() <= 8){
    			if(*quotas[i]->getLastPayed() < dataActual){
    				meses_atrasados = dataActual.getMonth() - 1 - quotas[i]->getLastPayed()->getMonth() + 12 *(dataActual.getYear() - quotas[i]->getLastPayed()->getYear());
    			}
    		}
    		else{
    			if(*quotas[i]->getLastPayed() < dataActual){
    				meses_atrasados = dataActual.getMonth() - quotas[i]->getLastPayed()->getMonth() + 12 *(dataActual.getYear() - quotas[i]->getLastPayed()->getYear());
    			}
    		}
    	}
    }
    return meses_atrasados;
}

float Socio::pagarQuotas(int meses,Data dataActual, bool pagar, Modalidade *mod) {
    float total = 0;
    float multa = 0;
    if(QuotasAtrasadas(dataActual, mod) >= meses){
        multa = 5*meses;
    }
    else{
        multa = QuotasAtrasadas(dataActual, mod)*5;
    }
    for(size_t i = 0; i < quotas.size(); i++){
    	if(mod == quotas[i]->getModalidade()){
    		total += quotas[i]->getPreco();
    		if(pagar) quotas[i]->pagarQuota(meses);
    	}
    }
    if(modalidades.size() >= 3){
        total *= 0.95*meses;
    }
    return total + multa;
}

bool Socio::removeQuota(Modalidade* mod) {
    for(size_t i = 0;i < quotas.size(); i++){
        if(quotas[i]->getModalidade() == mod){
            quotas.erase(quotas.begin()+i);
            return true;
        }
    }
    return false;
}

string Socio::showInfo() const {
	std::stringstream ss;
	ss << Jogador::showInfo();
	ss << "Ultimas quotas pagas: \n\n";
	if(quotas.size() >0) {
		for(size_t i = 0; i < quotas.size(); i++){
			ss << quotas[i]->showQuota() << "\n";
		}
		ss << "\n \n";
	}
	return ss.str();
}

bool Socio::supportsMod(string modalidade) {
	std::transform(modalidade.begin(), modalidade.end(), modalidade.begin(), ::tolower);
	for(unsigned int i = 0; i < modalidades.size(); i++){
		string data = modalidades[i]->getNome();
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
		if(data == modalidade){
			return true;
		}
	}
	return false;
}
