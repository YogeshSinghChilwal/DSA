#include<iostream>
#include<climits>
using namespace std;

int partision(int* A, int l, int n)
{
    int i, j;
    int pivot = A[l];
    i = l;
    j = n;

    do
    {

        do{i++;}while(i <= j && A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i < j)
            swap(A[i], A[j]);

    }while(i < j);

    swap(A[l], A[j]);

    return j;
}

void quickSort(int* A, int l, int h)
{
    int j;
    if(l < h)
    {
        j = partision(A, l, h);
        quickSort(A, l, j - 1);
        quickSort(A, j+1, h);
    }
}


void Display(int* A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        cout<<A[i]<<" | ";
    }
    cout<<endl;
}

int main()
{
    int A[] = {5, 6, 3, 2, 7, 4, INT_MAX};
    int n = sizeof(A) / sizeof(A[0]);
     

    quickSort(A, 0, n);


   
    Display(A, n);

    return 0;
}