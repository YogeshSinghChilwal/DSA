//Reversing

#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    printf("\nElements are\n");
    for(int i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    
    return 0;
    
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            // swap(&arr->A[i], &arr->A[i - 1]);
            // return i - 1;
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
        
        
    }
    return -1;
}

int binSearch(struct Array arr, int key)
{
    int low, high, mid;
    low = 0;
    high = arr.length - 1;
    while( low <= high)
    {
        mid = (low + high) / 2;
        if(key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int rBinSearch(int a[], int l, int h, int key){
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if(a[mid] == key)
            return mid;
        else if(key < a[mid])
            return rBinSearch(a, l, mid - 1, key);
        else 
            return rBinSearch(a, mid + 1, h, key);
    }
    return -1;
    
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
    
}

int Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
    return -1;
    
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
        
    }
    return max;
    
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
        
    }
    return min;
    
}

int Sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total = total + arr.A[i];
    }

    return total;
    
}

float Avg(struct Array arr)
{

    return  (float)Sum(arr) / arr.length;
    
}

 void Reverse(struct Array *arr)
 {
    int *B;
    int i,j;
    
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
 }

void Reverse2(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    
}

void Inserting(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
    {
        return;
    }
    
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
    
}

int AlgorithmIsShorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
    
}

void Rearrange(struct Array *arr){
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while(arr->A[i] < 0) {i++;}
        while(arr->A[j] >= 0) {j--;}
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

int main(){
    struct Array arr1 = {{2,-3,5,-6,7}, 10, 5};
    
    Display(arr1);

    // printf("\n%d",  Get(arr1, 2));

    // Set(&arr1, 2, 1);

    // Display(arr1);

    // printf("\n%d", Max(arr1));
    // printf("\n%d", Min(arr1));

    // printf("\n%d", Sum(arr1));
    // printf("\n%f", Avg(arr1));
    
    // Reverse(&arr1);

    // Display(arr1);

    // Inserting(&arr1, 4);
    // printf("\n%d", AlgorithmIsShorted(arr1));
    Rearrange(&arr1);
    Display(arr1);

    return 0;
}