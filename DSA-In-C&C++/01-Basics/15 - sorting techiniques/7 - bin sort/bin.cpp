#include<iostream>
#include <algorithm>
using namespace std;

void Display(int* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<A[i]<<" | ";
    }
    cout<<endl;
}

struct Node
{
    int data;
    Node* next;
};

void Insert(Node** Bin, int index)
{
    Node* temp = new Node;
    temp->data = index;
    temp->next = nullptr;

    if(Bin[index] == nullptr)
        Bin[index] = temp;
    else
    {
        Node* p = Bin[index];
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** Bin, int index)
{
    int x;
    Node* p;
    p = Bin[index];
    
    Bin[index] = Bin[index]->next;

    x = p->data;
    delete p;
    return x;
}

void binSort(int* A, int n)
{
    int max = *max_element(A, A+n);
    Node** Bin;
    Bin = new Node*[max+1];

    for(int i = 0; i < max + 1; i++)
        Bin[i] = nullptr;
    
    for(int i = 0; i < n; i++)
    {
        Insert(Bin, A[i]);
    }

    int i = 0;
    int j = 0;
    while(i < max + 1)
    {
        if(Bin[i] != nullptr)
        {
            while(Bin[i] != nullptr)
                A[j++] = Delete(Bin, i);
        }
        else
            i++;
    }

    delete [] Bin;
}


int main()
{
    int A[] = {5, 7, 3, 2, 9, 3, 1, 4};
    int n = sizeof(A)/sizeof(A[0]);

    binSort(A, n);

    Display(A, n);
}