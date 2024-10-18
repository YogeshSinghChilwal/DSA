#include<iostream>
using namespace std;

class Queue
{
    private: 
        int size;
        int front;
        int rear;
        int* Q;
    public:
        Queue(int size);
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(int x);
        int dequeue();
        void display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}

Queue::~Queue()
{
    delete [] Q;
}

bool Queue::isEmpty()
{
    if(front == rear)
        return true;
    else
        return false;
}

bool Queue::isFull()
{
    if(rear == size - 1)
        return true;
    return false;
}

void Queue::enqueue(int x)
{
    if(isFull())
    {
        cout<<"Queue overflow!";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if(isEmpty())
        cout<<"Queue is underflow!";
    else
    {
        front++;
        x = Q[front];
    }
    return x;

}

void Queue::display()
{
    for(int i = front + 1; i <= rear; i++)
    {
        cout<<Q[i];
        if(i < rear)
            cout<< "<-" << flush;
    }
    cout<<endl;
}

int main()
{
    Queue q(7);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;

}