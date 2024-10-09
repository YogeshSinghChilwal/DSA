#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initalise(Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}


int area(Rectangle r){
    return r.length * r.breadth;
}

int perimeter(Rectangle r){
    int p;
    p = 2*(r.length + r.breadth);
    return p;
}


int main(){
    
    Rectangle r = {0,0};

    int l, b;

    printf("Enter lenght and breadth:\n");
    cin>>l>>b;

    initalise(&r, l, b);

    int ar = area(r);
    int peri = perimeter(r);
    printf("Area is %d\nPerimeter is %d", ar, peri);
    return 0;
}