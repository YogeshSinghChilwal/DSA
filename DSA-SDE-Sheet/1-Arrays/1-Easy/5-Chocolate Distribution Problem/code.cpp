#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findMinDiff(vector<int> &a, int m)
{
    if (m == 0 || m > a.size())
        return -1;
    sort(a.begin(), a.end());
    int result = INT_MAX;
    for (int i = 0; i <= a.size() - m - 1; i++)
    {
        int currentDiff = a[i + m] - a[i];
        result = min(currentDiff, result);
    }
    return result;
}

int main()
{
}