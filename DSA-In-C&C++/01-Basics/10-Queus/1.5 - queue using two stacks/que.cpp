#include<iostream>
using namespace std;

class Stack
{
    private:
        int size;
        int top;
        int* s;

    public:
        Stack(int size);
        ~Stack();
        void push(int x);
        int pop();
        int peek(int index);
        int stackTop();
        int isEmpty();
        int isFull();
        void display();
        void rdisplay();
};


Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    s = new int[size];
}

Stack::~Stack()
{
    delete[] s;
}

void Stack::push(int x)
{
    if(isFull())
        cout<<"Stack Overflow!"<<endl;
    else
    {
        top++;
        s[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if(isEmpty())
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

int Stack::peek(int index)
{
    int x = -1;
    if(top - index + 1 == size || top - index + 1 < 0)
        cout<<"Invalid Position!"<<endl;
    else
    {
        x = s[top - index + 1];
    }
    return x;
}

int Stack::stackTop()
{
    if(isEmpty())
        return -1;
    else
        return s[top];
}

int Stack::isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int Stack::isFull()
{
    if(top == size - 1)
        return 1;
    else
        return 0;
}

void Stack::display()
{
    for(int i = top; i >= 0; i--)
        cout<<s[i]<<" | "<<flush;
    
}

void Stack::rdisplay()
{
    for(int i = 0; i <= top; i++)
        cout<<s[i]<<" | "<<flush;
    
}

class Queue
{
    private:
        Stack* st1;
        Stack* st2;
    public:
        Queue(int size);
        void enque(int x);
        int dequq();
        void display();
};

Queue::Queue(int size)
{
    st1 = new Stack(size);
    st2 = new Stack(size);
    
}

void Queue::enque(int x)
{
    if(st1->isFull())
        cout<<"Queue is overflow!"<<endl;
    else
        st1->push(x);
}

int Queue::dequq()
{
    int x = -1;
    if(st2->isEmpty())
    {
        if(st1->isEmpty())
        {
            cout<<"Stack underflow!"<<endl;
            return x;
            cout<<"/nno";

        }
        else
        {
            while(!st1->isEmpty())
                st2->push(st1->pop());
        }
    }
    x = st2->pop();
        return x;
}

void Queue::display()
{
    st2->rdisplay();
    st1->display();
    cout<<endl;
}

int main()
{
    Queue q(10);

    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(9);

    q.display();

    q.dequq();
    q.dequq();
    q.dequq();
    q.display();

    q.enque(4);
    q.display();
    



    return 0;
}