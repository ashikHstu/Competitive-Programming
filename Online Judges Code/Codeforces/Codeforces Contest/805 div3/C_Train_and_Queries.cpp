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
    int n,k;cin>>n>>k;
    int ar[n+2];
    map<int,int>mp,mpl;
    
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(mpl[ar[i]]==0)
        mpl[ar[i]]=i+1;
       mp[ar[i]]=i+1;
    }
     for(int i=0;i<k;i++)
     {
         int l,r;cin>>l>>r;
         if(mp[l]==0 || mp[r]==0)
         {
            cout<<"NO\n";
         }
         else {
            if(mp[r]>=mpl[l])
            cout<<"YES\n";
            else cout<<"NO\n";
         }
     }

    


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


