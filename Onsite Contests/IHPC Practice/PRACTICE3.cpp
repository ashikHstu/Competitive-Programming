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
   int ar[n+2];
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
   }

   cout<<"break point 0 : "<<endl;

   int cnt[101+2]={0};
   for(int i=0;i<n;i++)cnt[ar[i]]++;

   int b[101+2]={0};

   cout<<"break point 0.5"<<endl;

   for(int i=1;i<101;i++)
   {
       b[i]=cnt[i];
       for(int j=i+i;j<=101;j+=i)
       {
           b[i]+=cnt[j];
       }
   }

   cout<<"break point 1"<<endl;

   int a[101]={0};

   for(int i=1;i<=101;i++)
   {
       a[i]=(b[i]*(b[i]-1))/2.0;
   }

   cout<<"break point 2 "<<endl;

   int main_gcd[101];
   for(int i=100;i>=1;i--)
   {
       main_gcd[i]=a[i];
       for(int j=i+i;j<=100;j+=i)
       {
           main_gcd[i]-=main_gcd[j];
       }
   }

   cout<<"break point 3"<<endl;

   ll res=1;
   for(int i=1;i<=16;i++)
   {
       cout<<"main_gcd["<<i<<"] = "<<main_gcd[i]<<endl;
       while(main_gcd[i]>0){res*=i;
       main_gcd[i]--;
       }
   }

   cout<<"res : "<<res<<endl;

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


