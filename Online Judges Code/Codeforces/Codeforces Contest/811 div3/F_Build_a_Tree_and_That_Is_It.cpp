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
   int n,a,b,c;
   cin>>n>>a>>b>>c;
 int cur=4;
 int connecting=1;
 vector<pair<int,int>>res;
 if(a>=b && a>=c)
 {
    if(a!=b+c)
    {
        cout<<"NO\n";
        return;
    }

    while(c>1)
    {
         res.pb({connecting,cur});
         connecting=cur;
         cur++;
         c--;
    }
    res.pb({connecting,3});
    connecting=3;
    while(b>1)
    {
        res.pb({connecting,cur});
        connecting=cur;
        cur++;
        b--;
    }
    res.pb({connecting,2});
   connecting=2;
   while(cur<n)
   {
    res.pb({connecting,cur});
        connecting=cur;
        cur++;
   }
 }
    
    //second

    if(b>=a && b>=c)
 {
    if(b!=a+c)
    {
        cout<<"NO\n";
        return;
    }

    connecting=2;

    while(a>1)
    {
         res.pb({connecting,cur});
         connecting=cur;
         cur++;
         a--;
    }
    res.pb({connecting,1});
    connecting=1;
    while(c>1)
    {
        res.pb({connecting,cur});
        connecting=cur;
        cur++;
        c--;
    }
    res.pb({connecting,3});
   connecting=3;
   while(cur<n)
   {
    res.pb({connecting,cur});
        connecting=cur;
        cur++;
   }
 }

 //Third

 if(c>=b && c>=a)
 {
    if(c!=b+a)
    {
        cout<<"NO\n";
        return;
    }
    connecting=1;

    while(a>1)
    {
         res.pb({connecting,cur});
         connecting=cur;
         cur++;
         a--;
    }
    res.pb({connecting,2});
    connecting=2;
    while(b>1)
    {
        res.pb({connecting,cur});
        connecting=cur;
        cur++;
        b--;
    }
    res.pb({connecting,3});
   connecting=3;
   while(cur<n)
   {
    res.pb({connecting,cur});
        connecting=cur;
        cur++;
   }
 }


    cout<<"YES\n";
for(pair<int,int>p:res)
{
    cout<<p.first<<" "<<p.second<<endl;
}

  

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


