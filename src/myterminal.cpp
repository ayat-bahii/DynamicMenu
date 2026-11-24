#include <iostream>
#include "myterminal.h"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>

    // Translates Windows arrow keys into Linux arrow keys
    char getch_linux() {
        // Enables ANSI colors and gotoxy on Windows automatically
        static bool initialized = false;
        if (!initialized) {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
            initialized = true;
        }

        static int step = 0;
        static char savedArrow = 0;

        // If an arrow key was pressed, feed '[' then 'A'/'B' on the next calls
        if (step == 1) {
            step = 2;
            return '[';
        }
        if (step == 2) {
            step = 0;
            return savedArrow;
        }

        int ch = _getch();
        if (ch == 0 || ch == 224) { // Windows arrow key prefix
            int arrow = _getch();
            if (arrow == 72) {      // Windows Up Arrow
                step = 1;
                savedArrow = 'A';
                return '\033';
            }
            if (arrow == 80) {      // Windows Down Arrow
                step = 1;
                savedArrow = 'B';
                return '\033';
            }
        }
        return (char)ch;
    }

#else
    #include <unistd.h>
    #include <termios.h>

    char getch_linux() {
        char buf = 0;
        struct termios old = {0};
        tcgetattr(0, &old);
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        tcsetattr(0, TCSANOW, &old);
        read(0, &buf, 1);
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        tcsetattr(0, TCSADRAIN, &old);
        return buf;
    }
#endif

void gotoxy(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
    std::cout.flush();
}

void setColor(int color) {
    std::cout << "\033[" << color << "m";
    std::cout.flush();
}

void resetColor() {
    std::cout << "\033[0m";
    std::cout.flush();
}
