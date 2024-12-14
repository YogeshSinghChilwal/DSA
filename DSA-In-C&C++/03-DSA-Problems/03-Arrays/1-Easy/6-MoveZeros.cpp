/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

#include<iostream>
#include<vector>

using namespace std;

void movesZeros(vector<int>& nums){
    int n = nums.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main(){
    vector<int> nums = {8, 1, 0, 3, 12};

    movesZeros(nums);

    for(auto it: nums){
        cout<<it<<" ";
    }
}