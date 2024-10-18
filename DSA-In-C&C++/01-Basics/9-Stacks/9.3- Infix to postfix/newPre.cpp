#include<iostream>
#include<cstring>
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
        char stackTop();
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
 
char Stack::stackTop() {
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

int isOpreand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    return 1;
}

int outStackPre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '^')
        return 6;
    else if(x == '(')
        return 7;
    else if(x == ')')
        return 0;
    return 0;
}

int inStackPre(char x)
{
    if(x == '+' || x == '-')
        return 2;
    else if(x == '*' || x == '/')
        return 4;
    else if(x == '^')
        return 5;
    else if(x == '(')
        return 0;
    return 0;
}


char* convert(char* infix)
{
    int i = 0, j = 0;
    Stack st;
    
    char* postfix = new char[strlen(infix) + 1];
    while(infix[i] != '\0')
    {
        if(isOpreand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(outStackPre(infix[i]) > inStackPre(st.stackTop()) )
                st.push(infix[i++]);
            else if(outStackPre(infix[i]) == inStackPre(st.stackTop()))
                {
                    st.pop();
                    i++;
                }
            else
            {
                postfix[j++] = st.pop();
            }
        }
    }
    while(!st.isEmpty()) postfix[j++] = st.pop();

    postfix[j] = '\0';

    
    return postfix;

    
}


int main()
{
    char infix[10];

    cout<<"Enter Infix form: ";
    cin>>infix;

    cout<<convert(infix);


    
    return 0;
}