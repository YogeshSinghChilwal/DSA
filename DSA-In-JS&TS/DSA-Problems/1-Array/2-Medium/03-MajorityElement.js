/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

var majorityElement = function(nums) {
    for (let i = 0; i < nums.length; i++) {
    let count = 1;

        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] === nums[j]) {
                count++;
            }
        }
        if (count > (nums.length / 2)) {
            return nums[i];
        }
    }
    return -1;
};

console.log(majorityElement([6, 5, 5]))

/*
Why Choose an Object in JavaScript?

Performance:
JavaScript objects work as hash maps, meaning property access (like obj[key]) is optimized for constant time complexity in most cases.
This makes them an efficient choice for frequency counting tasks like finding the majority element.

Simplicity:
Objects are native to JavaScript and straightforward to use.
They provide a clear syntax for creating and updating key-value pairs (obj[key] = value).

Use Case Alignment:
In JavaScript, we usually don't need the ordering guarantees provided by a Map unless explicitly required.
For problems like the majority element, ordering is irrelevant, so an object suffices.
*/

var majorityElement2 = function(nums) {
    const counts = {}
    const majority = Math.floor(nums.length / 2)
    for(let num of nums){
        counts[num] = (counts[num] || 0) + 1
        if(counts[num] > majority){
            return num
        }
    }
    return -1
};

console.log(majorityElement2([6, 5, 5]))

//! Moore's voting algorithm

var majorityElement3 = function(nums) {
    let count = 0
    let element = null
    for(let num of nums){
        if(count === 0){
            element = num
        }
        count += (num === element) ? 1 : -1
    }
    return element
};