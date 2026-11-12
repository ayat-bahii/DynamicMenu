#ifndef MYTERMINAL_H
#define MYTERMINAL_H

void gotoxy(int x, int y);
void setColor(int color);
void resetColor();
char getch_linux();
int choiceMenu();


namespace Colors
{
    const int BLACK   = 30;
    const int RED     = 31;
    const int GREEN   = 32;
    const int YELLOW  = 33;
    const int BLUE    = 34;
    const int MAGENTA = 35;
    const int CYAN    = 36;
    const int WHITE   = 37;
}

#endif