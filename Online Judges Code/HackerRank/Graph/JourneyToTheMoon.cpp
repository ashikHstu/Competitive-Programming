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
    int n,e;
    cin>>n>>e;

    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        visited[i]=0;
    }


    for(int i=0;i<e;i++)
    {
        int u,v;cin>>u>>v;g[u].push_back(v);
        g[v].push_back(u);
    }


  vector<int>ast;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ct=0;
            dfs(i);
          ast.push_back(ct);
        }
    }

    sort(ast.begin(),ast.end());
    int res=0;
    int sum=0;
    for(int i=0;i<ast.size();i++)
    {
        if(i==0)
        {
            sum=ast[i];
            continue;
        }
        res+=(sum*ast[i]);
        sum+=ast[i];
    }

   // cout<<"res : ";
    cout<<res<<endl;

}

int32_t main()
{
    int tc=1;
    //cin>>tc;

    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

