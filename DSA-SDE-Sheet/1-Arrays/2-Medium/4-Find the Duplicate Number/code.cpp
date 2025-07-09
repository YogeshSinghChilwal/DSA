#include <iostream>
#include <vector>

using namespace std;

// Slow and Fast pointer approach
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // first part
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // second part
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}

int main()
{

    vector<int> arr = {3, 1, 2, 4, 6, 2, 5};

    cout << findDuplicate(arr);
    return 0;
}