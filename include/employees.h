#ifndef EMPLOYEES_H
#define EMPLOYEES_H

struct employees
{
    char name[100];
    char position[100];
    int age , salary ;
};

class employee{
    char name[100];
    char position[100];
    int age , salary ;
    public:
    void setName(const char n[]){
        int i=0;
        while(n[i] !='\0'){
            name[i]=n[i];
            i++;
        }
        name[i]='\0';
    }
    void setPosition(const char p[]){
        int i=0;
        while(p[i]!='\0'){
            position[i]=p[i];
            i++;
        }
        position[i]='\0';
    }
    void setAge(int a){
        age=a;
    }
    void setSalary(int s){
        salary=s;
    }
    const char* getName()const{
        return name;
    }
    const char* getPostiton() const {
        return position;
    }
    int getAge() const {
        return age;
    }
    int getSalary() const{
        return salary;
    }

};

void enterEmployees(employees emp[],int size);
void viewEmployees(employees emp[]);
void enterEmployeeClass(employee emp[]);
void viewEmployeeClass(employee emp[]);
employees* enterEmployeesDynamic(employees* emp);
void viewEmployeesDynamic(employees* emp);
void addEmployeeStack();
void displayStack();
#endif