#include<iostream>
using namespace std;

void compare(char* A, char* B)
{
    int i, j;
    for(i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if(A[i] != B[j])
            break;
    }

    if(A[i] == B[j]) printf("Equal");
    else if(A[i] < B[j]) printf("Smaller");
    else printf("Larger");
}


int main(){

    char A[] = "yogesh";
    char B[] = "yogesh";
    compare(A, B);
    return 0;
}