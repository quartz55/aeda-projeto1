#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){

    Clube clube;

    //Pessoa *p1 = new Pessoa("Joao Costa", 18, 0);
    //p1->setExterno();

    Jogador *p1 = new Jogador("Joao Costa", 18, 14702805);
    clube.addJogador(p1);
    Jogador *p2 = new Jogador("Joao Almeida", 19, 123123);
    clube.addJogador(p2);
    p2 = new Jogador("Hugo Almeida", 25, 592312);
    clube.addJogador(p2);
    p2 = new Jogador("Cardoso", 24, 292312);
    clube.addJogador(p2);
    p2 = new Jogador("Luisao", 94, 219234);
    clube.addJogador(p2);

    Modalidade *m1 = new Modalidade("Futebol");
    Modalidade *m2 = new Modalidade("Basket");

    clube.addModalidade(m1);
    clube.addModalidade(m2);
    p1->addModalidade(m1);
    p1->addModalidade(m2);

    SubModalidade *sub1 = new SubModalidade("Futebol Masculino", m1);
    SubModalidade *sub2 = new SubModalidade("Sub21", m1);

    clube.addSubModalidade(sub1);
    clube.addSubModalidade(sub2);
    p1->addSubModalidade(sub1);
    p1->addSubModalidade(sub2);

    clube.changeModalidade("Futebol", "Futibole");

    clube.changeSubModalidade("Sub21", "Sub19");

    clube.CRUD();

    return 0;
}
