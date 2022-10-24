#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int kase)
{
    ll a,b;cin>>a>>b;
    ll g=__gcd(a,b);
    ll m=min(a,b);
    ll res=g*m;
    printf("Case #%d: %lld\n",kase,res);
}


int main()
{
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        solve(i);
    }

    return 0;
}
