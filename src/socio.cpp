#include "socio.h"

Socio::Socio(string nome, unsigned int idade, unsigned long NIF, string sexo):Jogador(nome,idade,NIF, sexo){
	this->classe = "Socio";
}

bool Socio::addModalidade(Modalidade* mod, int mes, int ano) {
	float preco = mod->getPrecoQuota();
	Quota* quota = new Quota(mes,ano, mod, preco);
	quotas.push_back(quota);
	return Jogador::addModalidade(mod);
}

int Socio::QuotasAtrasadas(Data dataActual) {
    int meses_atrasados = 0;
    if(quotas.size() > 0){
        if(dataActual.getDay() <= 8){
            if(quotas[0]->getLastPayed()->getMonth() < dataActual.getMonth() - 1){
                meses_atrasados = dataActual.getMonth() - 1 - quotas[0]->getLastPayed()->getMonth();
            }
        }
        else{
            if(quotas[0]->getLastPayed()->getMonth() < dataActual.getMonth()){
                meses_atrasados = dataActual.getMonth() - quotas[0]->getLastPayed()->getMonth();
            }
        }
    }
    return meses_atrasados;
}

float Socio::pagarQuotas(int meses,Data dataActual) {
    float total = 0;
    float multa = 0;
    if(QuotasAtrasadas(dataActual) >= meses){
        multa = 5*meses;
    }
    else{
        multa = QuotasAtrasadas(dataActual)*5;
    }
    for(size_t i = 0; i < quotas.size(); i++){
        total += quotas[i]->getPreco();
        quotas[i]->pagarQuota(meses);
    }
    if(modalidades.size() >= 3){
        total *= 0.95;
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
			ss << quotas[i]->getModalidade()->getNome() << " : " << quotas[i]->getLastPayed()->showData() << "\n";
		}
		ss << "\n \n";
	}
	return ss.str();
}
