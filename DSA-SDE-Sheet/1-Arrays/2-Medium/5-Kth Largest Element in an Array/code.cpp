#include <iostream>
#include <vector>
#include <climits>
#include<queue>

using namespace std;

// Worst time complixity
int findKthLargestBrute(vector<int> &nums, int k)
{
    int max = INT_MIN;
    for (int i = 1; i <= k; i++)
    {
        int maxIndex = -1;
        max = INT_MIN;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] > max)
            {
                max = nums[j];
                maxIndex = j;
            }
        }
        nums.erase(nums.begin() + maxIndex);
    }
    return max;
}

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < nums.size(); i++)
    {
        minHeap.push(nums[i]);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    return minHeap.top();
    
}

int main()
{
    vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 2;

    cout << findKthLargest(arr, k);
}