/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

var longestConsecutive = function(nums) {
    let longest = 0
    const mySet = new Set(nums)

    for(let num of nums){
        if(!mySet.has(num - 1)){
            let count = 0
            let currentNum = num

            while(mySet.has(currentNum + 1)){
                count++
                currentNum++
            }
            longest = Math.max(count, longest)
        }
    }

    return longest
}

console.log(longestConsecutive([0,3,7,2,5,8,4,6,0,1]))