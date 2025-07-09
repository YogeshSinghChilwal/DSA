# Find the Duplicate Number

## Company


## Link
https://leetcode.com/problems/find-the-duplicate-number/description/

## Question
#### Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.


Examples:
```
Input: nums = [1,3,4,2,2]
Output: 2
```
```
Input: nums = [3,1,3,4,2]
Output: 3
```
```
Input: nums = [3,3,3,3,3]
Output: 3
```

## Solution

### 1. Approach 1: Floyd’s Tortoise and Hare (Cycle Detection)
Treat the array as a linked list where i is node and nums[i] is a pointer to the next node.

Since one number is duplicated, a cycle will exist.

This approach works in O(n) time and O(1) space.

🔁 Steps:
Phase 1 – Detect the cycle:

Use slow and fast pointers.

Slow moves one step: slow = nums[slow]

Fast moves two steps: fast = nums[nums[fast]]

They will meet inside the cycle.

Phase 2 – Find entrance to the cycle (duplicate number):

Reset one pointer to the start.

Move both pointers one step at a time until they meet.

The meeting point is the duplicate number.

```cpp
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // first part
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // second part
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}
```
### 2. Approach 2: Binary Search on Value
Binary search not on index but on range of values [1, n]

Use Pigeonhole Principle: count how many numbers ≤ mid.

If count > mid → duplicate is in left half.

```cpp
int findDuplicate(vector<int>& nums) {
    int low = 1, high = nums.size() - 1;
    int duplicate = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int count = 0;
        for (int num : nums)
            if (num <= mid)
                count++;

        if (count > mid) {
            duplicate = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return duplicate;
}


```