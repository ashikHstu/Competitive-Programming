#include <bits/stdc++.h>
using namespace std;
vector<int>g[10004];
int visited[10004];
int dis[10004];
pair<int,int>pr;
void dfs(int u,int d)
{
    if(d>pr.second)pr={u,d};
    visited[u]=1;
    dis[u]=d;
    for(int v:g[u])
    {
        if(!visited[v])dfs(v,d+1);
    }
}

int main()
{
    int n,u,v;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pr={0,-1};
    dfs(1,0);
    int secondCall=pr.first;
    pr={0,-1};
    memset(visited,0,sizeof(visited));
    dfs(secondCall,0);
    cout<<pr.second<<endl;
    return 0;
}

