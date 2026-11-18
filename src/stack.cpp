#include "stack.h"
using namespace std;

Stack::Stack()
{
    
    this->sizeArray=10;
    this->top=-1;
    this->arr=new employee[sizeArray];
    //ctor
}
Stack::Stack(Stack & s)
{
 
    this->arr=new employee[s.sizeArray];
    this->sizeArray=s.sizeArray;
    this->top=s.top;
    for(int i=0; i<=s.top; i++){
        this->arr[i]=s.arr[i];
    }

}
Stack::Stack(int sizeArray)
{
   
    this->sizeArray=sizeArray;
    this->top=-1;
    this->arr=new employee[sizeArray];
    //ctor
}
void Stack:: push(employee& emp){
    top++;  
    if(top==sizeArray){
        sizeArray*=2;
        employee *ptr=arr;
        for(int i=0;i<sizeArray;i++){
            arr[i]=ptr[i];
        }
        delete[] ptr;
    } 
    arr[top]=emp;
}
bool Stack::pop(employee * emp){
    if(top == -1){
        return 0;
    }
    *emp=arr[top];
    top--;
    return 1;
}
void Stack::display()
{
    if(top==-1){
        cout<<"There is no employees\n";
    }
    else{
        for(int i = 0; i <=top; i++)
        {
            cout << "======== Employee "<<i+1<<" ========\n";
            cout << "Name: " << arr[i].getName() << "\n";
            cout << "Position: " << arr[i].getPostiton() << "\n";
            cout << "Age: " << arr[i].getAge() << "\n";
            cout << "Salary: " << arr[i].getSalary() << "\n";
        }
    } 
}
Stack & Stack:: operator=(const Stack  s){
    delete [] this->arr;
    arr=new employee[s.sizeArray];
    this->sizeArray=s.sizeArray;
    this->top=s.top;
    for(int i=0; i<=s.top; i++){
            this->arr[i]=s.arr[i];
    }
    return *this;

}

Stack::~Stack()
{    
    delete []arr;
    //dtor
}


