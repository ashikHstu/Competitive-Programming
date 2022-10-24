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
#define MOD 998244353

ll ncr[1011][1011];

void calNCR()
{
   for(int i=0;i<=1009;i++)
   {
       ncr[i][0]=ncr[i][i]=1;
       for(int j=1;j<i;j++)
       {
        ncr[i][j]=((ncr[i-1][j]+ncr[i-1][j-1])%MOD);
        ncr[i][j]%=MOD;
       }
   }
}

void solve()
{

    calNCR();
    int n;

    cin>>n;
    ll ar[n+2];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

     ll res[n+2]={0};
     res[n]=1;
     for(int i=n-1;i>=0;i--)
     {
        if(ar[i]<=0){
            res[i]=0;
            continue;
        }

        for(int j=i+ar[i]+1;j<=n;j++)
        {
            res[i]+=((res[j]*ncr[j-i-1][ar[i]])%MOD);
            res[i]%=MOD;
        }

     }


     ll mainRes=0;
     for(int i=0;i<n;i++)
     {
        mainRes+=res[i];
        mainRes%=MOD;
     }

     cout<<mainRes<<endl;


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


