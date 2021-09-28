#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz 10004
vector<int>g[sz];
int vis[sz],dis[sz];

void init(int n)
{
    for(int i=0;i<=n;i++)g[i].clear(),vis[i]=0;
}

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    dis[src]=0;
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:g[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n,m;cin>>n>>m;
    init(n);
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs(1);
    cout<<dis[n]<<endl;
    return;
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}

