#include<iostream>
using namespace std;

/*In C++, a function is a block of code that performs a specific task. Functions help to organize code, improve readability, and facilitate code reuse. 
They can take inputs (parameters), perform operations, and return results.*/

int add(int a, int b){
    int s = a + b;
    return s;
}

int main(){
    int num1 = 10, num2 = 5, sum;

    sum = add(num1, num2);

    cout<<"Sum is "<<sum;

    return 0;
}