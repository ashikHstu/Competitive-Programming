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

vector<int>g[200005];
int visited[200005];
int in[200005],out[200005];
int timer;

void dfs(int src)
{
    in[src]=timer;
    timer++;
visited[src]=1;
    for(int child:g[src])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }

    out[src]=timer;
    timer++;
}

struct st
{
    int it,ot,nd;
    st(int _it,int _ot,int _nd)
    {
        it=_it;
        ot=_ot;
        nd=_nd;
    }
    bool operator<(const st &s)const{
        return it<s.it;
    }
};

void solve()
{
       
     int n;
     cin>>n;


     for(int i=1;i<n;i++)
     {
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
     
     }     

timer=1;
    dfs(1);
     int q;cin>>q;
     for(int i=0;i<q;i++)
     {
        int k;cin>>k;
        vector<st>vec;
        for(int j=0;j<k;j++)
        {
            int nd;cin>>nd;
            vec.pb(st(in[nd],out[nd],nd));
        }
        sort(all(vec));

         bool ok=true;
         for(int j=0;j<k-1;j++)
         {
            if(vec[j].ot<vec[j+1].ot)ok=false;
         }
         if(ok)cout<<"YES\n";
         else cout<<"NO\n";

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


