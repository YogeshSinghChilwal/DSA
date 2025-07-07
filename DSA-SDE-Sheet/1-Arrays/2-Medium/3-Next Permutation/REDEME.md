# Next Permutation

## Company
Uber + Goldman Sachs + Adobe Interview Qs

## Link
https://leetcode.com/problems/next-permutation/description/

## Question
#### A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.


Examples:
```
Input: nums = [1,2,3]
Output: [1,3,2]
```
```
Input: nums = [3,2,1]
Output: [1,2,3]
```
```
Input: nums = [1,1,5]
Output: [1,5,1]
```

## Solution

### 1. Approach
1- Find the element that needs to be changed to form the next permutation.
nums[i] < nums[i + 1]

2- If no such element is found this means given array does not have a lexicographical larger rearrangement.
So reverse the whole array.

3- Find the smallest element greater than nums[index] and swap.

4- Reverse the subarray from index + 1 to end

```cpp
void nextPermutation(vector<int> &nums)
{
    int index = -1;
    int s = nums.size();

    // Finding the element that needs to be changed to form the next permutation
    for (int i = s - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    // If no such element is found this means given array does not have a lexicographical larger rearrangement.
    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // finding the smallest element greater than nums[index] and swap
    for (int i = s - 1; i > index; i--)
    {
        if (nums[index] < nums[i])
        {
            swap(nums[index], nums[i]);
            break;
        }
    }

    // Reverse the subarray from index + 1 to end
    reverse(nums.begin() + index + 1, nums.end());
}
```
### 2. 

```cpp


```