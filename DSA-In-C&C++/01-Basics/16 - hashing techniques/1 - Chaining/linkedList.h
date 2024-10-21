#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node
{
    public:
    int data;
    Node* next;
};

class LinkedList
{
    public:
    void Insert(Node** A, int val)
    {
        Node* t = new Node;
        t->data = val;
        t->next = nullptr;
        
        Node* q = nullptr;
        Node* p = *A;

        if(*A == nullptr)
            *A = t;
        else
        {
            while (!p && p->data < val)
            {
                q = p;
                p = p->next;
            }
            if(p == *A)
            {
                t->next = *A;
                *A = t;
            }
            else
            {
                t->next = q->next;
                q->next = t;
            }
            
        }
        
    }
    Node* Search(Node* p, int key)
    {
        while(p != nullptr)
        {
            if(p->data == key)
            {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
    int Delete(Node** A, int key)
    {
        int x = -1;
        Node* p = *A;
        Node* q = *A;
        while(p != nullptr)
        {
            if(p->data == key)
            {
                if(p == *A)
                {
                    *A = nullptr;
                    x = p->data;
                    delete p;
                    return x;
                }
                x = p->data;
                q->next = p->next;
                delete p;
                return x;
            }
            q = p;
            p = p->next;
        }
        return x;
    }
};

#endif