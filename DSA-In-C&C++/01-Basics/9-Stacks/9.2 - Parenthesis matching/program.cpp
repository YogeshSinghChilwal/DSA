#include<iostream>
using namespace std;

class Node
{
    public:
        char data;
        Node* next;
};

class Stack
{
    private:
        Node* Top;

    public:
        Stack();
        ~Stack();
        void push(int x);
        char pop();
        int peek(int index);
        int stackTop();
        int isEmpty();
        int isFull();
        void display();
};

Stack::Stack()
{
    Top = nullptr;
}

Stack::~Stack()
{
    Node* p = Top;
    while(Top)
    {
        Top = Top->next;
        delete p;
        p = Top;
    }
}

void Stack::push(int x)
{
    Node *t = new Node;
    if(t == nullptr)
        cout<<"Stack overflow!"<<endl;
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

char Stack::pop()
{
    char x = -1;
    Node* p = nullptr;
    if(Top == nullptr)
        cout<<"Stack is undeflow!"<<endl;
    else
    {
        p = Top;
        Top = Top->next;
        x = p->data;
        delete p;
    }
    return  x;
}

int Stack::peek(int index)
{
    Node* p = Top;
    for(int i = 0; p != nullptr && i < index - 1; i++)
        p = p->next;
    if(p)
        return p->data;
    else
        return -1;
}

int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}
 
int Stack::isEmpty() {
    return Top ? 0 : 1;
}
 
int Stack::stackTop() {
    if (Top){
        return Top->data;
    }
    return -1;
}

void Stack::display()
{
    Node* p = Top;
    while(p != nullptr)
    {
        cout<<p->data<<" | ";
        p = p->next;
    }
    cout<<"\n";
}

bool isBalanced(char exp[])
{
    Stack stk;
    
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(') 
            stk.push(exp[i]);
        else if(exp[i] == ')')
        {
            if(stk.isEmpty()) return false;
            cout<<stk.pop()<<endl;
        }
    }
    return stk.isEmpty() ? true : false;
}

int main()
{
    char E[] = "((a + b) * (c - d))"; //char* E = "((a + b) * (c - d))";

    cout<<isBalanced(E);


    
    return 0;
}