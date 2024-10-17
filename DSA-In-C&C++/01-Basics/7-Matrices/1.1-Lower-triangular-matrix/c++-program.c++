#include<iostream>
using namespace std;

class LowerTeri
{
    private:
        int n;
        int *arr;
    public:
        LowerTeri()
        {
            n = 3;
            arr = new int[n * (n + 1)/2];
        }

        LowerTeri(int n)
        {
            this->n = n;
            arr = new int[n];
        }

        void set(int i, int j, int val);
        int get(int i, int j);
        void display();

        ~LowerTeri()
        {
            delete []arr;
        }
};

void LowerTeri::set(int i, int j, int val)
{
    if(i >= j)
        arr[i * (i - 1) / 2 + j - 1] = val;
}

int LowerTeri::get(int i, int j)
{
    if(i >= j)
        return arr[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void LowerTeri::display()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            if(i >= j)
                cout<<arr[i * (i - 1) / 2 + j - 1]<<" ";
            else
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n, val;
    cout<<"Enter dimension ";
    cin>>n;

    LowerTeri m(n);

    cout<<"Enter values \n";

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>val;
            m.set(i, j, val);
        }
    }
    cout<<endl;

    m.display();

    return 0;
}