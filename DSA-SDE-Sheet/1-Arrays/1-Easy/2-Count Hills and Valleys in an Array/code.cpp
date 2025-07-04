#include <iostream>
#include <vector>
using namespace std;

//* Approach 1
int countHillValley(vector<int> &nums)
{
    int size = nums.size();
    int result = 0;
    vector<int> newArr;
    newArr.push_back(nums[0]);

    for (int i = 1; i < size; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            newArr.push_back(nums[i]);
        }
    }
    for (int i = 1; i < newArr.size() - 1; i++)
    {

        if (newArr[i] > newArr[i - 1] && newArr[i] > newArr[i + 1])
        {

            result++;
        }
        if (newArr[i] < newArr[i - 1] && newArr[i] < newArr[i + 1])
        {
            result++;
        }
    }
    return result;
}

// int countHillValley(vector<int> &nums)
// {
//     int result = 0;
//     int prev = nums[0];
//     int current = nums[1];
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (prev == current)
//         {
//             while (prev != current)
//             {
//                 i++;
//                 prev = current;
//                 current = nums[i];
//             }
//         }
//         if (current == nums[i + 1])
//         {
//             while (current != nums[i + 1])
//             {
//                 i++;
//                 current = nums[i];
//             }
//         }

//         if(current < prev && current < nums[i + 1]){
//             result++;
//         }
//         if(current > prev && current > nums[i + 1]){
//             result++;
//         }
//     }

//     return result;
// }

int main()
{
    vector<int> arr = {2, 4, 1, 1, 6, 5};
    cout << countHillValley(arr);

    return 0;
}