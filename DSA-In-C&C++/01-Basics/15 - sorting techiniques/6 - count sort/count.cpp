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

void countSort(int* A, int n)
{
    int max = *max_element(A, A + n);
    int* c;
    c = new int[max + 1];
    int i,j;

    for(i = 0; i < max + 1; i++)
        c[i] = 0;

    for(i = 0; i < n; i++)
        c[A[i]]++;
    
    i = 0;
    j = 0;
    while(i < max + 1)
    {
        if(c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}


int main() {
  int A[] = {10, 4, 7, 8, 50};
  int n = sizeof(A) / sizeof(A[0]);

  countSort(A, n);
  Display(A, n);

  return 0;
}