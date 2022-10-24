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
   int n;cin>>n;
   int ar[n+2][n+2];
   string st;
   int total_one=0;
   for(int i=0;i<n;i++)
   {
       cin>>st;
       for(int j=0;j<n;j++)
       {
           ar[i][j]=st[j]-'0';
           if(ar[i][j]==1)
           {
               total_one++;
           }
       }
   }

   int res=n+total_one;

   for(int i=0;i<=n;i++)
   {
       ll tr=0;
       for(int j=0;j<n;j++)
       {
           if(ar[(i+j)%n][j]==1)
           {
               tr++;
           }
       }

       int ex=n-tr;
       int hudai=total_one-tr;
       int temp=ex+hudai;
       res=min(temp,res);

   }

   //cout<<"res : ";

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


