/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // Your code here
    // return vector with correct order of elements
    vector<int> nums;

    int i = 0;
    int j =  0;
    

    return nums;
    
}

int main(){
    vector<int> a = {-7, 8};
    vector<int> b = {-8, -3, 8};

    vector<int> nums = findUnion(a, b);

    for(auto it: nums){
        cout<<it<<" ";
    }
}