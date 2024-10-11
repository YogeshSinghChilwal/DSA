#include<iostream>
#include <bits/stdc++.h>
// #include <span>
using namespace std;

int main(){
    int A[10] = {1,2,3,4,5};
    int *p;
    p = new int[10];        // in c++
    int *m;
    m = (int *)malloc(10*(sizeof(int)));        // in c

    int size = 4;

    int* arr = new int[size]{1, 2, 3, 4, 5}; // Dynamically allocate an array

    p[0] = 1;
    p[1] = 3;
    p[2] = 4;

    m[0] = 2;
    m[3] = 4;

    for(auto& element : A) cout<<element<<" ";
    cout<<endl;

    // for(auto& element : span()) cout<<element<<" ";
    // cout<<endl;

    // for(auto& element : m) cout<<element<<" ";
    // cout<<endl;

    for(int i = 0; i < sizeof(p); i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < sizeof(m); i++){
        cout<<m[i]<<" ";
    }
}