#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

//DATA
const string FILE_JOGADORES = "txt/jogadores.txt";
const string FILE_MODALIDADES = "txt/modalidades.txt";
const string FILE_SOCIOS = "txt/socios.txt";

int main(){

    Clube clube;

    clube.readModalidades(FILE_MODALIDADES);
    clube.readJogadores(FILE_JOGADORES);
    clube.readSocios(FILE_SOCIOS);

    clube.listarModalidades();
    clube.listarJogadores();

    clube.getJogadores()[0]->showInfo();

    //clube.CRUD();
    clube.writeModalidades(clube.getMods(), FILE_MODALIDADES);
    clube.writeJogadores(clube.getJogadores(), FILE_JOGADORES);
    clube.writeSocios(clube.getSocios(), FILE_SOCIOS);

    return 0;
}
