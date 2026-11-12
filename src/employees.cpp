#include <iostream>
#include "employees.h"
#include "myterminal.h"
#define x 10
#define y 5
using namespace std;


// struct employees{
//     char name[100];
//     char position[100];
//     int age , salary ;
// };

void enterEmployees(employees emp[],int size){
    cout << "\033[2J\033[1;1H";
    cin.clear();
    cout << "=== Enter 5 Employees Info ===\n";
    for(int i=0 ;i<size;i++){
        cout<<"Enter Employee name " <<i+1<< " : ";
        cin>>emp[i].name;
        cout<<"Enter Employee posititon " <<i+1<< " : ";
        cin>>emp[i].position;
        cout<<"Enter Employee age " <<i+1<< " : ";
        cin>>emp[i].age;
        cout<<"Enter Employee salary " <<i+1<< " : ";
        cin>>emp[i].salary;
    }
    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;

    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }
}

void viewEmployees(employees emp[]){
    cout << "\033[2J\033[1;1H";
    for(int i=0;i<5;i++){
        cout<<"========Employee"<<i+1<<"========="<<endl;
        cout<<"Name: "<<emp[i].name<<"\n";
        cout<<"Position: "<<emp[i].position<<"\n";
        cout<<"Age: "<<emp[i].age<<"\n";
        cout<<"Salary: $"<<emp[i].salary<<"\n";
    }

    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;


    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }
   
}


void enterEmployeeClass(employee emp[]){
    cout << "\033[2J\033[1;1H";
    cin.clear();
    cout << "=== Enter 5 Employees Info ===\n";
    for(int i =0;i<5;i++){
        char tmpname[100];
        char tmppos[100];
        int tmpage=0,tmpsal=0;
        cout<<"Enter Employee name " <<i+1<< " : ";
        cin>>tmpname;
        emp[i].setName(tmpname);
        cout<<"Enter Employee posititon " <<i+1<< " : ";
        cin>>tmppos;
        emp[i].setPosition(tmppos);
        cout<<"Enter Employee age " <<i+1<< " : ";
        cin>>tmpage;
        emp[i].setAge(tmpage);
        cout<<"Enter Employee salary " <<i+1<< " : ";
        cin>>tmpsal;
        emp[i].setSalary(tmpsal);
    }
    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;

    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }
}

void viewEmployeeClass(employee emp[]){
    cout << "\033[2J\033[1;1H";
    for(int i=0;i<5;i++){
        cout<<"========Employee"<<i+1<<"========="<<endl;
        cout<<"Name: "<<emp[i].getName()<<"\n";
        cout<<"Position: "<<emp[i].getPostiton()<<"\n";
        cout<<"Age: "<<emp[i].getAge()<<"\n";
        cout<<"Salary: $"<<emp[i].getSalary()<<"\n";
    }

    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;

    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }
   
}

int number=0;

employees* enterEmployeesDynamic(){
    cout << "\033[2J\033[1;1H";
    cin.clear();
    
    cout<<"How Many Employees ? ";
    cin>>number;
    employees* emp= new employees[number];
    for(int i=0;i<number;i++){
        cout<<"Enter Employee name " <<i+1<< " : ";
        cin>>emp[i].name;
        cout<<"Enter Employee posititon " <<i+1<< " : ";
        cin>>emp[i].position;
        cout<<"Enter Employee age " <<i+1<< " : ";
        cin>>emp[i].age;
        cout<<"Enter Employee salary " <<i+1<< " : ";
        cin>>emp[i].salary;
    }
    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;
    
    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }
    return emp;
}


void viewEmployeesDynamic(employees* emp){
    
    cout << "\033[2J\033[1;1H";

    for(int i=0;i<number;i++){

        cout<<"========Employee"<<i+1<<"========="<<endl;
        cout<<"Name: "<<emp[i].name<<"\n";
        cout<<"Position: "<<emp[i].position<<"\n";
        cout<<"Age: "<<emp[i].age<<"\n";
        cout<<"Salary: $"<<emp[i].salary<<"\n";
    }

    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;


    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }
   
}