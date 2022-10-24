#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int>g[200005];
int visited[200005];
vector<int>elem;
int status=0;



void dfs(int src)
{
    visited[src]=1;

    for(int v:g[src])
    {
        if(visited[v]==1)status=-1;
        if(visited[v]==0)dfs(v);

    }

    elem.push_back(src);
    visited[src]=2;

}

int32_t main()
{
    int n,e;cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
       // g[u].push_back(v)
        g[v].push_back(u);
    }
vector<int>res;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }

//        int szz=elem.size();
//        for(int j=0;j<szz;j++)
//        {
//            res.push_back(elem[j]);
//        }
//        elem.clear();
    }
    if(status==-1)cout<<"-1";
    else {
            //reverse(elem.begin(),elem.end());
    for(int val:elem)cout<<val<<" ";cout<<endl;
       // for(int val:res)cout<<val<<" ";
    }




    return 0;
}


