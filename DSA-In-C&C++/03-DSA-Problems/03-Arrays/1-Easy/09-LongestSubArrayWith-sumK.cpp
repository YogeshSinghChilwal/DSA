/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. It is guaranteed that a valid subarray exists.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, 9], k = 15
Output: 4
Explanation: The subarray [5, 2, 7, 1] has a sum of 15 and length 4.
*/

#include<iostream>
#include<vector>

using namespace std;

int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int longest = 0;
        int n = arr.size();

        for(int i = 0; i<n; i++){
            int sum = 0;

            for(int j = i; j < n; j++){
                sum += arr[j];

                if(sum == k){
                    longest = max(longest, j - i - 1);
                }
            }
        }
        return longest;
    }

int main(){

    vector<int> arr = {-1, 2, -3, 5, 2, -1, -1, -1, 2, -2,  -1};
    int k = -2;
    cout<<lenOfLongestSubarr(arr, k);

    return 0;
}