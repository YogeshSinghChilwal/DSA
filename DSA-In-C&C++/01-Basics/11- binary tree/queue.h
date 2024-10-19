#include<iostream>
using namespace std;

class Node
{
    public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue
{
    private:
        int size;
        int front;
        int rear;
        Node** Q;
    public:
        Queue(int size);
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(Node* x);
        Node* dequeue();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}

Queue::~Queue()
{
    delete []Q;
}

bool Queue::isEmpty()
{
    if(front == rear)
        return 1;
    return 0;
}

bool Queue::isFull()
{
    if(rear == size - 1)
        return 1;
    return 0;
}

void Queue::enqueue(Node* x)
{
    if(isFull())
        cout<<"Queue overflow!"<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue()
{
    Node* x = nullptr;
    if(isEmpty())
        cout<<"Queue underflow!"<<endl;
    else
    {
        front++;
        x = Q[front];
    }
    return x;

}
