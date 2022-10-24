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
   int n,m;cin>>n>>m;
   int ar[m+2];
   for(int i=0;i<m;i++)
   {
    cin>>ar[i];
   }

   sort(ar,ar+m);
   

   vector<int>dis;
   for(int i=1;i<m;i++)
   {
        dis.pb((ar[i]-ar[i-1]-1));
   }

   int d=ar[0]-1+n-ar[m-1];
   dis.pb(d);
   sort(all(dis));
   reverse(all(dis));
   
  // for(int x:dis)cout<<x<<" ";cout<<endl;

   int safe=0;
   int ex=1;
   for(int i=0;i<dis.size();i++)
   {
      // ex++;
       if(dis[i]-ex>0)
       {
        safe+=(dis[i]-ex);
       }
       else if(dis[i]-ex==0)safe++;
       ex+=4;
   }

   cout<<n-safe<<endl;

   
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


