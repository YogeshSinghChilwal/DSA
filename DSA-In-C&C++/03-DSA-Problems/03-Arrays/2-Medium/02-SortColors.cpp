/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
        // Using Dutch National Flag Algorithm
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] == 1)
            {
                mid++;
            } else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    for(int it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
    sortColors(nums);
    for(int it: nums){
        cout<<it<<" ";
    }
}