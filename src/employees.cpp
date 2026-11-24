#include <iostream>
#include "employees.h"
#include "myterminal.h"
#include "stack.h"
#define x 10
#define y 5
using namespace std;


bool isValidName(const char name[]){
    if(name[0] == '\0')
        return false;

    for(int i = 0; name[i] != '\0'; i++){
        if(!((name[i] >= 'A' && name[i] <= 'Z') ||
             (name[i] >= 'a' && name[i] <= 'z')))
        {
            return false;
        }
    }

    return true;
}
void enterEmployees(employees emp[],int size){
    cout << "\033[2J\033[1;1H";
    cin.clear();
    cout << "=== Enter 5 Employees Info ===\n";
    for(int i=0 ;i<size;i++){
        cout<<"Enter Employee name " <<i+1<< " : ";
        cin>>emp[i].name;
        while(!isValidName(emp[i].name)){
            cout<<"Enter Characters only"<<"\n";
            cin>>emp[i].name;
        }
        cout<<"Enter Employee posititon " <<i+1<< " : ";
        cin>>emp[i].position;
        while(!isValidName(emp[i].position)){
            cout<<"Enter Characters only"<<"\n";
            cin>>emp[i].position;
        }
        cout<<"Enter Employee age " <<i+1<< " : ";
        cin>>emp[i].age;
        while (emp[i].age<=0||emp[i].age>=70)
        {
            cout<<"Enter Valid Age"<<"\n";
            cin>>emp[i].age;
        }
        cout<<"Enter Employee salary " <<i+1<< " : ";
        cin>>emp[i].salary;
        while (emp[i].salary<=0||emp[i].salary>=500000)
        {
            cout<<"Enter Valid Salary"<<"\n";
            cin>>emp[i].salary;
        }
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
        while(!isValidName(tmpname)){
            cout<<"Enter Characters only"<<"\n";
            cin>>tmpname;
        }
        emp[i].setName(tmpname);
        cout<<"Enter Employee posititon " <<i+1<< " : ";
        cin>>tmppos;
        while(!isValidName(tmppos)){
            cout<<"Enter Characters only"<<"\n";
            cin>>tmppos;
        }
        emp[i].setPosition(tmppos);
        cout<<"Enter Employee age " <<i+1<< " : ";
        cin>>tmpage;
        while (tmpage<=0||tmpage>=70)
        {
            cout<<"Enter Valid Age"<<"\n";
            cin>>tmpage;
        }
        emp[i].setAge(tmpage);
        cout<<"Enter Employee salary " <<i+1<< " : ";
        cin>>tmpsal;
        while (tmpsal<=0||tmpsal>=500000)
        {
            cout<<"Enter Valid Salary"<<"\n";
            cin>>tmpsal;
        }
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
int capacity=2;
int counter=0;
employees* enterEmployeesDynamic(employees* emp){
    cout << "\033[2J\033[1;1H";
    cin.clear();
    if (emp == nullptr) {
        emp = new employees[capacity];
    }
    cout<<"How Many Employees ? ";
    cin>>number;
    while(number<=0){
        cout<<"Please Enter Positive number"<<"\n";
        cin>>number;
    }
    int total=number+counter;
    for(int i=counter;i<total;i++){
        if(counter==capacity){
            capacity*=2;
            employees *ptr=new employees[capacity];
            for(int j=0;j<counter;j++){
                ptr[j]=emp[j];
            }
            delete[] emp;
            emp=ptr;
        }
        cout<<"Enter Employee name " <<i+1<< " : ";
        cin>>emp[i].name;
        while(!isValidName(emp[i].name)){
            cout<<"Enter Characters only"<<"\n";
            cin>>emp[i].name;
        }
        cout<<"Enter Employee posititon " <<i+1<< " : ";
        cin>>emp[i].position;
        while(!isValidName(emp[i].position)){
            cout<<"Enter Characters only"<<"\n";
            cin>>emp[i].position;
        }
        cout<<"Enter Employee age " <<i+1<< " : ";
        cin>>emp[i].age;
        while (emp[i].age<=0||emp[i].age>=70)
        {
            cout<<"Enter Valid Age"<<"\n";
            cin>>emp[i].age;
        }
        cout<<"Enter Employee salary " <<i+1<< " : ";
        cin>>emp[i].salary;
        while (emp[i].salary<=0||emp[i].salary>=500000)
        {
            cout<<"Enter Valid Salary"<<"\n";
            cin>>emp[i].salary;
        }
        counter++;
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

    for(int i=0;i<counter;i++){

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
Stack emp;
void addEmployeeStack(){
    cout << "\033[2J\033[1;1H";
    cin.clear();
    
    int size=0;
    cout<<"Enter Number of Employees: ";
    cin>>size;
    
    employee* emparr=new employee[size];
    for(int i=0;i<size;i++){
        char tmpname[100];
        char tmppos[100];
        int tmpage=0,tmpsal=0;
        cout<<"Enter Employee name " <<i+1<< " : ";
        cin>>tmpname;
        while(!isValidName(tmpname)){
            cout<<"Enter Characters only"<<"\n";
            cin>>tmpname;
        }
        emparr[i].setName(tmpname);
        cout<<"Enter Employee posititon " <<i+1<< " : ";
        cin>>tmppos;
        while(!isValidName(tmppos)){
            cout<<"Enter Characters only"<<"\n";
            cin>>tmppos;
        }
        emparr[i].setPosition(tmppos);
        cout<<"Enter Employee age " <<i+1<< " : ";
        cin>>tmpage;
        while (tmpage<=0||tmpage>=70)
        {
            cout<<"Enter Valid Age"<<"\n";
            cin>>tmpage;
        }
        emparr[i].setAge(tmpage);
        cout<<"Enter Employee salary " <<i+1<< " : ";
        cin>>tmpsal;
        while (tmpsal<=0||tmpsal>=500000)
        {
            cout<<"Enter Valid Salary"<<"\n";
            cin>>tmpsal;
        }
        emparr[i].setSalary(tmpsal);
        emp.push(emparr[i]);
    }
    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;

    
    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }
}

void displayStack(){
    cout << "\033[2J\033[1;1H";

    
    emp.display();
    
    cout << "\n=========================================" << endl;
    cout<< "Press [Esc] to return to menu "<<flush;


    char ch = 0;
    while (ch != 27) 
    { 
        ch = getch_linux();
    }

}

