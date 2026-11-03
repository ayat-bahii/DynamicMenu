#include <iostream>
#include "myterminal.h"

int main()
{
    gotoxy(10, 5);
    setColor(Colors::YELLOW);
    std::cout << "Menu" << std::endl;
    resetColor();
    gotoxy(10, 6);
    std::cout << "Home" << std::endl;
    gotoxy(10, 7);
    std::cout << "Exit" << std::endl;
    return 0;
}
