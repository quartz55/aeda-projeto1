#include "interface.h"

using std::string;

Interface::Interface(){
    this->X = 0;
    this->Y = 0;
    initscr();
    move(X,Y);
}

Interface::~Interface(){
    endwin();
}

void Interface::drawChar(char CHAR){
    mvaddch(CHAR,Y,X);
    getyx(stdscr, Y,X);
    refresh();
}
void Interface::drawString(string STRING){
    const char *STR = STRING.c_str();
    mvaddstr(Y,X,STR);
    getyx(stdscr, Y, X);
    refresh();
}

void Interface::cleanScr(){
    clear();
    refresh();
    this->X = 0;
    this->Y = 0;
}
void Interface::newLine(){
    this->Y++;
    this->X = 0;
}

char Interface::readChar(){
    return getch();
}

