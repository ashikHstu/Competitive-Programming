#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define TIME              clock()*1.0/CLOCKS_PER_SEC
#define pi                acos(-1.0)
#define mem(a,b)           memset(a,b,sizeof(a))
#define all(a)             a.begin(),a.end()
#define Sort(x)            sort(x.begin(),x.end())
#define Reverse(x)         reverse(x.begin(),x.end())
#define SortA(ar,s)        sort(ar,ar+s)
#define SortD(ar,s)        sort(ar,ar+s,greater<int>())
#define gcd(a,b)           __gcd(a,b)
#define lcm(a,b)           (a*(b/gcd(a,b)))
#define sq(x)              (x)*(x)
#define CEIL(a,b)          ((a/b)+((a%b)!=0))
#define sz 200005
vector<int>g[sz];
vector<pair<int,int>>res;

int visited[sz];

void dfs(int src)
{

    queue<int>q;
    q.push(src);
    visited[src]=1;

     while(!q.empty())
     {
        int u=q.front();
         q.pop();
        for(int child:g[u])
        {
            if(!visited[child])
            {
                res.pb({u,child});
                visited[child]=1;
                q.push(child);
            }
        }
     }

    
}

void solve()
{
    int n,m;cin>>n>>m;
     int degree[n+2]={0};
     int mxD=-1;
     int mxInd=-1;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].pb(v),g[v].pb(u);
        degree[u]++;
        if(degree[u]>mxD)
        {
            mxD=degree[u];
            mxInd=u;
        }
        
        degree[v]++;
        if(degree[v]>mxD)
        {
            mxD=degree[v];
            mxInd=v;
        }
    }

    dfs(mxInd);

    for(pair<int,int>p:res)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }

}

int main()
{
    int tc=1;
   // cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


