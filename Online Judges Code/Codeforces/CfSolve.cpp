#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
long long bigMod(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n,m;cin>>n>>m;
    ll x=0;
    for(int i=0;i<m;i++)
    {
        ll l,r,v;cin>>l>>r>>v;
        x=x|v;
    }

    ll res=((x%mod)*(bigMod(2,n-1,mod)%mod))%mod;

   // cout<<"res : ";
    cout<<res<<endl;
}


int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
    return 0;
}
