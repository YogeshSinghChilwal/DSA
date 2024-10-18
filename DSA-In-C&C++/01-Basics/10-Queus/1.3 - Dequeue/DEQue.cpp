#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class DEQueue
{
    private:
        Node* front;
        Node* rear;
    
    public:
        DEQueue();
        ~DEQueue();
        bool isEmpty();
        bool isFull();
        void enqueue(int x);
        int dequeue();
        void display();
};

DEQueue::DEQueue()
{
    front = rear = nullptr;
}

DEQueue::~DEQueue()
{
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}


bool DEQueue::isEmpty()
{
    if(front == nullptr)
        return true;
    return false;
}

bool DEQueue::isFull()
{
    Node* t = new Node;
    if(t == nullptr)
        return true;
    return false;
}

void DEQueue::enqueue(int x)
{
    Node* t = new Node;
    if(isFull())
        cout<<"Queue overflow!"<<endl;
    else
    {
        t->data = x;
        t->next = nullptr;
        if(front == nullptr)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int DEQueue::dequeue()
{
    Node* p;
    int x = -1;
    if(isEmpty())
        cout<<"Queue underflow!"<<endl;
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void DEQueue::display()
{
    Node* p = front;
    while(p)
    {
        cout<<p->data;
        if(p->next != nullptr)
            cout<<" <- ";
        p = p->next;
    }
    cout<<endl;
}


int main()
{

    
    return 0;
}