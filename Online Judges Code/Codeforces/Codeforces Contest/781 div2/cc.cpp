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

ll findRes(ll oneNeed,ll twoNeed)
{
    if(oneNeed==twoNeed+1 || oneNeed==twoNeed)
   {
       return (oneNeed+twoNeed);

   }
   ll res=0;
   if(oneNeed>twoNeed)
   {
       ll ext=oneNeed-twoNeed;
       res=2*twoNeed;
       res+=(2*ext-1);

       return res;

   }

   ll ext=twoNeed-oneNeed;
   ext*=2;
   res=oneNeed*2;
   ll d=ext/6;
   res+=(d*4);
   ll m=ext%6;
   if(m==5)res+=4;
   if(m==4)
    res+=3;
   else if(m>=2)res+=2;
   else if(m==1)res+=1;

   return res;
}


void solve()
{
   int n;
   cin>>n;
   ll ar[n+2];
   ll mx;
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
       if(i==0)
        mx=ar[i];
       else mx=max(mx,ar[i]);
   }
   ll oneNeed=0,twoNeed=0;
   for(int i=0;i<n;i++)
   {
       int d=mx-ar[i];
       twoNeed+=(d/2);
       oneNeed+=(d%2);
   }

   ll res1=findRes(oneNeed,twoNeed);

    oneNeed=0;
    twoNeed=0;
    mx++;
   for(int i=0;i<n;i++)
   {
       int d=mx-ar[i];
       twoNeed+=(d/2);
       oneNeed+=(d%2);
   }

   ll res2=findRes(oneNeed,twoNeed);

//cout<<"res : ";
   //cout<<"one need : "<<oneNeed<<endl;
   //cout<<"Two need : "<<twoNeed<<endl;
ll res=min(res1,res2);

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


