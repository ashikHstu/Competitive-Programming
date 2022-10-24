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
   int  n;cin>>n;
   int ar[n+2];
   int cur=0;
   vector<pair<int,int>>vec;
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
       if(i==0)continue;
       if(ar[i]==ar[i-1])
       {
           cur++;
       }
       else {
           if(cur>=1)
           {
               vec.push_back({cur+1,i-1});
           }
           cur=0;
       }

   }

   if(cur>=1)
   vec.push_back({cur+1,n-1});

   int len=vec.size();
   if(len==0)
   {
      cout<<"0"<<endl;
      return;
   }
   if(len==1)
   {
       int r=vec[0].first-2;
       if(r==0)
       {
           cout<<"0\n";
           return;
       }
       if(r==1)
       {
           cout<<"1\n";
           return;
       }
       cout<<r-1<<endl;
       return;
   }

   int firstL=vec[0].second-vec[0].first +1;
   int last=vec[len-1].second;
   int dis=last-firstL-2;
   //cout<<"dis : "<<dis<<endl;
   dis=max(dis,0);
   cout<<dis<<endl;




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


