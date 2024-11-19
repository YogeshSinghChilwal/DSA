/*
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
*/

#include<iostream>
#include<vector>
using namespace std;

int getSecondLargest(vector<int> &arr) {
        // Code Here
        int largest = -1;
        int sLargest = -1;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest){
                sLargest = largest;
                largest = arr[i];
            }else if(arr[i] > sLargest && arr[i] != largest){
                sLargest = arr[i];
            }
        }

        return sLargest;
    }

int main(){
    vector<int> arr = {12, 35, 1, 10, 34, 1, 35};

    cout<<getSecondLargest(arr);
}