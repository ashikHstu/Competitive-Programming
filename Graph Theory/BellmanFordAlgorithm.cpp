#include <bits/stdc++.h>
using namespace std;
#define infinity 1<<28
void bellman(int n,vector<int>g[],vector<int>cost[],int source)
{
    int distance[n+1];
    for(int i=1;i<=n;i++)
    {
        distance[i]=infinity;
    }
    distance[source]=0;
    bool neg_cycle=false;

    for(int k=1;k<=n;k++)
    {
        bool updated=false;
        for(int u=1;u<=n;u++)
        {
            for(int i=0;i<(int)g[u].size();i++)
            {
               int v=g[u][i];
                if(distance[u]+cost[u][i]<distance[v])
                {
                    distance[v]=distance[u]+cost[u][i];
                    updated=true;
                }
            }
        }
        if(k==n and updated==true)
        {
            neg_cycle=true;
        }
    }
    if(neg_cycle){
        cout<<"Negative cycle detected.\n";

    }
    else {
        for(int i=1;i<=n;i++)
        {
            cout<<source<<" --> "<<i<<" = "<<distance[i]<<endl;
        }
    }
}
int main()
{
    vector<int>g[10000],cost[10000];
    int numNode,numEdge;
    cin>>numNode>>numEdge;
    for(int i=0;i<numEdge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int source;
    cin>>source;
    bellman(numNode,g,cost,source);
    return 0;
}
