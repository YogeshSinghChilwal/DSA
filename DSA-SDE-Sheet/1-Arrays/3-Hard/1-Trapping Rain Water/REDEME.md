#  Trapping Rain Water

## Company
Samsung Interview Qs

## Link
https://leetcode.com/problems/trapping-rain-water/description/

## Question
#### Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


Examples:
```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```
```
Input: height = [4,2,0,3,2,5]
Output: 9
```
```

```

## Solution

### 1. Brute Force approach
For every 1 to n-1 interger find leftMax, rightMax.
Take minimum of them and subtract with current height.
Add all trapWater and return.
O(n2)

```cpp
int trap(vector<int> &height)
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
```
### 2. Same approach as above but with less time complixity & more space

```cpp
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

```

### 3.Intuition
Instead of precomputing left and right maximums for each index using extra space, we can use two pointers (l and r) starting from both ends. At each step, we can decide which side to move based on the current lMax and rMax. The idea is:

Water trapped at any index is determined by the shorter of the two tallest bars (left and right).

So, if lMax <= rMax, we know that the trapped water on the left depends only on lMax, and we can safely move l forward.

Else, we move r backward and use rMax.

### Approach
Initialize two pointers: l = 0, r = n - 1.

Keep track of the maximum height seen so far from both left (lMax) and right (rMax).

While l < r:

Update lMax and rMax.

If lMax <= rMax, then calculate water at l, update result, and move l++.

Otherwise, calculate water at r, update result, and move r--.

Return the total water trapped.

```cpp
int trap(vector<int> &height){
    int n = height.size();
    int result = 0;
    int l = 0;
    int r = n - 1;

    int lMax = 0;
    int rMax = 0;

    while (l < r)
    {
        lMax = max(lMax, height[l]);
        rMax = max(rMax, height[r]);

        if (lMax <= rMax)
        {
            result += lMax - height[l];
            l++;
        }else{
            result += rMax - height[r];
            r--;
        }
        
    }
    return result;
    
}
```