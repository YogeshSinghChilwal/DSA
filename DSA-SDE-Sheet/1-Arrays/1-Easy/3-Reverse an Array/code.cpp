#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr)
{
    // code here
    vector<int> newArr;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        newArr.push_back(arr[i]);
    }

    for (int i = 0; i < newArr.size(); i++)
    {
        arr[i] = newArr[i];
    }
}

void reverse(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main()
{
    vector<int> arr = {1, 4, 3, 2, 6, 5};
}