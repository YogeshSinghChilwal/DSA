#include<iostream>
#include<queue>

using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i = start;
    queue<int> q;
    int visited[7] = {0};

    cout<<i<<endl;
    visited[i] = 1;
    q.push(i);

    while(!q.empty())
    {
        i = q.front();
        q.pop();

        for(int j = 1; j < n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                cout<<j<<endl;
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

void DFS(int A[][7], int start, int n)
{
    static int visited[7] = {0};
    int i = start;

    if(visited[i] == 0)
    {
        cout<<i<<endl;
        visited[i] = 1;
        for(int j = 1; j < n; j++)
        {
            if(A[i][j] == 1 && visited[j] == 0)
                DFS(A, j, n);
        }
    }
}

int main()
{
    int A[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};

    DFS(A,2, 7);
}