/* 
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/

var missingNumber = function(nums) {
    // for(let i = 0; i <= nums.length; i++){
    //     let flag = 0;
    //     for(let j = 0; j <= nums.length; j++){
    //         if(nums[j] === i){
    //             flag = 1;
    //             break
    //         }
    //     }
    //     if(flag === 0){
    //         return i
    //     }
    // }

    let arr = new Array(nums.length + 1).fill(0)

    for(let i = 0; i < nums.length; i++){
        arr[nums[i]] = 1
    }

    for(let i = 0; i <= nums.length; i++){
        if(arr[i] === 0){
            return i;
        }
    }

    return -1
};

console.log(missingNumber([1, 3, 4, 2, 6, 0]))