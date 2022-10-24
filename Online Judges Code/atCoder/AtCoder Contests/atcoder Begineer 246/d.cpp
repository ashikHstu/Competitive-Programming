#include <bits/stdc++.h>
using namespace std;
#define  ll long long int

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
#define SQrt(x)              (x)*(x)
#define CEIL(a,b)          ((a/b)+((a%b)!=0))

ll res(ll a,ll b)
{
    return (a*a*a+a*a*b+a*b*b+b*b*b);
}

//ll SQrt(ll a)
//{
//    return a*a;
//}


void solve()
{
   ll n;cin>>n;
   ll mx=1000000000000000000LL;
   ll j=1000000;
   for(int i=0;i<=1000000;i++)
   {
       while(res(i,j)>=n && j>=0)
       {
           //cout<<"working"<<endl;
           mx=min(mx,res(i,j));
           j--;
       }
   }
   cout<<"res : ";
   cout<<mx<<endl;
}

int32_t main()
{
    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }


    return 0;
}


