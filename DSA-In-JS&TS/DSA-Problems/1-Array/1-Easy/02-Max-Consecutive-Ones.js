/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

var findMaxConsecutiveOnes = function(nums) {
    let maxOne = 0
    let currentMaxOne = 0
    for(let i = 0; i < nums.length; i++){
        if(nums[i] === 1){
            currentMaxOne++

            if(currentMaxOne > maxOne){
                maxOne = currentMaxOne
            }
        }else{
            currentMaxOne = 0
        }
    }

    return maxOne
};

console.log(findMaxConsecutiveOnes([0,1,1,1,0]))