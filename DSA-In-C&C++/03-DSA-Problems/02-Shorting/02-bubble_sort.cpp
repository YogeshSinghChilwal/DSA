#include<iostream>
#include<algorithm>

using namespace std;

//& Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.


/*
Given an Integer n and a list arr. Sort the array using bubble sort algorithm.

Examples :

Input: n = 5, arr[] = {4, 1, 3, 9, 7}
Output: 1 3 4 7 9
*/

void bubbleSort(int arr[], int n) {
        // Your code here
        int flag;
        for(int i = 0; i < n - 1; i++){
            flag = 0;
            for(int j = 0; j < n - 1 - i; j++){
                if(arr[j + 1]){
                    if(arr[j + 1] < arr[j]){
                        swap(arr[j + 1], arr[j]);
                        flag = 1;
                    }
                }
            }
            if(flag == 0) break;
        }
    }

int main(){
    int arr[] ={4, 1, 3, 9, 7};
    int n = 5;
    bubbleSort(arr, n);

    for(int ele : arr){
        cout<<ele<<" ";
    }
}