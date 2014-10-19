#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){

    Clube clube;

    clube.readModalidades();
    clube.readJogadores();

    clube.listarModalidades();
    clube.listarJogadores();

    clube.getJogadores()[0]->showInfo();

    //clube.CRUD();
    clube.writeModalidades(clube.getMods());
    clube.writeJogadores(clube.getJogadores());

    return 0;
}
