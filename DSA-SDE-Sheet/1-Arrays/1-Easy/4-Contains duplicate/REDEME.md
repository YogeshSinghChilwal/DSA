# Contains Duplicate

## Company
 Amazon Interview Qs

## Link
https://leetcode.com/problems/contains-duplicate/description/

## Question
#### Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


Examples:
```
Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.
```
```
Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.
```
```
Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true
```

## Solution

### 1. Brute froce approach

```cpp
bool containsDuplicateBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }

    return false;
}
```
### 2. Using Unordered set

```cpp

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++)
    {
        if (set.count(nums[i]))
        {
            return true;
        }

        set.insert(nums[i]);
    }

    return false;
}
```