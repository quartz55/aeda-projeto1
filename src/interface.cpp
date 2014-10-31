#include "interface.h"
#include <iostream>

using std::string;

Interface::Interface(){
    //this->X = 0;
    //this->Y = 0;
    //initscr();
    //clear();
    //cbreak();
    //move(X,Y);
    //cleanScr();
}

Interface::~Interface(){
    //endwin();
}

void Interface::drawChar(char CHAR){
    //mvaddch(CHAR,Y,X);
    //getyx(stdscr, Y,X);
    //refresh();
    std::cout << CHAR;
}
void Interface::drawString(string STRING){
    //const char *STR = STRING.c_str();
    //mvaddstr(Y,X,STR);
    //getyx(stdscr, Y, X);
    //refresh();
    std::cout << STRING;
}

void Interface::readLine(std::string &STRING){
    //char *STR = new char;
    //getstr(STR);
    //STRING = std::string(STR);
    getline(std::cin, STRING);
}

void Interface::cleanScr(){
    //clear();
    //refresh();
    //this->X = 0;
    //this->Y = 2;
    for(unsigned int i = 0; i < 100; i++)
        std::cout << std::endl;
}
void Interface::newLine(){
    //this->Y++;
    //this->X = 0;
    std::cout << std::endl;
}

