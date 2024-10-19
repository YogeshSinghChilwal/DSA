#include<iostream>
using namespace std;

void insert(int* A, int n)
{
    int temp, i = n;
    temp = A[n];

    while(i > 1 && temp > A[i/2])  //i % 2 == 0 ? (i/2)-1 : i/2
    {
        A[i] = A[i / 2];
        i = i/2;
    }
    A[i] = temp;
}

void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Delete(int* A, int n)
{
    int i, j, t;
    t = A[1];
    A[1] = A[n];
    i = 1;
    j = i * 2;
    while (j < n - 1)
    {
        if(A[j] < A[j + 1])
            j = j + 1;
        if(A[i] < A[j])
        {
            swap(&A[i], &A[j]);
            i = j;
            j = 2 * j;
        }
        else
            break;
    }

    A[n] = t;
    
}

void Display(int* A, int n)
{
    for(int i = 1; i < n; i++)
    {
        cout<<A[i]<<" | ";
    }
    cout<<endl;

}

int main()
{
    // int A[] = {0, 10, 20 , 30, 25, 5, 40, 35};
    // int n = sizeof(A) / sizeof(A[0]);

    // Display(A, n);

    // for(int i = 2; i <= 7; i++)
    // {
    //     insert(A, i);
    // }

    // Display(A, n);

    // int j = 7;
    // for(int i = 1; i <= 7; i++)
    // {
    //     Delete(A, j);
    //     j--;
    // }

    // Display(A, n);

    cout<<7/2;
    
    return 0;
}