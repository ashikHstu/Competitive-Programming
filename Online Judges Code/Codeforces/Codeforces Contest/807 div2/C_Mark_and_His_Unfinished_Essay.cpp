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
    ll n,c,q;
    cin>>n>>c>>q;
    string st;
    cin>>st;
    ll cur=n;
    vector<pair<ll,ll>>vec;
    for(int i=0;i<c;i++)
    {
       ll l,r;
        cin>>l>>r;
        ll li=cur+1;
        cur=cur+(r-l+1);
        vec.pb({l,li});
    }
    for(int i=0;i<q;i++)
    {
        ll qi;
        cin>>qi;
        for(int j=c-1;j>=0;j--)
        {
            if(qi>=vec[j].second)
            {
                qi=(vec[j].first+(qi-vec[j].second));
            }
        }
        cout<<st[qi-1]<<endl;
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


