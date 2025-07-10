# Kth Largest Element in an Array

## Company
 Amazon Microsoft Walmart Adobe

## Link
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

## Question
#### Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?


Examples:
```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```
```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```
```

```

## Solution

### 1. Brute force approach

```cpp
// Worst time complixity
int findKthLargestBrute(vector<int> &nums, int k)
{
    int max = INT_MIN;
    for (int i = 1; i <= k; i++)
    {
        int maxIndex = -1;
        max = INT_MIN;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] > max)
            {
                max = nums[j];
                maxIndex = j;
            }
        }
        nums.erase(nums.begin() + maxIndex);
    }
    return max;
}
```
### 2. Using min heap

```cpp
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < nums.size(); i++)
    {
        minHeap.push(nums[i]);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    return minHeap.top();
    


```