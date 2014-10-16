#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){

    Clube clube;

    clube.readModalidades();

    clube.listarModalidades();

    //clube.CRUD();
    clube.writeModalidades(clube.getMods());
    //clube.writeJogadores(clube.getJogadores());

    return 0;
}
