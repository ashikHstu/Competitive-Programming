#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int>g[100005];
int visited[100005];
int ct=0;

void dfs(int u)
{
    visited[u]=1;
    //cout<<"visiting node : "<<u<<endl;
    ct++;
    for(int v:g[u])
    {
        if(!visited[v])dfs(v);
    }
}

void solve()
{
    int n,e,library,road;
    cin>>n>>e>>library>>road;

    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        visited[i]=0;
    }
    ct=0;

    for(int i=0;i<e;i++)
    {
        int u,v;cin>>u>>v;g[u].push_back(v);
        g[v].push_back(u);
    }

    if(library<=road)
    {
        cout<<(library*n)<<endl;
        return;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            ct=0;
            dfs(i);
           // cout<<"ct : "<<ct<<endl;
            res=res+(library+((ct-1)*road));
        }
    }

    cout<<res<<endl;
}

int32_t main()
{
    int tc;
    cin>>tc;

    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}
