/*First put number of node then put the node number and their weight.
 then put number of edges and put start and end of an edges and put also the path cost */

#include<bits/stdc++.h>
using namespace std;
const int N=100;
typedef pair<int,int> pii;

int Hsld[N];
vector<int>connected[N];
int parent[N],dist[N],cost[N][N],pathCost[N];
vector<pii>path;

bool AStar(int s,int goal)
{
    for(int i=0;i<N;i++)parent[i]=i,dist[i]=0;
    priority_queue<pii,vector<pii>,greater<pii> > q;

    q.push({0,s});
    pathCost[s]=dist[s]=0;
    while(!q.empty())
        {
            pii t=q.top();
            q.pop();
            int u=t.second;
            if(u!=parent[u])
                path.push_back({parent[u],u});
            if(u==goal)return 1;
            for(int i=0; i<connected[u].size(); i++)
                {
                    int v=connected[u][i];
                    pathCost[v]=pathCost[u]+cost[u][v];
                    dist[v]=Hsld[v]+pathCost[v];
                    parent[v]=u;
                    q.push({dist[v],v});
                }
        }
    return 0;
}
void print(int s)
{
    for(auto p:path)
        cout<<p.first<<"->"<<p.second<<endl;
}
int main()
{
    int node,edges,u,v,d,sld;
    cin>>node;
    for(int i=0;i<node;i++)
    {
        cin>>u>>sld;
        Hsld[u]=sld;
    }
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v>>d;
        connected[u].push_back(v);
        connected[v].push_back(u);
        cost[u][v]=d;
        cost[v][u]=d;
    }
    int source,goal;
    cin>>source>>goal;

    if(AStar(source,goal))
    {
        cout<<"found\n";
        print(goal);
        cout<<endl<<pathCost[goal];
    }
}
/*
20
1 366
2 0
3 160
4 242
5 161
6 176
7 77
8 151
9 226
10 244
11 241
12 234
13 380
14 100
15 193
16 253
17 329
18 80
19 199
20 374
23
1 20 75
20 13 71
13 16 151
1 16 140
1 17 118
16 6 99
16 15 80
6 2 211
15 14 97
14 2 101
15 3 146
14 3 138
17 10 111
10 11 70
11 4 75
4 3 120
7 2 90
12 9 87
9 19 92
19 18 142
18 8 98
8 5 86
2 18 85
*/



