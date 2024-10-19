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

Node* root;

void create()
{
    Node *p, *t;
    int x;
    Queue q(10);
    cout<<"Enter root value: ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while( !q.isEmpty())
    {
        p = q.dequeue();

        cout<<"Enter left child value of "<<p->data<<" : ";
        cin>>x;
        if( x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter right child value of "<<p->data<<" : ";
        cin>>x;
        if( x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void preorder(Node* r)
{
    if(r)
    {
        cout<<r->data<<" | ";
        preorder(r->lchild);
        preorder(r->rchild);
    }
}

void inorder(Node *r)
{
    if(r)
    {
        inorder(r->lchild);
        cout<<r->data<<" | ";
        inorder(r->rchild);
    }
}

void postorder(Node *r)
{
     if(r)
    {
        postorder(r->lchild);
        postorder(r->rchild);
        cout<<r->data<<" | ";
    }
}

int Height(Node* r)
{
    int x = 0;
    int y = 0;
    if(r == 0)
        return 0;
    x = Height(r->lchild);
    y = Height(r->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{

    create();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<"\n"<<endl;
    Height(root);
    return 0;
}