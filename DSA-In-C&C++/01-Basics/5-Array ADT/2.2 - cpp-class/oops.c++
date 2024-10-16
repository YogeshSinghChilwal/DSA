#include<iostream>
using namespace std;
template<class T>
class Array
{
    private:
        T *A;
        int size;
        int length;

    public:
        Array()
        {
            size = 10;
            A = new T[10];
            length = 0;
            void Swap(T *x, T *y);
        }

        Array(int sz)
        {
            size = sz;
            A = new T[size];
            length = 0;
        }
        ~Array()
        {
            delete []A;
        }

        void Display();
        void Insert(int index, T x);
        T Delete(int index);
        int LinrarSearch(T key);
        int BinarySearch(T key);
};

template<class T>
void Array<T>::Display()
{
    for(int i = 0; i < length; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void Array<T>::Insert(int index, T x)
{
    if(index >= 0 && index <= length)
    {
        for(int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
        
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    T x;
    if(index >= 0 && index < length)
    {
        x = A[index];
        for(int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}


template<class T>
void Swap(T *x, T *y)
{
    T z;
    z = *y;
    *y = *x;
    *x = z;
}

template<class T>
int Array<T>::LinrarSearch(T key)
{
    for(int i = 0; i < length; i++)
    {
        if(A[i] == key)
        {
            Swap(&A[i], &A[0]);
            return 0;
        }
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(T key)
{
    int low, mid, high;
    low = 0;
    high = length - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if(A[mid] == key)
            return mid;
        
        if (key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
        
    }

    return -1;
}

int main()
{
    Array<int> arr(10);

    arr.Insert(0, 3);
    arr.Insert(1, 6);
    arr.Insert(2, 4);

    arr.Display();

    cout<<arr.Delete(1)<<" Deleted!"<<endl;

    arr.Display();

    cout<<arr.BinarySearch(4);

    return 0;
}