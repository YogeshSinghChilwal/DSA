#include<iostream>
using namespace std;

/*
In C++, there are three main methods for passing parameters to functions: pass by value, pass by reference, and pass by pointer. 
Each method has its own characteristics and use cases.

1. Pass by Value
In pass by value, a copy of the actual parameter is passed to the function. 
This means changes made to the parameter inside the function do not affect the original argument.

2. Pass by Reference
In pass by reference, a reference (alias) to the actual parameter is passed to the function. 
This allows the function to modify the original argument.

3. Pass by Pointer
In pass by pointer, the address of the actual parameter is passed to the function. 
The function can then modify the value at that address.
*/

int value(int a){
    a++;
    cout<<a;
    return 0;
}

int address(int *a){
    (*a)++;
    cout<<*a<<" ";
    return 0;
}

int reference(int &a){
    a++;
    cout<<a;
    return 0;
}


int main(){
    int x = 10;

    value(x);
    cout<<endl<<x<<' ';

    address(&x);
    cout<<endl<<x<<' ';

    reference(x);
    cout<<endl<<x<<endl;
    return 0;
}