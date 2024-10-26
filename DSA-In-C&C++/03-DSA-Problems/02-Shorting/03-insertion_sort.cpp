#include<iostream>
#include<algorithm>

using namespace std;

//& Builds a sorted list one element at a time by repeatedly taking the next element and inserting it into its correct position.

/*
The task is to complete the insert() function which is used to implement Insertion Sort.


Examples:

Input: n = 5, arr[] = { 4, 1, 3, 9, 7}
Output: 1 3 4 7 9
*/

void insertionSort(int arr[], int n)
    {
        //code here
        for(int i = 1; i < n; i++){
            int j = i - 1;
            int x = arr[i];
            
            while(j > -1 && arr[j] > x){
                arr[j + 1] = arr[j];
                j--;
            }
            
            arr[j + 1] = x;
        }
    }

int main(){
    int arr[] = { 4, 1, 3, 9, 7};
    int n = 5;
    insertionSort(arr, n);

    for(int ele : arr){
        cout<<ele<<"    ";
    }
    return 0;
}