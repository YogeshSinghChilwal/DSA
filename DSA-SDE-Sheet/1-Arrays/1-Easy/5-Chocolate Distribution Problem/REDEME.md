# Chocolate Distribution Problem

## Company
Amazon Interview Qs

## Link
https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

## Question
#### Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
     i. Each student gets exactly one packet.
     ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.




Examples:
```
Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].
```
```
Input: arr = [7, 3, 2, 4, 9, 12, 56], m = 3
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following m packets :[3, 2, 4].
```
```
Input: arr = [3, 4, 1, 9, 56], m = 5
Output: 55
Explanation: With 5 packets for 5 students, each student will receive one packet, so the difference is 56 - 1 = 55.
```

## Solution

### 1. Sort the array, For every group of m consecutive packets compute difference
```cpp

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
```
### 2. 

```cpp


```