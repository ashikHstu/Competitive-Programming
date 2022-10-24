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

void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n+1);

    for(int i=1;i<=n;i++)cin>>v[i];

v[0]=0;
for(int i=1;i<=n;i++)
{
    v[i]+=v[i-1];
}


ll res=0;
for(int i=1;i<=n;i++)
{

     if(v[i]-v[i-1]>x)continue;

      ll l=i,r=n;
      int tres=l;
      while(l<=r)
      {
          ll mid=(l+r)/2;
          ll cur=v[mid]-v[i-1];
          if(cur<=x)
          {
              l=mid+1;
              tres=mid;
          }
          else {
              r=mid-1;
          }
      }
      res+=(tres-i+1);
     // cout<<"step res : "<<tres<<endl;
}


cout<<res<<endl;


  

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


