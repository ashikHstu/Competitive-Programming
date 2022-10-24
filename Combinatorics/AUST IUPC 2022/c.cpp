#include <bits/stdc++.h>
using namespace std;
#define sz 300005
vector<int>g[sz+2],cost[sz+2];

void solve(int kase)
{
    int n,m;cin>>n>>m;
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        int mn=min(u,v),mx=max(u,v);
        pair<int,int>p=make_pair(mn,mx);

    }



}

int main()
{
    int tc;cin>>tc;
    for(int i=1;i<=tc;i++)solve(i);

    return 0;
}
