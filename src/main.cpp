#include "clube.h"

int main(){

    Clube clube;

	if (clube.readAll())
		clube.CRUD();
	system("PAUSE");
    return 0;
}
