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
   int n;cin>>n;
   vector<ll>vec;

   map<ll,ll>mp;
   ll t=1;
   ll sum=0;
   for(int i=0;i<30;i++)
   {
       vec.pb(t);
       mp[t]=1;
       sum+=t;
       t*=2;
   }
   int ct=0;

   for(int i=1000000000;i>=1;i--)
   {
       if(mp[i]==0)
       {
           vec.pb(i);
           mp[i]=1;
           sum+=i;
           ct++;
       }
       if(ct>=70)break;
   }

   for(int i=0;i<100;i++)
   {
       cout<<vec[i]<<" ";
   }cout<<endl;

   for(int i=0;i<100;i++)
   {
    ll v;cin>>v;
       vec.pb(v);
       sum+=v;
   }

   ll half=sum/2;
   sort(all(vec));
   for(int i=199;i>=0;i--)
   {
       if(vec[i]<=half)
       {
           cout<<vec[i]<<" ";
           half-=vec[i];
       }
       if(half==0)break;
   }
   cout<<endl;



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


