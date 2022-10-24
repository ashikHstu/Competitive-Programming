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
   int n;

   cin>>n;
   queue<pair<int,int>>q;
   q.push({n,0});
   int m=32768;
   int ct[32769]={0};

   while(!q.empty())
   {
       pair<int,int>p=q.front();
       q.pop();
       if(p.first==0)
       {
           cout<<p.second<<" ";
           return;
       }
       ct[p.first]=1;
       int v1=(p.first+1)%m;
       int v2=(p.first*2)%m;
       if(ct[v1]==0)
       q.push({(p.first+1)%m,p.second+1});
       if(ct[v2]==0)
       q.push({(p.first*2)%m,p.second+1});



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


