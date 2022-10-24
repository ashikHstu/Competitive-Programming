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

int findGCD(int a,int b)
{
    a=abs(a);
    b=abs(b);
    return __gcd(a,b);
}

pair<int,int> findR(int a,int b)
{
    int d=findGCD(a,b);
    a/=d;
    b/=d;

    if(a<0 && b<0)
    {
        return {b,-a};
    }
    else if(a>0 && b>0)
    {
        return {-b,a};
    }
    a=abs(a);
    b=abs(b);
    return {b,a};
}

void solve()
{
   int n;
   cin>>n;

   int ar[n+2],br[n+2];
   for(int i=0;i<n;i++)
   {
    cin>>ar[i];
   }
   int bres=0;
   int any=0;
   for(int i=0;i<n;i++)
   {
    cin>>br[i];
    if(br[i]==0 && ar[i]==0)any++;
    else if(br[i]==0)bres++;
   }
   
    map<pair<int,int>,int>mp;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(ar[i]==0 || br[i]==0)continue;

        pair<int,int>p=findR(ar[i],br[i]);
        mp[p]++;
        if(mp[p]>res)res=mp[p];
    }

    res=max(res,bres);
    cout<<res+any<<endl;
    




}

int main()
{
    int tc=1;
   // cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


