#include<iostream>
using namespace std;

struct Matrix{
    int arr[10];
    int n;
};

void Set(struct Matrix *m, int i, int j, int val)
{
    if(i == j)
        m->arr[i -1] = val;
}

int Get(struct Matrix m, int i, int j)
{
    if(i == j)
        return m.arr[i - 1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for(int i = 0; i < m.n; i++)
    {
        for(int j = 0; j < m.n; j++)
        {
            if(i == j)
                cout<< m.arr[i]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}


int main(){
    struct Matrix m;
    m.n = 5;
    Set(&m, 1, 1, 25);
    Set(&m, 2, 2, 82);
    Set(&m, 3, 3, 16);
    Set(&m, 4, 4, 12);
    Set(&m, 5, 5, 55);


    Display(m);

    return 0;
}