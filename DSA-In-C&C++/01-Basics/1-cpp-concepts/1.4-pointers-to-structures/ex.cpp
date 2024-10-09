#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};


int main(){

    // Rectangle r = {10, 5};

    // cout<<r.length<<endl<<r.breadth<<endl;

    // Rectangle *p=&r;

    // cout<<p->length<<endl<<p->breadth<<endl;

    Rectangle *p = new Rectangle;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    

    p->length = 15;
    p->breadth = 10;

    cout<<p->length<<endl<<p->breadth<<endl;

    return 0;
}