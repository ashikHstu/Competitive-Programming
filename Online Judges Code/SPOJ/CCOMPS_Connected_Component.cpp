#include <bits/stdc++.h>
using namespace std;
#define mx 100005
 int n,e;
 vector<int>g[mx];
 int visited[mx];

 void dfs(int cur)
 {
     visited[cur]=1;
     for(int v:g[cur])
     {
         if(!visited[v])dfs(v);
     }
 }

int main()
{

    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int connected_component=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            connected_component++;
        }
    }

    cout<<connected_component<<endl;
    return 0;
}
