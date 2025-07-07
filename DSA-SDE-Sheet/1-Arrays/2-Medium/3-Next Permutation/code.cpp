#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int index = -1;
    int s = nums.size();

    // Finding the element that needs to be changed to form the next permutation
    for (int i = s - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    // If no such element is found this means given array does not have a lexicographical larger rearrangement.
    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // finding the smallest element greater than nums[index] and swap
    for (int i = s - 1; i > index; i--)
    {
        if (nums[index] < nums[i])
        {
            swap(nums[index], nums[i]);
            break;
        }
    }

    // Reverse the subarray from index + 1 to end
    reverse(nums.begin() + index + 1, nums.end());
}

int main()
{
    vector<int> arr = {1, 1, 5};
    nextPermutation(arr);

    for (int a : arr)
    {
        cout << a << "  ";
    }
    cout << endl;
}