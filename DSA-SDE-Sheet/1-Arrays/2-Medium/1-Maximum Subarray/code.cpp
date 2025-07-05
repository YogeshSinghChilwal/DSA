#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//* print all sub array brute forse
void printSubArray(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        for (int end = start; end < nums.size(); end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << nums[i];
            }
            cout << " ";
        }
    }
}

//* brute forse approach
int maxSubArrayBrute(vector<int> &nums){
    int maxSum = INT_MIN;
    for(int start= 0; start < nums.size(); start++){
        int currentSum = 0;
        for (int end = start; end < nums.size(); end++)
        {
            currentSum += nums[end];
            maxSum = max(currentSum, maxSum);
        }
        
    }
    return maxSum;
}

//* Kadane's algorithm
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int currentSum = 0;

    for(int i = 0; i < nums.size(); i++){
        currentSum += nums[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        if(currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    return maxSum;
}

int main()
{

    vector<int> nums = {1, 2, -3, 4, 5, 6};
    // printSubArray(nums);
    cout<<maxSubArray(nums);
    return 0;
}