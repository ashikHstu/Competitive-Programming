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
   int ar[n+2];
   for(int i=1;i<=n;i++)
   
   cin>>ar[i];
   int in[m+2],out[m+2];
   int degree[n+2]={0};

   for(int i=0;i<m;i++)
   {
    cin>>in[i]>>out[i];
    degree[in[i]]++;
    degree[out[i]]++;
   }

    if(m%2==0)
    {
        cout<<"0\n";
        return;
    }

    int res=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        if(degree[i]%2==1)
        {
            //cout<<"degree of "<<i<<" is : "<<degree[i]<<endl;
            res=min(res,ar[i]);
        }
    }

   for(int i=0;i<m;i++)
   {
    if(degree[in[i]]%2==0 && degree[out[i]]%2==0)
    {
        res=min(res,ar[in[i]]+ar[out[i]]);
    }
   }

   cout<<res<<endl;

   


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


