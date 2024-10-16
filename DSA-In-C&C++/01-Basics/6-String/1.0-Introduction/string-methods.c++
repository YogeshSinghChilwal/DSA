#include<iostream>
using namespace std;

int Length(char* arr)
{
    int i;
    for(i = 0; arr[i] != '\0'; i++){}
    return i;
}

char* ChangeToLowerCase(char* arr)
{
    for(int i = 0; arr[i] != '\0'; i++)
    {
        arr[i] = arr[i] + 32;
    }

    return arr;
}

int main(){

    // char name[] = "Yogesh";
    // cout<<Length(name);

    char name2[] = "YOGESH";
    
    // cout<<name2;

    printf("%s", ChangeToLowerCase(name2));
    return 0;
}