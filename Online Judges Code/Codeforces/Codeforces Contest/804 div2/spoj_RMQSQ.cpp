#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
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
#define sz 1000006


vector<ll>g[sz];
ll visited[sz];
ll res;
ll nodeValues[sz];
ll mainR=0;
bool hobeNa=false;

void dfs(ll src,ll diche)
{
    visited[src]=1;
    if(nodeValues[src]%diche!=0 || diche>nodeValues[src])
    {
        hobeNa=true;
        return;
    }
    if(diche<nodeValues[src])mainR++;
    for(ll v:g[src])
    {
        if(visited[v]==0)dfs(v,nodeValues[src]);
    }  
    visited[src]=2;

}

void solve()
{
   int n;
   cin>>n;
   mainR=0;
   hobeNa=false;
   for(int i=2;i<=n;i++)
   {
      int p;
      cin>>p;
      g[p].pb(i);
      g[i].pb(p);
   }
   for(int i=1;i<=n;i++)cin>>nodeValues[i];

    
    dfs(1,1);
  if(hobeNa)cout<<"-1\n";
  else
    cout<<mainR<<endl;
 


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


