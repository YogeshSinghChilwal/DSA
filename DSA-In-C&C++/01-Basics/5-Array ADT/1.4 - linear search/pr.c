//Linear search

#include<stdio.h>

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
int main(){
    struct Array arr1 = {{2,3,4,5,6}, 10, 5};
    // Append(&arr1, 10);
    // Insert(&arr1, 0, 12);
    // Display(arr1);
    // printf("\nElemenr deleted %d\n", Delete(&arr1, 4)) ;

    Display(arr1);

    printf("\n\nIndex is: %d\n", linearSearch(&arr1, 6));

    Display(arr1);

    return 0;
}