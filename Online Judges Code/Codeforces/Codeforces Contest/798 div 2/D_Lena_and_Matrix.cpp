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
   string st[n+2];

   for(int i=0;i<n;i++)
   {
    cin>>st[i];
     
   }


   pair<int,int>p1={-1,-1},p2={-1,-1},p3={-1,-1},p4={-1,-1},resp={-1,-1};
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        if(st[i][j]=='B')
        {
            if(p1.first==-1 || i+j>p1.first+p1.second)p1={i,j};
            if(p2.first==-1 || i+j<p2.second+p2.first)p2={i,j};
            if(p3.first==-1 || i-j>p3.first-p3.second)p3={i,j};
            if(p4.first==-1 || i-j<p4.first-p4.second)p4={i,j};
        }
    }
   }
vector<pair<int,int>>border;
border.pb(p1);
border.pb(p2);
border.pb(p3);
border.pb(p4);
   int res=1e9;

   for(int i=0;i<n;i++)
   {

    for(int j=0;j<m;j++)
    {
        int d=0;
        for(auto pp:border)
        {
            d=max(d,(abs(i-pp.first)+abs(j-pp.second)));
        }
       if(d<res)
       {
        res=d;
        resp={i,j};
       }

    }
   }

   cout<<resp.first+1<<" "<<resp.second+1<<endl;
   
    


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


