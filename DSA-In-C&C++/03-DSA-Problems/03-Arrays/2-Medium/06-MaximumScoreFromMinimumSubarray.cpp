/*
Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. From the subarray arr[i...j], select the smallest and second smallest numbers and add them, you will get the score for that subarray. Return the maximum possible score across all the subarrays of array arr[].

Examples :

Input : arr[] = [4, 3, 1, 5, 6]
Output : 11
Explanation : Subarrays with smallest and second smallest are:- [4, 3] smallest = 3,second smallest = 4
[4, 3, 1] smallest = 1, second smallest = 3
[4, 3, 1, 5] smallest = 1, second smallest = 3
[4, 3, 1, 5, 6] smallest = 1, second smallest = 3
[3, 1] smallest = 1, second smallest = 3
[3, 1, 5] smallest = 1, second smallest = 3
[3, 1, 5, 6] smallest = 1, second smallest = 3
[1, 5] smallest = 1, second smallest = 5
[1, 5, 6] smallest = 1, second smallest = 5
[5, 6] smallest = 5, second smallest = 6
Maximum sum among all above choices is, 5 + 6 = 11.
Input : arr[] = [5, 4, 3, 1, 6] 
Output : 9
*/

#include<iostream>
#include<vector>
using namespace std;

int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int maximum = 0;
        for(int i = 0; i < arr.size() -1; i++){
            int j = i + 1;
            maximum = max(maximum, arr[i] + arr[j]);
        }
        return maximum;
    }

int main(){
    vector<int> arr = {5, 4, 3, 1, 6};
    cout<<pairWithMaxSum(arr);
}