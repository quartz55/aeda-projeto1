#include "socio.h"

Socio::Socio(string nome, unsigned int idade, unsigned long NIF, string sexo):Jogador(nome,idade,NIF, sexo){
    this->classe = "Socio";
}
