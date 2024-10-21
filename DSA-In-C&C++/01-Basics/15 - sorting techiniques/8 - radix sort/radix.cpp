#include<iostream>
#include <algorithm>
using namespace std;

//For displaying array
void Display(int* A, int n) 
{
    for(int i = 0; i < n; i++)
    {
        cout<<A[i]<<" | ";
    }
    cout<<endl;
}

//Node structure
struct Node
{
    int data;
    Node* next;
};

//Insert function for node data structure
void Insert(Node** Bin, int index, int data)
{
    Node* temp = new Node;
    temp->data = data;
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

//Delete function for Node data structure
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

//counting digits of max element of an array
int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}

//Functions for sorting the unsorted array using radix algorithm
void radixSort(int* A, int n, int r)
{
    int max = *max_element(A, A+n); //finding max element
    static int pass = countDigits(max); //counting digits of max ele for how many times recurtion should take place
    Node** Bin; //Array of Node pointers
    Bin = new Node*[10]; //creating an array for decimal

    //initialize bin with null pointer
    for(int i = 0; i < 10; i++)
        Bin[i] = nullptr;
    
    //iterating through input array and inserting in bin
    for(int i = 0; i < n; i++)
    {
        Insert(Bin, (A[i]/r)%10, A[i]);
    }

    //Deletion
    int i = 0;
    int j = 0;
    while(i < 10)
    {
        if(Bin[i] != nullptr)
        {
            while(Bin[i] != nullptr)
                A[j++] = Delete(Bin, i);
        }
        else
            i++;
    }
    static int val = 1;

    //Recursion for n number of pass(depends on max no. count)
    while(pass != 0)
    {
        val = val * 10;
        pass--;
        radixSort(A, n, val);
    }

    //for delocating heap memory
    delete [] Bin;
}


int main()
{
    int A[] = {44, 90, 23333333, 346, 1, 75733, 23, 90, 22, 124, 6, 3};
    int n = sizeof(A)/sizeof(A[0]);

    radixSort(A, n, 1);

    Display(A, n);
}