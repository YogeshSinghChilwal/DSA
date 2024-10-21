#include<iostream>
using namespace std;

void Display(int* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<A[i]<<" | ";
    }
    cout<<endl;
}

void Merge(int* A, int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int B[100];
    int k = l;

    while(i <= mid && j <= h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i <= mid; i++)
        B[k++] = A[i];
    for(; j <= h; j++)
        B[k++] = A[j];

    for(i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void IMergeSort(int* A, int n)
{
    int p, h, mid, l;

    for(p = 2; p <= n; p = p * 2)
    {
        for(int i = 0; i + p -1 < n; i = i + p)
        {
            l = i; 
            h = i + p - 1;
            mid = (l + h)/2;
            Merge(A, l, mid, h);
        }
    }
    if(p/2 < n)
        Merge(A, 0, p/2 -1, n - 1);
}

void RMergeSort(int* A, int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    int A[] = {2, 9, 11, 3, 6, 5, 1, 4, 10 };
    int n = sizeof(A)/sizeof(A[0]);

    RMergeSort(A, 0, n - 1);
    Display(A, n);
}