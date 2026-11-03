#include <iostream>
#include "myterminal.h"


void gotoxy(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "H"; //ANSI Escape Sequence
    std::cout.flush();
}

void setColor(int color)
{
    std::cout << "\033[" << color << "m";
    std::cout.flush();
}

void resetColor()
{
    std::cout << "\033[0m";
    std::cout.flush();
}
