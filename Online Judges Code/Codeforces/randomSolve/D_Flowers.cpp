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
#define MOD 1000000007

ll res[200005];
ll sum[200005];

void calculate(int n,int k)
{
    for(int i=0;i<=200000;i++)
    {
        if(i<k)res[i]=1;
        else res[i]=(res[i-1]+res[i-k])%MOD;
    }

    for(int i=1;i<200000;i++)
    {
        sum[i]=(sum[i-1]+res[i])%MOD;
    }
}

void solve()
{
  int n,k;cin>>n>>k;
  calculate(n,k);
  for(int i=0;i<n;i++)
  {
    int l,r;
    cin>>l>>r;
   ll rr=(sum[r]-sum[l-1])%MOD;
   if(rr<0)rr+=MOD;

   cout<<rr<<endl;
  }
}

int main()
{
    int tc=1;
  //  cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


