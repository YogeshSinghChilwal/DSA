/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//! brute approach

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int l = k + 1; l < n; l++){
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if(sum == target){
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    } 
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }


//! optimal

vector<vector<int>> fourSumOpt(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    if (n < 4) return result;

    // Sort the array to handle duplicates and use two pointers
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
        // Avoid duplicate for the first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {
            // Avoid duplicate for the second number
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1, right = n - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Avoid duplicates for the third and fourth numbers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSumOpt(nums, target);

    cout << "Quadruplets:" << endl;
    for (const auto& quad : result) {
        cout << "[";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
