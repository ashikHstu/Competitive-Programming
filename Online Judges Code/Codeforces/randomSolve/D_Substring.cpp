/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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
#define NUMLEN(Num)        to_string(Num).size()

#define POSL(x,v)          (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v)          (upper_bound(x.begin(),x.end(),v)-x.begin())
#define min3(a,b,c)        min(a,min(b,c))
#define min4(a,b,c,d)      min(a,min(b,min(c,d)))
#define max3(a,b,c)        max(a,max(b,c))
#define max4(a,b,c,d)      max(a,max(b,max(c,d)))
#define ABS(x)             ((x)<0?-(x):(x))
#define pb                 push_back
#define nl                 printf("\n")

///vector
#define Lower_bound(vec,value) lower_bound(vec.begin(),vec.end(),value)
#define Upper_bound(vec,value) upper_bound(vec.begin(),vec.end(),value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))

/// File In
#define READ(f)              freopen(f,  "r" ,stdin)
#define WRITE(f)             freopen(f,  "w" ,stdout)

const int mod = 1e9 + 7;
const int maxn=300005;

bool color[maxn];
bool resStack[maxn];
vector<int>adj[maxn];
string st;
int maxAche[maxn][30];
string nodeSt[maxn];
bool has_cycle;
int res=0;
void dfs_visit(int n,int node)
{
    if(has_cycle)return;
    color[node]=resStack[node]=1;
 

    int l=adj[node].size();
    for(int i=0;i<l;i++)
    {
        if(resStack[adj[node][i]])
        {
            has_cycle=1;
            return;

        }
        else if(!color[adj[node][i]]){
            dfs_visit(n,adj[node][i]);
        }
        for(int p=0;p<26;p++)
        {
            maxAche[node][p]=max(maxAche[node][p],maxAche[adj[node][i]][p]);
            res=max(res,maxAche[node][p]);
        }
    }
    resStack[node]=0;

  
    maxAche[node][st[node-1]-'a']++;
    res=max(res,maxAche[node][st[node-1]-'a']);

}
void dfs(int n)
{
    has_cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(has_cycle)return;
        if(!color[i])
        {
            dfs_visit(n,i);

        }
    }
}



void solve()
{
   int n,m;cin>>n>>m;
   cin>>st;
   for(int i=0;i<m;i++)
   {
    int u,v;cin>>u>>v;
    adj[u].pb(v);
   }

   dfs(n);

   if(has_cycle)
   {
    cout<<"-1\n";
    return;
   }

   cout<<res<<endl;

//    for(int i=1;i<=n;i++)
//    {
//     for(int j=0;j<26;j++)
//     {
//         cout<<maxAche[i][j]<<" ";
//     }cout<<endl;
//    }

   
}

int main()
{
    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

 
 /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
