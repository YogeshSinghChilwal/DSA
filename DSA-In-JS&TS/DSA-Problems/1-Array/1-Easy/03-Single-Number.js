
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
*/



var singleNumber = function(nums) {
    let ans;
    for(const num of nums){
        ans^= num
    }
    return ans
};

console.log(singleNumber([5, 2, 5, 6, 2, 1, 1]))