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
#define sz 300005

vector<int>g[sz];
int visited[sz+2];
int subTreeSz[sz];
int dfs(int src)
{
    visited[src]=1;
    int mx=0;
    subTreeSz[src]=1;
    vector<int>infected,values;
    int totalSum=0;
    for(int v:g[src])
    {
        if(visited[v]==0)
        {
           int info=dfs(v);
           totalSum+=info;
           int t=subTreeSz[v]-1;
            subTreeSz[src]+=subTreeSz[v];
            infected.push_back(v);
            values.push_back(info);
        }
    }

int res=0;
     for(int i=0;i<values.size();i++)
     {
        int t=subTreeSz[infected[i]]-1+totalSum-values[i];
        res=max(res,t);
     }

     




    
    

    return res;
}



void solve()
{
    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }


   int res=dfs(1);
   cout<<res<<endl;


  for(int i=0;i<=n;i++)
  {
    g[i].clear();
    visited[i]=0;
  }

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


