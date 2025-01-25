/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            hashMap[nums[i]] += 1;
        }
        vector<int> ans;
        int minMax = n / 3;
        for(const auto& pair : hashMap){
            if( pair.second > minMax ){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }

vector<int> majorityElementOPT(vector<int>& nums) {
    int n = nums.size();
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

    // Step 1: Find potential candidates
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify the candidates
    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    vector<int> result;
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);

    return result;
}