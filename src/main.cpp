#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){

    Clube clube;

    Jogador *p1 = new Jogador("Joao Costa", 18, 14702805);
    clube.addJogador(p1);
    p1->showInfo();

    Modalidade *m1 = new Modalidade("Futebol");
    Modalidade *m2 = new Modalidade("Basket");

    clube.addModalidade(m1);
    clube.addModalidade(m2);
    p1->addModalidade(m1);
    p1->addModalidade(m2);

    p1->showModalidades();


    SubModalidade *sub1 = new SubModalidade("Futebol Masculino", m1);
    SubModalidade *sub2 = new SubModalidade("Sub21", m1);

    clube.addSubModalidade(sub1);
    clube.addSubModalidade(sub2);
    p1->addSubModalidade(sub1);
    p1->addSubModalidade(sub2);

    p1->showSubModalidades();

    clube.changeModalidade("Futebol", "Futibul");

    p1->showSubModalidades();

    clube.changeSubModalidade("Sub21", "Sub19");

    p1->showSubModalidades();

    //cout << std::endl;

    //p1.showModalidades();

    //cout << std::endl;

    //p1.showSubModalidades();


    return 0;
}
