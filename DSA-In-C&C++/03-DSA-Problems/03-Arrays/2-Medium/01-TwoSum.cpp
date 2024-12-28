/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
           if(nums[i] + nums[j] == target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
           }
        }
    }
}

/*
An unordered map is a data structure commonly found in programming languages, such as C++, and it functions as a key-value store. 
It allows for efficient insertion, deletion, and lookup operations with an average time complexity of 
O(1). The "unordered" aspect means that the elements in the map are not stored in any specific order; instead, they are organized internally using a hash table.
*/

vector<int> twoSum2(vector<int>& nums, int target){
    vector<int> ans;
    unordered_map<int, int> myMap;
    for(int i = 0; i < nums.size(); i++){
        if(myMap.find(nums[i]) != myMap.end()){
            ans.push_back(myMap[nums[i]]);
            ans.push_back(i);

            return ans;
        }

        int remaining = target - nums[i];
        myMap[remaining] = i;
    }
}


int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;

    vector<int> ans =  twoSum2(nums, target);

    for(int it:ans){
        cout<<it<<", ";
    }
    return 0;
}