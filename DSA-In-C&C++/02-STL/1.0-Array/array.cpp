#include<iostream>
#include<array>

using namespace std;

int main()
{
    int A[] = {1, 2, 3};

    array<int,4> a = {1, 2, 3, 4};

    //int n = A.size(); wrong

    int n = a.size();

    for(int i = 0; i < n; i++)
        cout<<a[i]<<"   ";
    
    cout<<endl;

    cout<<a[2]<<endl;
    cout<<a.at(2)<<endl;

    cout<<a.empty()<<endl; // returns bool

    cout<<a.front()<<"  "<<a.back()<<endl;   // all at O(1)



}