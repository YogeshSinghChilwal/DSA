/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

//! O(n^2)
// var twoSum = function(nums, target) {
//     for(let i = 0; i < nums.length; i++){
//         for(let j = i + 1; j < nums.length; j++){
//             if(nums[i] + nums[j] === target){
//                 return [i, j]
//             }
//         }
//     }
//     return []
// };

// console.log(twoSum([2, 3, 5, 1], 4))

/*
In JavaScript, a Map is a built-in object that stores key-value pairs. Unlike plain objects, 
where keys are always treated as strings or symbols, a Map allows keys of any data type, including objects, functions, and primitive types.
*/

//! O(n)
var twoSum = function(nums, target) {
    const myMap = new Map()
    for(let i = 0; i < nums.length; i++){
        if(myMap.has(nums[i])){
            return [myMap.get(nums[i]), i]
        }
        const remaining = target - nums[i]
        
        myMap.set(remaining, i);

    }
    return []
};

console.log(twoSum([2, 3, 5, 1], 4))
