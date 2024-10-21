#include<iostream>
using namespace std;

void selectionSort(int* A, int n)
{
    int j, k;
    for(int i = 0; i < n - 1; i++)
    {
        for(j = k = i; j < n; j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}

void Display(int* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<A[i]<<" | ";
    }
    cout<<endl;
}

int main()
{
    int A[] = {8, 6, 3, 2, 5, 4};
    int n = sizeof(A) / sizeof(A[0]);

    selectionSort(A, n);
    Display(A, n);

    return 0;
}