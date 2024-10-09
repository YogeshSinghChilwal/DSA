#include<iostream>
using namespace std;

//~ 2- logarithmic time
    int binSearch(int arr[], int low, int high, int key){

        while (low <= high){
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) return mid;
            if (arr[mid] < key) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

int main(){

    //~ 1- constant time
    int arr[] = {1, 2, 3};
    int x = arr[2]; // O(1)

    

    //~ 3- linear time
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << endl;
    }



    return 0;
}