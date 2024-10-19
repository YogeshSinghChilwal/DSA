#include<iostream>
#include<climits>
#include"queue.h"
using namespace std;

class Stack
{
    private:
        int size;
        int top;
        Node** s;

    public:
        Stack(int size);
        ~Stack();
        void push(Node* x);
        Node* pop();
        Node* peek(int index);
        Node* stackTop();
        int isEmptyStack();
        int isFullStack();
        void Display();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    s = new Node* [size];
}

Stack::~Stack()
{
    delete[] s;
}

void Stack::push(Node* x)
{
    if(isFullStack())
        cout<<"Stack Overflow!"<<endl;
    else
    {
        top++;
        s[top] = x;
    }
}

Node* Stack::pop()
{
    Node* x = nullptr;
    if(isEmptyStack())
    {
        cout<<"Stack Underflow!"<<endl;
    }
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

Node* Stack::peek(int index)
{
    Node* x = nullptr;
    if(top - index + 1 == size || top - index + 1 < 0)
        cout<<"Invalid Position!"<<endl;
    else
    {
        x = s[top - index + 1];
    }
    return x;
}

Node* Stack::stackTop()
{
    if(isEmptyStack())
        return 0;
    else
        return s[top];
}

int Stack::isEmptyStack()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int Stack::isFullStack()
{
    if(top == size - 1)
        return 1;
    else
        return 0;
}

void Stack::Display()
{
    for(int i = top; i >= 0; i--)
        cout<<s[i]<<" | "<<flush;
    cout<<endl;
}
