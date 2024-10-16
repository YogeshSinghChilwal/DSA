#include<iostream>
using namespace std;

// When the elements are first n natural numbers
void missing1(int* arr, int sz)
{
    int sum = 0;
    int n = arr[sz - 1];
    int sumOfN = n * (n + 1)/2;

    for(int i = 0; i < sz; i++)
    {
        sum = sum + arr[i];
    }

    cout<<"Missing value is "<<sumOfN - sum<<endl;
}

// When the elements are not first N natural numbers
void missing2(int* arr, int size)
{
    int diff = arr[0] - 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] - i != diff)
        {   cout<<"Missing value is "<< i + diff<<endl;
            break;
        }
    }
}

// Finding multiple missing elements
void missing3(int* arr, int size)
{
    int diff = arr[0] - 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] - i != diff)
        {
            while(diff < arr[i] - i)
            {
                cout<<"Missing value is "<< i + diff<<endl;
                diff++;
            }
        }
    }
}

// For an unsorted array
void missing4(int* arr, int sz, int lowVal, int maxVal)
{
    int hashArr[maxVal -lowVal + 1] = {0};

    for(int i = 0; i < sz; i++)
        hashArr[arr[i]]++;

    for(int i = lowVal; i < maxVal; i++)
    {
        if(hashArr[i] == 0)
            cout<<"Missing value is "<<i<<endl;
    }
}

int main()
{
    // int array[] = {1, 2, 3, 5, 6};
    // int size = sizeof(array) / sizeof(array[0]);
    // missing1(array, size);

    // int array2[] = {3, 4, 6, 7, 8};
    // int size2 = sizeof(array2) / sizeof(array2[0]);
    // missing2(array2, size2);

    // int array3[] = {3, 4, 6, 7, 8, 11, 12};
    // int size3 = sizeof(array3) / sizeof(array3[0]);
    // missing3(array3, size3);

    int array4[] = {5, 3, 1, 6, 9, 8, 11, 12};
    int size3 = sizeof(array4) / sizeof(array4[0]);
    missing4(array4, size3, 1, 12);


    return 0;
}