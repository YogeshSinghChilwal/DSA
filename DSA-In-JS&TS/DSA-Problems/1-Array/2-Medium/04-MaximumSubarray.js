/*
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/
//* returning sub array
var maxSubArray = function(nums) {
    let maximum = -Infinity
    let maxI = null
    let maxJ = null
    for(let i = 0; i < nums.length; i++){
        let currentMax = nums[i]
        for(let j = i + 1; j <= nums.length; j++){
            if(currentMax > maximum){
                maximum = currentMax
                maxI = i
                maxJ = j
            }
            if(j < nums.length){
                currentMax += nums[j]
            }
        }
    }
    const ans = []
    while(maxI < maxJ){
        ans.push(nums[maxI])
        maxI++
    }
    return ans
};

console.log(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))

//! O(n^2)
var maxSubArray2 = function(nums) {
    let maximum = -Infinity;


    for (let i = 0; i < nums.length; i++) {
        let currentMax = nums[i];
        for (let j = i + 1; j <= nums.length; j++) {
            if (currentMax > maximum) {
                maximum = currentMax;
            }
            if (j < nums.length) { 
                currentMax += nums[j];
            }
        }
    }

    return maximum
};

console.log(maxSubArray2([-2,1,-3,4,-1,2,1,-5,4]))

var maxSubArray3 = function(nums){
    let maximum = -Infinity
    let currentMax = 0
    for(let i = 0; i < nums.length; i++){
        currentMax = Math.max(nums[i], currentMax + nums[i])
        maximum = Math.max(currentMax, maximum)
    }

    return maximum
}

console.log(maxSubArray3([-2,1,-3,4,-1,2,1,-5,4]))

