#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    int n;cin>>n;
    ll a[n+2];
    ll ar[n+2];
    ar[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        a[i]=ar[i];
        ar[i]=(ar[i]+ar[i-1]);
    }

    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res=res+(((ar[n]-ar[i])%mod)*a[i])%mod;
        res%=mod;
    }

    cout<<res<<endl;
    return 0;


}
