#include<iostream>
#include<stdio.h>
using namespace std;


int main(){
    int length = 0, breadth = 0;
    printf("Enter lenght and breadth");
    cin>>length>>breadth;

    int area = length * breadth;
    int peri = 2*(length + breadth);
    printf("Area is %d\n Perimeter is %d", area, peri);
    return 0;
}