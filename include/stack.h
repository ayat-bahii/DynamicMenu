#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "employees.h"

class Stack
{

    public:
        Stack();
        Stack(int sizeArray);
        ~Stack();
        Stack(Stack & s);
        void push(employee& emp);
        bool pop(employee* emp);
        void display();
        Stack & operator=(const Stack s);

    protected:


    private:
        int top;
        int sizeArray;
        employee* arr;

};

#endif // STACK_H