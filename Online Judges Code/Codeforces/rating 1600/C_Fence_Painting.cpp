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
   int ar[n+2],br[n+2],cr[m+2];
   for(int i=0;i<n;i++)cin>>ar[i];
   for(int i=0;i<n;i++)cin>>br[i];
  
   vector<int>lagbe[n+2],hudai[n+2];
   map<int,int>need,extra;
    int lagbei=0;
   for(int i=0;i<m;i++)
   {
    cin>>cr[i];
   }

 
   vector<int>res;
   int exi=-1;
  for(int i=0;i<n;i++)
  {
    if(ar[i]==br[i])
    {
        //extra[ar[i]]++;
        hudai[ar[i]].pb(i);
    }
    else {
        //need[br[i]]++;
        lagbei++;
        lagbe[br[i]].pb(i);
    }
  }
    int ind=-1;
    vector<int>rr;
   for(int i=m-1;i>=0;i--)
   {
       if(lagbe[cr[i]].size()==0 && hudai[cr[i]].size()==0 && ind==-1)
       {
        cout<<"NO\n";
        return;
       }
       if(lagbe[cr[i]].size()!=0)
       {
        ll v=lagbe[cr[i]].back();
        lagbe[cr[i]].pop_back();
        lagbei--;
        res.pb(v);
        if(ind==-1)ind=v;
       }
       else if(hudai[cr[i]].size()!=0)
       {
        ll v=hudai[cr[i]].back();
       // hudai[cr[i]].pop_back();
        res.pb(v);
        if(ind==-1)ind=v;
       }
       else if(ind!=-1)
       {
        res.pb(ind);
       }
       
    

   }
  if(lagbei>0)
  {
    cout<<"NO\n";
    return;
  }
   cout<<"YES\n";
   reverse(all(res));
   for(int vv:res)cout<<vv+1<<" ";cout<<endl;


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


