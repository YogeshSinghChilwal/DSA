#include<iostream>
using namespace std;

//Node class is the building block of the linked list, holding data and a pointer to the next node.
class Node
{
    public:
        int data;
        Node *next;
};

//LinkedList class manages these nodes, starting with a pointer to the first node, and would include methods to manipulate and traverse the list.
class LinkedList
{
    private:
        Node *first;

    public:
        LinkedList(){first = NULL;}
        LinkedList(int A[], int n);

        ~LinkedList();

        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        int Length();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;

    while(first)
    {
        first = first->next;
        delete p;
        p = first;
    }

}

void LinkedList::Display()
{
    Node *p = first;

     while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int LinkedList::Length()
{
    Node *p = first;
    int l = 0;
    while(p)
    {
        p = p->next;
        l++;
    }
    return l;
}

void LinkedList::Insert(int index, int x)
{
     Node *t, *p = first;
    if(index < 0 || index > Length())
        return;
    
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
     Node *q=NULL, *p;
    int x=-1,i;
    
    if(index < 1 || index > Length())
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else
    {
        p = first;
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);

    l.Display();


    // l.Insert(0, 9);
    cout<<endl<<l.Length()<<endl;
    l.Delete(3);


    l.Display();
    return 0;
}