#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<string> q;

    q.push("Ram");
    q.push("Jon");
    q.push("Yogesh");

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    q.pop();

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
}