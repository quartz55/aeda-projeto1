#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){
    Jogador p1("Joao Costa", 18, 14702805);
    p1.showInfo();

    Modalidade *m1 = new Modalidade("Futebol");
    Modalidade *m2 = new Modalidade("Basket");

    p1.addModalidade(m1);
    p1.addModalidade(m2);

    SubModalidade *sub1 = new SubModalidade("Futebol Masculino", m1);
    SubModalidade *sub2 = new SubModalidade("Sub21", m1);

    SubModalidade *sub3 = new SubModalidade("Basket Feminino", m2);
    SubModalidade *sub4 = new SubModalidade("Basket Juniors", m2);
    p1.addSubModalidade(sub1);
    p1.addSubModalidade(sub2);
    p1.addSubModalidade(sub3);
    p1.addSubModalidade(sub4);

    cout << std::endl;

    p1.showModalidades();

    cout << std::endl;

    p1.showSubModalidades();


    return 0;
}
