/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

//! O(n^2)
var swap = function(nums, a, b){
    let t = nums[a]
    nums[a] = nums[b]
    nums[b] = t
 }
var sortColors = function(nums) {
    for(let i = 0; i < nums.length; i++){
        for(let j = i + 1; j < nums.length; j++){
            if(nums[j] < nums[i]){
                swap(nums, j, i)
            }
        }
    }
};

const nums = [2, 0, 2, 1, 1, 0]

// console.log(nums)
// sortColors(nums)
// console.log(nums)

//* The Dutch National Flag Algorithm
//! O(1) - O(n)
var sortColors2 = function(nums) {
    let low = 0
    let mid = 0
    let high = nums.length - 1

    while(mid <= high){
        if(nums[mid] === 0){
            swap(nums, low, mid)
            low++
            mid++
        }else if(nums[mid] === 1){
            mid++
        }else{
            swap(nums, mid, high)
            high--
        }
    }
}

console.log(nums)
sortColors2(nums)
console.log(nums)