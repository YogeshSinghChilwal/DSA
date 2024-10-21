#include<iostream>
using namespace std;

void insertionSort(int* A, int n)
{
    int j;
    int x;
    for(int i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while(j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
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
    int A[] = {4, 7, 1, 3, 8, 2, 0};
    int n = sizeof(A) / sizeof(A[0]);

    insertionSort(A, n);

    Display(A,n);

}