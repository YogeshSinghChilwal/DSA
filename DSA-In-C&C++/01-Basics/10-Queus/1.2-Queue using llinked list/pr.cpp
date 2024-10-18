#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

class Queue
{
    private:
        Node* front;
        Node* rear;
    
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(int x);
        int dequeue();
        void display();
};

Queue::Queue()
{
    front = rear = nullptr;
}

Queue::~Queue()
{
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}


bool Queue::isEmpty()
{
    if(front == nullptr)
        return true;
    return false;
}

bool Queue::isFull()
{
    Node* t = new Node;
    if(t == nullptr)
        return true;
    return false;
}

void Queue::enqueue(int x)
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

int Queue::dequeue()
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

void Queue::display()
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

    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    q.display();
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
    q.dequeue();
    return 0;
}