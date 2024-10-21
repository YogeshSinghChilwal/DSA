#include<iostream>
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

void shellSort(int* A, int n)
{
    int gap, i, j, temp;
    for(gap = n/2; gap >= 1; gap = gap / 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while(j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {5, 6, 3, 7, 1, 8, 2, 9};
    int n = sizeof(A)/ sizeof(A[0]);

    shellSort(A, n);
    Display(A, n); 
}