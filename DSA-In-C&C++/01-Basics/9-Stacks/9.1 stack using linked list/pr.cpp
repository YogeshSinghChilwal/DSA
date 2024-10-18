#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
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
        int pop();
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

int Stack::pop()
{
    int x = -1;
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

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    st.pop();


    st.display();
    return 0;
}