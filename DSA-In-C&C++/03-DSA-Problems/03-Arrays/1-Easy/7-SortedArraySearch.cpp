/*
Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

Examples:

Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.
*/

#include<iostream>
#include<vector>

using namespace std;

bool searchInSorted(vector<int> arr, int k) {
    // Your code here
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == k){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    cout<<searchInSorted(arr, 6);


}