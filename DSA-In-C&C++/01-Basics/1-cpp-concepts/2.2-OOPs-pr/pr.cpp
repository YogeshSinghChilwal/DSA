#include<iostream>
#include<stdio.h>
using namespace std;

class Rectangle
{
public:
    int length;
    int breadth;

    void initalise(int l, int b){
        length = l;
        breadth = b;
    }


    int area(){
        return length * breadth;
    }

    int perimeter(){
        int p;
        p = 2*(length + breadth);
        return p;
    }

};

int main(){
    
    Rectangle r = {0,0};

    int l, b;

    printf("Enter lenght and breadth:\n");
    cin>>l>>b;

    r.initalise(l, b);

    int ar = r.area();
    int peri = r.perimeter();
    printf("Area is %d\nPerimeter is %d", ar, peri);
    return 0;
}