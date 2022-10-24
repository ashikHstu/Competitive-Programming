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
    ll n,m,k;
    cin>>n>>m>>k;
   ll ar[k+2];
   ll dn=0,dm=0;
   bool n_odd=false,m_odd=false,m_boro=false,n_boro=false;

    for(int i=0;i<k;i++)
    {
        cin>>ar[i];
        ll d=(ar[i]/n);
        if(d>=2)
        {
            dn+=d;
        }
        if(d>=3)
        {
            if(d%2==1)
            n_odd=true;
            n_boro=true;
        
        }
        d=(ar[i]/m);

         if(d>=2)
        {
            dm+=d;
        }
        if(d>=3)
        {
            if(d%2==1)
            m_odd=true;
            m_boro=true;
        }
    }
    
    if(dn>=m)
    {
        if(m%2==1)
        {
            if(n_odd)
            {
                cout<<"Yes\n";
                return;
            }
            else if(n_boro && dn>m)
            {
                cout<<"Yes\n";
                return;
            }
           // cout<<"No\n";
        }
        else {
            cout<<"Yes\n";
            return;
        }
       
    }
    if(dm>=n)
    {
        if(n%2==1)
        {
            if(m_odd)
            {
                cout<<"Yes\n";
                return;
            }
            else if(m_boro && dm>n)
            {
                cout<<"Yes\n";
                return;
            }
           // cout<<"No\n";
        }
        else {
            cout<<"Yes\n";
        return;
        }
    }
     cout<<"No\n";

  

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


