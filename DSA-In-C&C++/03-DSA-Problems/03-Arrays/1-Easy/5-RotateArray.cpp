/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());           
        reverse(nums.begin(), nums.begin() + k);     
        reverse(nums.begin() + k, nums.end()); 

    }

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
     

    rotate(nums, 3);

    for(auto it: nums){
        cout<<it<<" ";
    }
}