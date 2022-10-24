#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;

inline ll bigMod(ll a,ll b,ll mod)
{
    if(b==0)return 1%mod;
    ll ans = 1;
    while (b)
    {
        if (b&1) ans = (1ll * ans * a) % mod;
        a = (1ll * a * a) % mod;
        b /= 2;
    }
    return ans;
}

vector<int>g[200005];
int visited[200005];

int parent[200005];
void makeParent(int n)
{
    for(int i=0;i<=n;i++)parent[i]=i;
}

int findParent(int cur)
{
    if(cur==parent[cur])return cur;
    else return parent[cur]=findParent(parent[cur]);
}

int main()
{
   int n,k;cin>>n>>k;
   makeParent(n);
   for(int i=1;i<n;i++)
   {
       int u,v,s;
       cin>>u>>v>>s;
       if(s==0)
       {
           int p1=findParent(u);
           int p2=findParent(v);
           if(p1!=p2)parent[p1]=p2;
       }

   }

   map<int,int>mp;
   for(int i=1;i<=n;i++)
   {
       mp[findParent(i)]++;
   }

   ll res=bigMod(n,k,MOD);

   for(auto m:mp)
   {
       res-=(bigMod(m.second,k,MOD));
       while(res<0)res+=MOD;
   }


   cout<<res%MOD<<endl;


}
