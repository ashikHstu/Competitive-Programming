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
   vector<int>poses;
   int res[n+2];
   for(int i=1;i<=n;i++)
   {
    cin>>ar[i];
    if(ar[i]==i)poses.push_back(i);
    res[i]=i;
    

   }


   

    int ct=poses.size();
   if(n==1)
   {
       cout<<"-1\n";
       return;
   }

   for(int i=1;i<=n;i++)
   {
    if(res[i]==ar[i] && (i+1)<=n)
    {
       swap(res[i],res[i+1]);
    }
   }

   if(res[n]==ar[n])
   {
    int cct=n;
    while(cct--)
    {
        if(res[cct]!=ar[n] && res[n]!=ar[cct]){
            swap(res[cct],res[n]);
            break;
        }
    }
   }



  for(int i=1;i<=n;i++)cout<<res[i]<<" ";cout<<endl;
  return;

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


