#include<iostream>
using namespace std;

// Find a pair with sum k (= a + b)
void findAPair(int* arr, int size, int k)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] + arr[j] == k)
                cout<<arr[i]<<"+"<<arr[j]<<"="<<k<<endl;
        }
    }
}

// Find a pair of elements with sum k in shorted array
void findPair(int* arr, int size, int k)
{
    int i = 0 ,j = 0;
    while(i < j)
    {
        if(arr[i] + arr[j] == k)
        {
            cout<<arr[i]<<"+"<<arr[j]<<"="<<k<<endl;
            i++; 
            j--;
        } else if (arr[i] + arr[j] < k)
        {
            i++;
        } else{
            j++;
        }
        
    }
}

int main(){

    // int array[] = {1, 3, 4, 5, 9, 10, 11, 2, 7, 8};
    // int size = sizeof(array) / sizeof(array[0]);

    // findAPair(array, size, 10);

    int sortedArr[] = {1, 2, 3, 4, 5, 6 ,7 ,8 ,9};
    int sz = sizeof(sortedArr) / sizeof(sortedArr[0]);
    findAPair(sortedArr, sz, 10);
    return 0;
}