#  Search in Rotated Sorted Array

## Company
Microsoft Google Adobe Amazon D-E-Shaw Flipkart Hike Intuit MakeMyTrip Pay

## Link


## Question
#### There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.


Examples:
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```
```
Input: nums = [1], target = 0
Output: -1

```

## Solution

### 1. Binary serach
We can directly apply BS here because one half will always be Sorted
and we will only check target if the array is sorted if target was not in that place then we again haft the unsorted array and again one half will be sorted so on ...

```cpp
int search(vector<int> &nums, int target)
{
 int left = 0;
 int right = nums.size() - 1;

 while(left <= right){

    //same as mid = (left + right)/2 but better for larger numbers
    int mid = left + (right - left) / 2;   
    
    if(nums[mid] == target){
        return mid;
    }

    // checking if left sub array is sorted
    if(nums[left] <= nums[mid]){
        // checking if target exist in left sorted sub array
        if(nums[left] <= target && target < nums[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    //Right sub sorted array
    else{
        if(nums[mid] < target && target <= nums[right]){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
 }

 return -1;
}

```
### 2. 

```cpp


```