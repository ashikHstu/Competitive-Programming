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
int k;
int doneSoFar;
bool hoiche;
map<int,int>mp;
int vs;
int dfs(int src)
{
    //cout<<"src called"<<src<<endl;
    visited[src]=1;
    if(mp[src]!=0)
    {
        vs++;
        doneSoFar++;
    }

    for(int child:g[src])
    {
        
        if(!visited[child] && !hoiche)dfs(child); 
    }
    
    if(mp[src]!=0)hoiche=true;

}

void solve()
{
     int n;
     cin>>n;


     for(int i=1;i<n;i++)
     {
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
     
     }     

     int q;cin>>q;
     for(int i=0;i<q;i++)
     {
        doneSoFar=0;
        memset(visited,0,sizeof(visited));
        mp.clear();
        cin>>k;
        int start;
        for(int j=0;j<k;j++)
        {
            int vv;cin>>vv;
            mp[vv]++;
            start=vv;
        }
        visited[start]=1;
        int lf=0;
         for(int ch:g[start])
         {
             if(!visited[ch])
             { hoiche=false;
             vs=0;
          //   cout<<"before dfs"<<endl;
                dfs(ch);
            //    cout<<"after dfs\n"<<endl;
                if(vs>0)lf++;
             }
         }



         if(lf>2 || doneSoFar+1!=k)
         {
            cout<<"NO\n";
         }
         else cout<<"YES\n";




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


