#include<iostream>
using namespace std;
int i = 1;
int TOH(int n, int A, int B, int C){
    if(n > 0){
        TOH(n - 1, A, C, B);
        cout<<i<<". "<<"("<<A<<","<<C<<")";
        cout<<endl;
        i++;
        TOH(n - 1, B, A, C);
    }
}

int main(){
    TOH(3, 1, 2, 3);
    return 0;
}