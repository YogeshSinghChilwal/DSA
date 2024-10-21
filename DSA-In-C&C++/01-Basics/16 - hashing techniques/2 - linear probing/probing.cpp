#include<iostream>
using namespace std;


int Hash(int x)
{
    return x % 10;
}

int probe(int H[], int x)
{
    int idx, i = 0;
    while(H[(Hash(x) + i) % 10] != 0)
        i++;
    idx = (Hash(x) + i) % 10;
    return idx;
}

void insert(int* H, int key)
{
    int index;
    index = Hash(key);

    if(H[index] != 0)
        index = probe(H, key);
    
    H[index] = key;
}

int Search(int* H, int key)
{
    int index, i = 0;
    index = Hash(key);

    if(H[index] == key)
        return index;

    if(H[index] == 0)
        return -1;
    else if(H[index] != key)
    {
        while(H[index] != key && H[index] != 0)
        {
            i++;
            index = (Hash(key) + i) % 10;
            if(H[index] == key)
                return index;
        }
    }

    return -1;
    
}


int main()
{
    int H[10] = {0};
    insert(H, 27);
    insert(H, 47);
    insert(H, 22);
    insert(H, 57);
    insert(H, 7);


    cout<<Search(H, 7)<<endl;

    cout<<H[0];
}