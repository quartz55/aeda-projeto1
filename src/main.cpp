#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){

    Clube clube;

    Socio *p1 = new Socio("Joao Costa", 18, 14702805, "Macho");
    clube.addJogador(p1);
    Socio *p2 = new Socio("Joao Almeida", 19, 123123, "Macho");
    clube.addJogador(p2);
    p2 = new Socio("Hugo Almeida", 25, 592312, "Macho");
    clube.addJogador(p2);
    p2 = new Socio("Cardoso", 24, 292312, "Femea");
    clube.addJogador(p2);
    p2 = new Socio("Luisao", 94, 219234, "Femea");
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
