# Min and Max in Array

## Company
ABCO Accolite Amazon Cisco Hike Microsoft Snapdeal VMWare Google Adobe

## Link
https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

## Question
#### Given an array arr. Your task is to find the minimum and maximum elements in the array.

Note: Return a Pair that contains two elements the first one will be a minimum element and the second will be a maximum.

Examples:
```
Input: arr[] = [3, 2, 1, 56, 10000, 167]
Output: 1 10000
Explanation: minimum and maximum elements of array are 1 and 10000.
```
```
Input: arr[] = [1, 345, 234, 21, 56789]
Output: 1 56789
Explanation: minimum and maximum element of array are 1 and 56789.
```
```
Input: arr[] = [56789]
Output: 56789 56789
Explanation: Since the array contains only one element so both min & max are same.
```

## Solution

### 1. Best Simple and Efficient Approach

```cpp
pair<int, int> getMinMax(const vector<int>& arr) {
    if (arr.empty()) return {INT_MAX, INT_MIN}; // or throw exception

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    return {minVal, maxVal};
}
```
### 2. Using STL Algorithms (Best for Readability)

```cpp
#include <algorithm>

pair<int, int> getMinMax(const vector<int>& arr) {
    auto [minIt, maxIt] = minmax_element(arr.begin(), arr.end());
    return {*minIt, *maxIt};
}

```