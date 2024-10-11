#include<iostream>
using namespace std;

int main(){
    int A[5];
    int B[5] = {1,2,3,4,5};
    int C[5] = {1,2};
    int D[] = {1,2,3,4};
    int E[5] = {0};
    //int E[5] = {1,2,3,4,5,6}

    cout<<2[B]<<"\n";
    cout<<*(B + 2)<<endl;       // prints values

    for(auto& element : B){
        cout<<&element<<" "; // prints address
        cout<<element<<" " << endl; // prints values
    }
}