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

ll dp[100005][88];
ll ar[100005];
ll n,k;

ll findNew(ll v,ll p)
{
   // if(p>35)return 0;
    for(int i=1;i<=p;i++){
        v/=2;
        if(v<=0)return 0;
    }
    return v;
}

ll fun(ll cur,ll d)
{
   // cout<<"call : "<<cur<<" , "<<d<<endl;
    if(dp[cur][d]!=-1)return dp[cur][d];
    if(d>35)
    {
        return dp[cur][d]=0;
    }


    ll exv=findNew(ar[cur],d);
  
     
    if(cur==n)
    {
        return dp[cur][d]=max(exv-k,exv/2);
    }
     ll v=exv-k+fun(cur+1,d);
     ll v2=exv/2+fun(cur+1,d+1);
     ll rr=max(v,v2);
     if(rr<0)rr=0;

    // cout<<"value at "<<cur<<" : "<<rr<<endl;
     return dp[cur][d]=rr;
   

}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>ar[i];
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<88;j++)dp[i][j]=-1;
    }
    cout<<fun(1,0)<<endl;
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


