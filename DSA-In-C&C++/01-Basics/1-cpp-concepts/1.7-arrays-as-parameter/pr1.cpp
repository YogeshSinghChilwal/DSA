#include<iostream>
using namespace std;

void fun1(int *A, int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    A[0] = 77;
}

int *fun2(int n){
    int *p;
    p = new int[n];
    return p;
}

int main(){
    // int A [] = {1, 2, 3, 4, 5};
    // int n = sizeof(A) / sizeof(A[0]);
    // fun1(A, n);
    // cout<<endl;
    // cout<<n<<endl;

    // for(int x:A)
    //     cout<<x<<" ";

    int *A;
    A = fun2(5);

    A[0] = 1;
    A[1] = 2;
    cout<<A[0]<<" "<<sizeof(A);

    return 0;
}