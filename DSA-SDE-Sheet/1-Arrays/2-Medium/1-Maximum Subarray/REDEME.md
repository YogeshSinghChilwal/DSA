# Maximum Subarray

## Company
 Microsoft + Facebook Interview Qs

## Link
https://leetcode.com/problems/maximum-subarray/

## Question
#### Given an integer array nums, find the subarray with the largest sum, and return its sum.


Examples:
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```
```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```
```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

## Solution

### 1. Visiting all sub array  

```cpp
int maxSubArrayBrute(vector<int> &nums){
    int maxSum = INT_MIN;
    for(int start= 0; start < nums.size(); start++){
        int currentSum = 0;
        for (int end = start; end < nums.size(); end++)
        {
            currentSum += nums[end];
            maxSum = max(currentSum, maxSum);
        }
        
    }
    return maxSum;
}

```
### 2. Kadane's algorithm

```cpp
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int currentSum = 0;

    for(int i = 0; i < nums.size(); i++){
        currentSum += nums[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        if(currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    return maxSum;
}

```