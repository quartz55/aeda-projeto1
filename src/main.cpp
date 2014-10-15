#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){

    Clube clube;

    Jogador *p1 = new Jogador("Joao Costa", 18, 14702805, "Macho");
    clube.addJogador(p1);
    Jogador *p2 = new Jogador("Joao Almeida", 19, 123123, "Macho");
    clube.addJogador(p2);
    p2 = new Jogador("Hugo Almeida", 25, 592312, "Macho");
    clube.addJogador(p2);
    p2 = new Jogador("Cardoso", 24, 292312, "Femea");
    clube.addJogador(p2);
    p2 = new Jogador("Luisao", 94, 219234, "Femea");
    clube.addJogador(p2);

    //clube.CRUD();
    clube.listarPessoas();

    return 0;
}
