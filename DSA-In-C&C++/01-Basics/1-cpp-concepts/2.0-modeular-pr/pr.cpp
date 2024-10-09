#include<iostream>
#include<stdio.h>
using namespace std;

int area(int l, int b){
    return l * b;
}

int perimeter(int l, int b){
    int p;
    p = 2*(l + b);
    return p;
}


int main(){
    int length = 0, breadth = 0;
    printf("Enter lenght and breadth:\n");
    cin>>length>>breadth;

    int ar = area(length, breadth);
    int peri = perimeter(length, breadth);
    printf("Area is %d\nPerimeter is %d", ar, peri);
    return 0;
}