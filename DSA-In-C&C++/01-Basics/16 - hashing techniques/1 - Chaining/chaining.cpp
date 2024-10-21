#include<iostream>
#include"linkedList.h"
using namespace std;

int Hash(int x)
{
    return x%10;
}

void Insert(Node *p[], int key)
{
    int index = Hash(key);
    LinkedList li;
    li.Insert(&p[index], key);

}

int main()
{
    LinkedList l;
    Node *h[10]; //hash table (array of pointers)
    Node *temp;

    for(int i = 0; i < 10; i++)
        h[i] = nullptr;

    Insert(h, 42);
    Insert(h, 32);
    Insert(h, 22);
    Insert(h, 52);
    Insert(h, 24);
    Insert(h, 25);
    Insert(h, 27);
    Insert(h, 29);
    Insert(h, 20);
    Insert(h, 21);
    Insert(h, 23);

    l.Delete(&h[Hash(22)], 22);


    temp = l.Search(h[Hash(22)], 22);

    cout<<temp<<"   ";
    if(temp)
        cout<<temp->data;


    
}