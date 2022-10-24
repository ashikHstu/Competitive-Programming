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
   int n,k;cin>>n>>k;
   int a[n+1],b[n+1];
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++)cin>>b[i];

   int up=1,down=1;

   for(int i=0;i<n-1;i++)
   {
       int nup=0,ndown=0;
       if(up)
       {
           if(abs(a[i]-a[i+1])<=k)nup=1;

           if(abs(a[i]-b[i+1])<=k)ndown=1;

       }
        if(down)
       {
          // cout<<"down working at : "<<i<<endl;
           if(abs(b[i]-a[i+1])<=k)nup=1;

           if(abs(b[i]-b[i+1])<=k)ndown=1;

       }
       up=nup;
       down=ndown;

       if(up==0 && down==0)
       {
          // cout<<"NO at : "<<i<<endl;
           cout<<"No\n";
           return;
       }
      // cout<<"at "<<i<<", up , down : "<<up<<" "<<down<<endl;

   }


   cout<<"Yes\n";


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


