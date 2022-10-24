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
   int n,m;cin>>n>>m;
   int ar[n+2];
   vector<int>vec,cnt;
   vector<int>vec2,cnt2;

   int cur=0;
   for(int i=0;i<n;i++)
   {
    cin>>ar[i];
    int dp=1;
    while(ar[i]%m==0)
    {
          dp*=m;
          ar[i]/=m;
    }

    if(cur==0)
    {
        vec.pb(ar[i]);
        cnt.push_back(dp);
        cur++;
    }
    else {
         if(vec[cur-1]==ar[i])
         {
            cnt[cur-1]+=dp;
         }
         else {
         vec.pb(ar[i]);
         cnt.push_back(dp);
         cur++;
    }
    }
    
   }


    int k;cin>>k;
    int ar2[k+2];
    cur=0;
   for(int i=0;i<k;i++)
   {
    cin>>ar2[i];
    int dp=1;
    while(ar2[i]%m==0)
    {
          dp*=m;
          ar2[i]/=m;
    }

    if(cur==0)
    {
        vec2.pb(ar2[i]);
        cnt2.push_back(dp);
        cur++;
    }
    else {
         if(vec2[cur-1]==ar2[i])
         {
            cnt2[cur-1]+=dp;
         }
         else {
         vec2.pb(ar2[i]);
        cnt2.push_back(dp);
        cur++;
    }
    }
    
   }


   if(vec.size()!=vec2.size())
   {
    cout<<"No\n";
    return;
   }


   int len=vec.size();
   for(int i=0;i<len;i++)
   {
        if(vec[i]!=vec2[i] || cnt[i]!=cnt2[i])
        {
            cout<<"No\n";
            return;
        }
   }

   cout<<"Yes\n";


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


