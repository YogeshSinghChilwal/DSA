/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

//! It includes a validation step after identifying the result, counting its occurrences and checking if it exceeds nums.size() / 2.


#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele;

        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                ele = nums[i];
                count = 1;
            }
            else if(nums[i] == ele)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == ele)
                count++;
        }

        if(count > (nums.size()/2))
            return ele;
        
        return -1;
    }

    int main(){
        vector<int> nums = {2,2,1,1,1,2,2};
        cout<<majorityElement(nums);
    }