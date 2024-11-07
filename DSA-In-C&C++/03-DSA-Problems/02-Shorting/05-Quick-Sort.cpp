#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = arr[low];
        int i = low;
        int j = high;
        do{
            do{i++;}while(arr[i] <= pivot && i <= j);
            do{j--;}while(arr[j] > pivot);
            if(i < j){
                swap(arr[i], arr[j]);
            }
        }while(i < j);
        
        swap(arr[low], arr[j]);
        
        return j;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low < high){
            int p = partition(arr, low, high + 1);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

int main(){
    vector<int> arr = {3, 4, 6, 9, 2, 8, 1};

    quickSort(arr, 0, 6);

    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}