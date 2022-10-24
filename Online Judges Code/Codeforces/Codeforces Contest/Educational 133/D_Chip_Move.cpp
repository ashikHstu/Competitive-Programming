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
#define MOD  998244353
 int n,k;
 
 

void solve()
{
   cin>>n>>k;
   int res[n+2]={0};
       int temp[n+2]={0};
       res[0]=temp[0]=1;

   for(int i=k,cur=k;cur<=n;i++)
   {
    int temp2[n+2]={0};

    for(int j=cur;j<=n;j++)
    {
        temp2[j]+=(temp2[j-i]+temp[j-i])%MOD;
         res[j]+=temp2[j];
         res[j]%=MOD;
    }
    for(int j=cur;j<=n;j++)temp[j]=temp2[j];
    cur+=(i+1);

   }


   for(int i=1;i<=n;i++)cout<<res[i]<<" ";cout<<endl;



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


