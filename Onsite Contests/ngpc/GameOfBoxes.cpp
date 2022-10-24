#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void solve(int kase)
{
    ll n;cin>>n;
    ll suma,sumb,sumc;
    suma=sumb=sumc=0;
    ll maxa=0,maxb=0,maxc=0;
    for(int i=0;i<n;i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        suma+=a;sumb+=b;sumc+=c;
        maxa=max(maxa,a);maxb=max(maxb,b);maxc=max(maxc,c);
    }

    ll res=suma*maxb*maxc;
    res=min(res,(sumb*maxa*maxc));
    res=min(res,(maxa*maxb*sumc));

    cout<<res<<endl;
}


int main()
{

    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve(i);
    }

    return 0;
}
