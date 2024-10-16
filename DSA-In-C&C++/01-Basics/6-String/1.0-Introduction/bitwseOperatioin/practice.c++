#include<iostream>
using namespace std;

void findDuplicate(char* arr)
{
    int h = 0, x = 0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        x = 1;
        x = x<<( arr[i] - 97);

        if((x & h) > 0)
            printf("%c is duplicate!\n", arr[i]);
            
        else
            h = x | h;
    }
}

int main(){
    char name[] = "finding";
    
    findDuplicate(name);
    
    return 0;
}