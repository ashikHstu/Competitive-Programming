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

void solve(int kase)
{
   int a,b,c,d;
   int am,bm,cm,dm;
   for(int i=0;i<3;i++)
   {
       cin>>a>>b>>c>>d;
       if(i==0)
       {
           am=a;bm=b;cm=c;dm=d;
       }
       am=min(am,a);
       bm=min(bm,b);
       cm=min(cm,c);
       dm=min(dm,d);
   }

   cout<<"Case #"<<kase<<": ";

   int sum=am+bm+cm+dm;
   if(sum<1000000)
   {
       cout<<"IMPOSSIBLE\n";
       return;
   }
   int lagbe=1000000;
   int nicchi=min(lagbe,am);
   cout<<nicchi<<" ";
   lagbe-=nicchi;

   nicchi=min(lagbe,bm);
   cout<<nicchi<<" ";
   lagbe-=nicchi;

   nicchi=min(lagbe,cm);
   cout<<nicchi<<" ";
   lagbe-=nicchi;

   nicchi=min(lagbe,dm);
   cout<<nicchi<<endl;


   return;


}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve(i);
    }

    return 0;
}


