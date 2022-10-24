/** Problem : https://cses.fi/problemset/task/1666/

*/

#include <bits/stdc++.h>
using namespace std;
#define mx 200005
vector<int>g[mx];
int color[mx];

void dfs(int cur)
{
    color[cur]=1;
    for(int v:g[cur])
    {
        if(!color[v])dfs(v);
    }
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int>res;
    int ct=0;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            dfs(i);
            res.push_back(i);
            ct++;
        }

    }

    cout<<ct-1<<endl;
    for(int i=1;i<ct;i++)
    {
        cout<<res[i-1]<<" "<<res[i]<<endl;
    }

    return 0;

}
