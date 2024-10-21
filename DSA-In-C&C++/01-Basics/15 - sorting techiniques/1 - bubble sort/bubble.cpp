#include<iostream>
using namespace std;

void bubbleShort(int* A, int n)
{
    int flag;
    for(int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if(flag == 0)
            return;
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
    int A[] = {1, 6, 3, 7, 5};
    int n = sizeof(A)/sizeof(A[0]);
    Display(A, n);
    bubbleShort(A, n);
    Display(A, n);
    
}