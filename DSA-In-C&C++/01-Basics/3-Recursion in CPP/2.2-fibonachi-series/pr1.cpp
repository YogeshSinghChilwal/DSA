#include<iostream>
using namespace std;

int fib1(int n){
    int t0 = 0, t1 = 1, s, i;
    if( n <= 1) return 1;
    for( i = 2; i <= n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib2(int n){
    if(n <= 1)
        return n;
    return fib2(n - 2) + fib2(n - 1);
}

int F[10];

int fib3(int n){
    if(n <= 1){
        F[n] = n;
        return n;
    } else{
        if(F[n - 2] == -1) 
            F[n - 2] = fib3(n - 2);

        if(F[n - 1] == -1) 
            F[n - 1] = fib3(n - 1);

        F[n] = F[n - 2] + F[n -1];

        return F[n - 2] + F[n - 1];
    }
}

int main(){
    //cout<<fib2(7);
    for(int i = 0; i < 10; i++)
        F[i] = -1;

    cout<<fib3(7);
    return 0;
}