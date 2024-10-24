#include<iostream>
#include<algorithm>
using namespace std;

//? Given an unsorted array of size N, use selection sort to sort arr[] in increasing order.

/*
Input:
N = 5
arr[] = {4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Explanation:
Maintain sorted (in bold) and unsorted subarrays.
Select 1. Array becomes 1 4 3 9 7.
Select 3. Array becomes 1 3 4 9 7.
Select 4. Array becomes 1 3 4 9 7.
Select 7. Array becomes 1 3 4 7 9.
Select 9. Array becomes 1 3 4 7 9.
*/

int main(){
    int arr[] = {1, 5, 3, 8, 2, 0, 4};
    int n = 7;


    int i, j, k;
       for(i = 0; i < n; i++)
       {
           for(j = k = i; j < n; j++)
           {
               if (arr[j] < arr[k])
               {
                   k = j;
               }
           }
           
           swap(arr[i], arr[k]);
       }

    for(int ele : arr)
    {
        cout<<ele<<"  ";
    }

    return 0;
}