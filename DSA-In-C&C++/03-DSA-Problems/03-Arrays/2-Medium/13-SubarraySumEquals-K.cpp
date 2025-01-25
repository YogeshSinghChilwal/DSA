/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> hashMap;
    int count = 0;
    int prefixSum = 0;

    hashMap[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        count += hashMap[prefixSum - k];

        hashMap[prefixSum]++;
    }

    return count;
}

