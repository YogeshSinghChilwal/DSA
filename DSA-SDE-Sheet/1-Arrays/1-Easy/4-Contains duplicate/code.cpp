#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicateBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }

    return false;
}
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++)
    {
        if (set.count(nums[i]))
        {
            return true;
        }

        set.insert(nums[i]);
    }

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << containsDuplicate(arr);
    return 0;
}