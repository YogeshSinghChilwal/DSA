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
        void Display();
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

void Stack::Display()
{
    for(int i = top; i >= 0; i--)
        cout<<s[i]<<" | "<<flush;
    cout<<endl;
}


int main()
{
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);


    st.Display();

    st.pop();
    st.pop();

    st.Display();

    cout<<st.peek(3);

    return 0;

}