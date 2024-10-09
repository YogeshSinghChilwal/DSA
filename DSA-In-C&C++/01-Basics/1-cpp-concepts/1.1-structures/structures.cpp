#include<iostream>
using namespace std;

/*
In C++, a structure (or struct) is a user-defined data type that allows grouping variables of different data types under one name. 
Structs in C++ are similar to classes, but by default, all members of a struct are public, unlike classes where members are private by default.*/

struct Rectangle
{
    int length;
    int breath;
    char name;   //padding -> total memory = 9 but taking 12
} r3, r4;

struct Rectangle r2;

int main(){

    struct Rectangle r1 = {10, 5, 'a'};
    cout<<sizeof(r1);
    cout<<endl;
    r1.length = 2;
  
    cout<<r1.length<<" "<<r1.breath<<" "<<r1.name;


    return 0;
}