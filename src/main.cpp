#include <iostream>

#include "clube.h"


using std::cout; using std::cin;

int main(){
    Socio p1("Joao Costa", 18, 14702805);
    p1.showInfo();

    cout << "------------\nChanging Info...\n------------\n";

    p1.changeNome("Rui Vilares");
    p1.changeIdade(19);
    p1.changeNIF(0000000);

    p1.showInfo();
    return 0;
}
