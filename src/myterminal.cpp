#include <iostream>
#include <unistd.h>   // Provides Unix functions such as read
#include <termios.h>  // Used to control terminal settings
#include "myterminal.h"

char getch_linux() {
    char buf = 0; // Variable to store the input character
    struct termios old = {0}; // Structure to save current terminal settings
    // Save the current terminal settings
    tcgetattr(0, &old);
    // Disable Canonical Mode (do not wait for Enter key)
    old.c_lflag &= ~ICANON;
    // Disable Echo so typed characters are not displayed
    old.c_lflag &= ~ECHO;
    // Require at least one character to be read
    old.c_cc[VMIN] = 1;
    // No timeout while waiting for input
    old.c_cc[VTIME] = 0;
    // Apply the modified settings immediately
    tcsetattr(0, TCSANOW, &old);
    // Read a single character immediately from the keyboard
    read(0, &buf, 1);
    // Re-enable Canonical Mode
    old.c_lflag |= ICANON;
    // Re-enable Echo
    old.c_lflag |= ECHO;
    // Restore the terminal to its original settings
    tcsetattr(0, TCSADRAIN, &old);
    // Return the character that was read
    return buf;
}

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

// int choiceMenu(){
//     char byte1='q';
//     char byte2='q';
//     char byte3='q';
//     int counter =1;
//     do{
//         byte1= getch_linux();
//         if (byte1 == '\033') {
//             byte2=getch_linux();
//             byte3=getch_linux();
//             switch (byte3) {
//                 case 'A':
//                     if(counter=1){
//                         counter=3;
//                     }else{
//                         counter--;
//                     }
//                     break;

//                 case 'B':
//                     if(counter==3){
//                         counter=1;
//                     }else{
//                         counter++;
//                     }
//                     break;
//             }
//         }
       
//     }while(byte1 != 'q' && byte1 != 'Q'); 
//     return counter;

//     // Exit the program successfully
// }
