void cal()
{
    ll a=1,b=1;
    p1[0]=1;
    inv1[0]=1;
    p2[0]=1;
    inv2[0]=1;
    for(ll i=1; i<=5000; i++)
    {
        a=(a*31)%mod;
        p1[i]=a;
        inv1[i]=pow1(a,mod-2);
        b=(b*137)%mod1;
        p2[i]=b;
        inv2[i]=pow2(b,mod1-2);
    }
}
void string_hash(string &s)
{
    ll sum=0,sum1=0;
    for(ll i=0; i<s.size(); i++)
    {
        ll a=p1[i]*(s[i]-96);
        sum=(sum+a)%mod;
        ar[i]=sum;
        a=p2[i]*(s[i]-96);
        sum1=(sum1+a)%mod1;
        br[i]=sum1;
    }
}
pair<ll,ll> hash_query(ll i,ll j)
{
    ll a=ar[j];
    if(i>0)
        a=(a+mod)-ar[i-1];
    a=(a*inv1[i])%mod;
    ll b=br[j];
    if(i>0)
        b=((b+mod1)-br[i-1]);
    b=(b*inv2[i])%mod1;
    return {a,b};
}


//For random number hashing:

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	for(i=1;i<=n;i++){
		hs[i]=rand()%mod;
