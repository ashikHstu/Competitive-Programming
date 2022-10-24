#include <bits/stdc++.h>

using namespace std;
#define int long long int
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
    int ar[n+2];

    for(int i=1;i<=n;i++)cin>>ar[i];
   
   vector<pair<int,int>>vec;
    vector<int>ache,bad;
   for(int i=1;i<=n;i++)
   {
    if(ar[i]<i)
    {
        vec.pb({ar[i],i});
        ache.pb(ar[i]);
   
    }
   }

     

   sort(all(ache));
   
   int res=0;
    
    for(int i=0;i<ache.size();i++)
    {
        int vv=vec[i].first;
        int ind=vec[i].second;
        int ex=ache.end()-upper_bound(ache.begin(),ache.end(),ind);
        res+=ex;
    }
   
cout<<res<<endl;


}

int32_t main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


