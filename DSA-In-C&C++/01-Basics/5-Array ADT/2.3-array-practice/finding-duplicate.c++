#include<iostream>
using namespace std;

// Finding duplicates in shorted array
void findDuplicates(int* arr, int size)
{
    int lastDuplicateElement = 0;
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] == arr[i + 1] && arr[i] != lastDuplicateElement)
        {
            cout<<arr[i]<<endl;
            lastDuplicateElement = arr[i];
        }
        
    }
}

// Also counting duplicates
void findDuplicatesWithCount(int* arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] == arr[i + 1])
        {
            int j = i + 1;
            while (arr[i] == arr[j])
            {
                j++;
            }
            cout<<"Missing value is "<<arr[i]<<" appearing "<<j - i<< " times "<<endl;
            i = j - 1;
        }
    }
}


int main(){

    int array[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int sz = sizeof(array) / sizeof(array[0]);

    findDuplicates(array, sz);
    findDuplicatesWithCount(array, sz);

    return 0;
}