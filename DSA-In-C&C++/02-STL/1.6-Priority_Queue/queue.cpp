#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(10);
    maxi.push(20);
    maxi.push(30);
    maxi.push(0);
    maxi.push(50);
    maxi.push(15);

    int size = maxi.size();

    mini.push(10);
    mini.push(20);
    mini.push(30);
    mini.push(0);
    mini.push(50);
    mini.push(15);

    int Msize = mini.size();

    for(int i = 0; i < Msize; i++)
    {
        cout<<"In max heap: "<<i+1<<". "<<maxi.top()<<"     ";
        maxi.pop();
        cout<<"In min heap: " <<i+1<<". "<<mini.top();
        mini.pop();

        cout<<endl;
    }

}