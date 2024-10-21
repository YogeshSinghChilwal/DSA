#include<iostream>
#define I 32767

using namespace std;

int cost [][8] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
            
    };

int near[8] = {I,I,I,I,I,I,I,I};
int t[2][6];

int main()
{
    int i, j, u, v, n = 7, min = I;

    //Initial steps

    //finding minimum cost edge from cost upper triangular matrix
    for(i = 1; i <= n; i++)
    {
        for(j = i; j <= n; j++)
        {
            if(cost[i][j] < min)
            {   min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = 0;
    near[v] = 0;

    //updating near array
    for(i = 1; i <= n; i++)
    {
        if(near[i] != 0)
        {
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    //Repeating steps
    for(i = 1; i < n-1; i++)
    {
        min = I;

        //Finding minium from near array
        for(j = 1; j <= n; j++)
        {
            if(near[j] != 0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                u = j;
                v = near[j];
            }
        }
        
        t[0][i] = u;
        t[1][i] = v;
        near[u] = 0;
    
        //Updating nearer
        for(j = 1; j <= n; j++)
        {
            if(near[j] != 0 && cost[j][near[j]] > cost[j][u])
            {
                near[j] = u;
            }
        }
    }

    //Printing t
    int total = 0;
    for(i = 0; i < n - 1; i++)
    {
        cout<<"["<<t[0][i]<<"]"<<"---"<<"["<<t[1][i]<<"]"<< "   Cost: "<<cost[t[0][i]][t[1][i]]<<endl;
        total = total + cost[t[0][i]][t[1][i]];
    }
    cout<<endl;

    cout<<"Total cost of MST: "<<total<<endl;

    return 0;
}