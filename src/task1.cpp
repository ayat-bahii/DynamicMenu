#include <iostream>
#include "myterminal.h"
#include "employees.h"
#include "stack.h"

using namespace std;


void viewMenu();


int main()
{    
    
    viewMenu();
    return 0;
   
}




void viewMenu(){

    int arr[3] = {Colors::WHITE, Colors::WHITE, Colors::WHITE};
    employees empList[5]; 
    employee  empList2[5];
    employees* emplist3;
    char byte1=0;
    char byte2=0;
    char byte3=0;
    bool inputData = false;
    int counter =1;
    int x = 10 , y =5;

    while(byte1 != 'q' && byte1 != 'Q'){  

        switch (counter) {
        case 1:
            arr[0] = Colors::YELLOW;
            arr[1] = Colors::WHITE;
            arr[2] = Colors::WHITE;
            break;
        case 2:
            arr[1] = Colors::YELLOW;
            arr[0] = Colors::WHITE;
            arr[2] = Colors::WHITE;
            break;
        case 3:
            
            arr[2] = Colors::YELLOW;
            arr[0] = Colors::WHITE;
            arr[1] = Colors::WHITE;
            break;
        }
        
        gotoxy(x, y);
        setColor(arr[0]);
        cout << "News" ;
        gotoxy(x,y+1);
        setColor(arr[1]);
        cout << "Display" ;
        gotoxy(x,y+2);
        setColor(arr[2]);
        cout << "Exit";

        gotoxy(x - 1, y + (counter - 1));
        cout<<flush;

        byte1= getch_linux();
        if (byte1 == '\033') {
            byte2=getch_linux();
            byte3=getch_linux();
            switch (byte3) {
                case 'A':
                    if(counter==1){
                        counter=3;
                    }else{
                        counter--;

                    }
                    break;

                case 'B':
                    if(counter==3){
                        counter=1;

                    }else{
                        counter++;

                    }
                    break;
                
            }
        }  
        
        if(byte1=='\n' || byte1=='\r'){
           
            if(counter==1){
                //enterEmployees(empList,5);
                //enterEmployeeClass(empList2);
                //emplist3=enterEmployeesDynamic();
                addEmployeeStack();
                inputData=true;
                cout << "\033[2J\033[1;1H";
            }
            if(counter==2){
                
                if(inputData){
                    //viewEmployees(empList);
                    //viewEmployeeClass(empList2);
                    //viewEmployeesDynamic(emplist3);
                    displayStack();
                    cout << "\033[2J\033[1;1H";
                }else{
                    cout << "\033[2J\033[1;1H";    
                    cout<<"=====No Data Added yet====";

                }
                 
            }
            if(counter==3){
                byte1='q';
            }
        }
    
    }
    
}

