#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <ncurses.h>
#include <string>

class Interface{
    int X,Y;

    public:
    Interface();
    ~Interface();

    char readChar();
    string readString();

    void drawChar(char CHAR);
    void drawString(std::string STRING);
    void newLine();

    void cleanScr();
};

#endif
