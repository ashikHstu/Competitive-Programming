void cal()
{
    ll n=2e5;
    ll a=1;
    inv[0]=1;
    fact[0]=1;
    for(ll i=1;i<=n;i++)
    {
        a=(a*i)%mod;
        fact[i]=a;
        inv[i]=pow1(a,mod-2);
    }
}
ll ncr(ll n,ll r)
{
    if(r==0||n==0)
    {
        return 1;
    }
    return ((fact[n]*inv[r])%mod*inv[n-r])%mod;
}

