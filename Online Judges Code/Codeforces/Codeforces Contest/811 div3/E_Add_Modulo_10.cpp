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

int findState(int ld,int sld)
{
    if(ld==3 || ld==6 || ld==7 || ld==9)
    {
       if(sld%2==0)return 0;
       else return 1;
    }
    else {
           if(sld%2==0)return 1;
           return 0;
    }
}

void solve()
{
    int n;
    cin>>n;
    bool fz=false;
    vector<int>ar;
    for(int i=0;i<n;i++)
    {
        int v;cin>>v;ar.pb(v);
        if(v%10==0 || v%10==5)
        fz=true; 
    }

    if(fz)
    {
        if(ar[0]%10==5)ar[0]+=5;
        for(int i=1;i<n;i++)
        {
            if(ar[i]%10==5)ar[i]+=5;
            if(ar[i]!=ar[i-1])
            {
                cout<<"No\n";
                return;
            }

        }
        cout<<"Yes\n";
        return;
    }

   sort(all(ar));
   int tfs;
   for(int i=n-1;i>=0;i--)
   {
        int ld=ar[i]%10;
        int sld=ar[i]%100;
        sld/=10;
        if(i==n-1)
        { 
            tfs=findState(ld,sld);
            
        }
        else {
            int cs=findState(ld,sld);
            if(tfs!=cs)
            {
               cout<<"No\n";
               return;
            }
        }
   }

   cout<<"Yes\n";


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


