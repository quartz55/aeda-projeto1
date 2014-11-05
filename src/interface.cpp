#include "interface.h"
#include <stdlib.h>

using std::string;

//NCURSES
//Interface::Interface(){
    //this->X = 0;
    //this->Y = 0;
    //initscr();
    //clear();
    //cbreak();
    //move(X,Y);
    //cleanScr();
//}

//Interface::~Interface(){
    //endwin();
//}

//void Interface::drawChar(char CHAR){
    //mvaddch(CHAR,Y,X);
    //getyx(stdscr, Y,X);
    //refresh();
//}
//void Interface::drawString(string STRING){
    //const char *STR = STRING.c_str();
    //mvaddstr(Y,X,STR);
    //getyx(stdscr, Y, X);
    //refresh();
//}

//void Interface::readLine(std::string &STRING){
    //char *STR = new char;
    //getstr(STR);
    //STRING = std::string(STR);
//}

//void Interface::cleanScr(){
    //clear();
    //refresh();
    //this->X = 0;
    //this->Y = 2;
//}
//void Interface::newLine(){
    //this->Y++;
    //this->X = 0;
//}

//IOSTREAM
Interface::Interface(){
}

Interface::~Interface(){
}

void Interface::getInput(){
    std::cin.get();
}

void Interface::drawChar(char CHAR){
    std::cout << CHAR;
}

void Interface::readLine(std::string &STRING){
    //std::cin.get();
    getline(std::cin, STRING);
}

void Interface::cleanScr(){
	#ifdef _WIN32 // Windows: Console command (alternative: Windows API)
	system("cls");
	#else // UNIX: ANSI escape codes
	std::cout << "\x1B[2J\x1B[H";
	#endif
}
void Interface::newLine(){
    std::cout << std::endl;
}

