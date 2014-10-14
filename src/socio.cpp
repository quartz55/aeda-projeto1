#include "socio.h"

Socio::Socio(string nome, unsigned int idade, unsigned long NIF):Jogador(nome,idade,NIF){
    this->classe = "Socio";
}
