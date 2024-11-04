//* merge sort --> divide & merge

#include<iostream>
using namespace std;
#include<vector>

void merge(vector<int>& arr, int low, int mid, int high){
        int temp[high + 1];
        int i, j, k;
        
        i = low;
        j = mid + 1;
        k = low;
        
        while(i <= mid && j <= high){
            if(arr[i] < arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        
        for(; i <= mid; i++){
            temp[k++] = arr[i];
        }
        for(; j <= high; j++){
            temp[k++] = arr[j];
        }
        
        for(i = low; i <= high; i++){
            arr[i] = temp[i];
        }
    }


void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l < r){
            int mid = (l + r)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
            
        }
    }
    
    
int main(){
    vector<int> arr = {1, 4, 5, 7, 2, 9, 2, 3};
    int n = 8;

    mergeSort(arr,0, 7);

    for(auto ele:arr){
        cout<<ele<<"    ";
    }
}