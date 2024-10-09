#include<iostream>
using namespace std;

/* In C++, pointers are variables that store the memory address of another variable. 
Pointers are a powerful feature of C++ that allows for direct memory access and manipulation.*/

int main(){
    // int a = 10;
    // cout<<a<<" ";
    // int *p;
    // p = &a;
    // int *q = &a;
    // cout<<p<<' '<<q<<' ';
    // printf("using c code: %d %d", p, &a);
    // cout<<' '<<*q;

    int A[] = {1, 2, 3, 4, 5};
    cout<<A<<endl;
    int *p;
    p = A;
    int *k = &A[1];
    cout<<*p<<" "<<*k<<endl;
    cout<<&A[0]<<endl;

    for(int i = 0; i < 5; i++)
    cout<<p[i]<<" ";
    cout<<endl;
    cout<<*p;

    // int *p;
     //! in c-lang p = (int *)malloc(5 * sizeof(int));
    // p = new int[5];
    // for(int i = 0; i < 5; i++){
    // p[i] = 2 * i + 2;
    // cout<<p[i]<<endl;
    // }

    delete []p;

}