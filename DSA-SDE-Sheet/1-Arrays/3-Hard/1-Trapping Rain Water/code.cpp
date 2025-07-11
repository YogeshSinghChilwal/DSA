#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int trapBrute(vector<int> &height)
{
    int trapWater = 0;
    for (int i = 1; i < height.size() - 1; i++)
    {
        int leftMax = INT_MIN;
        for (int j = i - 1; j >= 0; j--)
        {
            leftMax = max(leftMax, height[j]);
        }

        int rightMax = INT_MIN;
        for (int j = i + 1; j < height.size(); j++)
        {
            rightMax = max(rightMax, height[j]);
        }

        int minHeight = min(leftMax, rightMax);

        if (minHeight > height[i])
        {
            trapWater = trapWater + (minHeight - height[i]);
        }
    }

    return trapWater;
}

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int trapWater = 0;
    for (int i = 0; i < n; i++)
    {
        trapWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return trapWater;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(arr);
}