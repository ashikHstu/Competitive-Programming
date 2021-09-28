#include <bits/stdc++.h>
using namespace std;
#define infinity 1<<30 // 2^30
struct node
{
    int u;
    int cost;
    node(int _u,int _cost)
    {
        u=_u;
        cost=_cost;
    }
    bool operator < (const node &p) const
    {
        return cost>p.cost;
    }
};
void dijkstra(int n,vector<int>g[],vector<int>cost[],int source)
{
    int distance[n+1];
    for(int i=1; i<=n; i++)
    {
        distance[i]=infinity;
    }
    priority_queue<node>q;
    q.push(node(source,0));
    distance[source]=0;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        int u=top.u;
        for(int i=0; i<(int)g[u].size(); i++)
        {
            int v=g[u][i];
            if(distance[u]+cost[u][i]<distance[v])
            {
                distance[v]=distance[u]+cost[u][i];
                q.push(node(v,distance[v]));
            }
        }
    }
    cout<<"minimum cost from source is : "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<source<<" --> "<<i<<" = "<<distance[i]<<endl;
    }
}
int main()
{
    vector<int>g[10000],cost[10000];//this code can handle maximum 10000 nodes
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
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
    dijkstra(n,g,cost,source);
    return 0;
}



