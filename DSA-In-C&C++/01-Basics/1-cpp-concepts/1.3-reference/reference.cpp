#include<iostream>
using namespace std;

/*In C++, references provide an alternative way to access memory addresses, similar to pointers, but they are safer and easier to use. 
A reference is essentially an alias for another variable, allowing you to work with the original variable directly under another name.*/

int main (){
    int a = 10;
    int &r = a;
    a++;
    cout<<r<<endl;  // 11
}