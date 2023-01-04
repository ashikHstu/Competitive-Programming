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

#define mod 998244353

ll dp[101][100001];
ll dp2[101][100001];

void solve()
{
   ll n;cin>>n;
   int ar[n+2];
   ll sum=0;
   for(int i=1;i<=n;i++)
   {
       cin>>ar[i];
       sum+=ar[i];
   }


   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=sum;j++)
       {
           if(i==0)
           {
               dp[i][j]=0;
           }
           if(j==0)
           {
               dp[i][j]=1;
           }
           if(i==0 || j==0)continue;
           dp[i][j]=dp[i-1][j]%mod;

           if(j-ar[i] >=0)dp[i][j]+=dp[i-1][j-ar[i]];
                  dp[i][j]=dp[i][j]%mod;

       }
   }


   ll res=0;

    for(int i=n+1;i>=1;i--)
   {
       for(int j=0;j<=sum;j++)
       {
           if(i==n+1)
           {
               dp2[i][j]=0;
           }
           if(j==0)
           {
               dp2[i][j]=1;
           }
           if(i==n+1 || j==0)continue;
           dp2[i][j]=dp2[i+1][j]%mod;

           if(j-ar[i] >=0)dp2[i][j]+=dp2[i+1][j-ar[i]];
            dp2[i][j]%=mod;


//           res+=((dp[i−1][j]*dp2[i+1][j−ar[i]])%mod);
           res=(res+((dp[i-1][j]*dp2[i+1][j-ar[i]])%mod)%mod);
            res%=mod;
       }
   }


  // cout<<"res : ";
   cout<<res<<endl;





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


