#include<iostream>
using namespace std;

int goodPair(int* A, int n)
{
    // int pair = 0;
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = i; j < n; j++)
    //     {
    //         if(A[i] == A[j] && i < j)
    //             pair++;
    //     }
    // }
    // return pair;

    int count[101] = {0}; // Assuming nums contains values in the range 0-100
    int goodPairs = 0;

    for (int i = 0; i < n; ++i) {
        goodPairs += count[A[i]];
        count[A[i]]++;
    }

    return goodPairs;
}

int main()
{
    int A[] = {1, 2, 3, 1};
    int n = 4;
    cout<<goodPair(A, n);
}