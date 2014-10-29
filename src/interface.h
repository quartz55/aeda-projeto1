#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <ncurses.h>
#include <string>
#include <sstream>


class Interface{
    int X,Y;

    public:
    Interface();
    ~Interface();

    template<typename Type>
    void readChar(Type &var);

    void readLine(std::string &STRING);

    template<typename Type>
    void read(Type &var);

    void drawChar(char CHAR);
    void drawString(std::string STRING);
    void newLine();

    void cleanScr();
};

template<typename Type>
void Interface::readChar(Type &var){
    var = getch();
}

template<typename Type>
void Interface::read(Type &var){
    char *input = new char;
    getstr(input);
    std::stringstream s(input);
    s >> var;
}


#endif
