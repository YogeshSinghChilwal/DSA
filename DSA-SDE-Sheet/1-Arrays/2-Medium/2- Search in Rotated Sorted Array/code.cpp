#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int search(vector<int> &nums, int target)
{
 int left = 0;
 int right = nums.size() - 1;

 while(left <= right){

    //same as mid = (left + right)/2 but better for larger numbers
    int mid = left + (right - left) / 2;   
    
    if(nums[mid] == target){
        return mid;
    }

    // checking if left sub array is sorted
    if(nums[left] <= nums[mid]){
        // checking if target exist in left sorted sub array
        if(nums[left] <= target && target < nums[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    //Right sub sorted array
    else{
        if(nums[mid] < target && target <= nums[right]){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
 }

 return -1;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    cout<<search(arr, 4);
}