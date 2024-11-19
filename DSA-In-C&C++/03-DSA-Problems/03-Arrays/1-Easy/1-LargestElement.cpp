/*
Given an array arr[]. The task is to find the largest element and return it.

Examples:

Input: arr = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.
*/

#include<iostream>
using namespace std;

int largest(int *arr, int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > max){

            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {1, 8, 7,  56, 90};

    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n;

    cout<<largest(arr, n);
}