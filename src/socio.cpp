#include "socio.h"

Socio::Socio(string nome, unsigned int idade, unsigned long NIF, string sexo):Jogador(nome,idade,NIF, sexo){
	this->classe = "Socio";
}

bool Socio::addModalidade(Modalidade* mod, int mes, int ano) {
	Quota* quota = new Quota(mes,ano,mod);
	quotas.push_back(quota);
	return Jogador::addModalidade(mod);
}

int Socio::QuotasAtrasadas(Data dataActual, Modalidade *mod) {
	int meses_atrasados = 0;
	for(size_t i  = 0; i < quotas.size();i++){
		if(quotas[i]->getModalidade() == mod){
			if(dataActual.getDay() <= 8){
				if(quotas[i]->getLastPayed()->getMonth() < dataActual.getMonth() - 1){
					meses_atrasados = dataActual.getMonth() - 1 - quotas[i]->getLastPayed()->getMonth();
					break;
				}
			}
			else{
				if(quotas[i]->getLastPayed()->getMonth() < dataActual.getMonth()){
					meses_atrasados = dataActual.getMonth() - quotas[i]->getLastPayed()->getMonth();
					break;
				}
			}
		}
	}
	return meses_atrasados;
}

float Socio::pagarQuotas(int meses,Data dataActual, Modalidade *mod) {
	float total = 0;
	float multa = 0;
	for(size_t i = 0; i < quotas.size(); i++){
		if(quotas[i]->getModalidade() == mod){
			total += quotas[i]->getPreco();
			multa = 5*QuotasAtrasadas(dataActual,mod);
		}
	}
	if(modalidades.size() >= 3){
		total *= 0.95;
	}
	return total + multa;
}
