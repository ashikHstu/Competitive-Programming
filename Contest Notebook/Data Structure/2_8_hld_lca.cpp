int sub[200005],dp[22][200005],dist1[200005],leader[200005],position[200005],ar[200005],val[200005];
int pos=1;
vector<int>v[200005];
int seg[1000006];
//segtree
void build(int ind,int low,int high)
{
    if(low==high)
    {
        seg[ind]=ar[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=max(seg[ind*2+1],seg[ind*2+2]);
}
ll query(ll ind,ll low,ll high,ll l,ll r)
{
    if(low>=l&&high<=r)
    {
        return seg[ind];
    }
    if(high<l||low>r)
    {
        return INT_MIN;
    }
    ll mid=(low+high)/2;
    ll left=query(ind*2+1,low,mid,l,r);
    ll right=query(ind*2+2,mid+1,high,l,r);
    return max(left,right);
}
void update(ll ind,ll low,ll high,ll node,ll val)
{
    if(low==high)
    {
        seg[ind]=val;
    }
    else
    {
        ll mid=(low+high)/2;
        if(low<=node&&mid>=node)
        {
            update(ind*2+1,low,mid,node,val);
        }
        else
            update(ind*2+2,mid+1,high,node,val);
        seg[ind]=max(seg[ind*2+1],seg[ind*2+2]);
    }
}
//lca
ll lca(ll a,ll b)
{
    int c=min(dist1[a],dist1[b]);
    int d=dist1[a]-c;
    int i;
    for(i=20; i>=0; i--)
    {
        if((d&(1<<i)))
        {
            d=d-(1<<i);
            a=dp[i][a];
        }
    }
    d=dist1[b]-c;
    for(i=20; i>=0; i--)
    {
        if((d&(1<<i)))
        {
            d=d-(1<<i);
            b=dp[i][b];
        }
    }
    if(a==b)
    {
        return a;
    }
    d=dist1[a];
    for(i=20; i>=0; i--)
    {
        if((d>(1<<i))&&dp[i][a]!=dp[i][b])
        {
            a=dp[i][a];
            b=dp[i][b];
            d=d-(1<<i);
        }
    }
    a=dp[0][a];
    return a;
}
//hld
ll n;
ll hldquery(ll a,ll b)
{
    ll lc=lca(a,b);
    ll ans=0;
    while(leader[a]!=leader[lc])
    {
        ll r=position[a];
        ll l=position[leader[a]];
        ans=max(ans,query(1,1,n,l,r));
        a=dp[0][leader[a]];
    }
    ll r=position[a];
    ll l=position[lc];
    ans=max(ans,query(1,1,n,l,r));
    a=b;
    while(leader[a]!=leader[lc])
    {
        r=position[a];
        l=position[leader[a]];
        ans=max(ans,query(1,1,n,l,r));
        a=dp[0][leader[a]];
    }
    r=position[a];
    l=position[lc];
    ans=max(ans,query(1,1,n,l,r));
    return ans;
}
void hld(ll a,ll p,ll head)
{
    leader[a]=head;
    ar[pos]=val[a];
    position[a]=pos++;
    vector<pair<ll,ll> >v1;
    for(auto b:v[a])
    {
        if(b!=p)
        {
            v1.push_back({sub[b],b});
        }
    }
    if(v1.empty())
    {
        return;
    }
    sort(v1.rbegin(),v1.rend());
    ll heavy=v1[0].second;
    hld(heavy,a,head);
    for(auto b:v[a])
    {
        if(b!=p)
        {
            if(b!=heavy)
            {
                hld(b,a,b);
            }
        }
    }
}
//counting subtree size
void dfs(ll a,ll p)
{
    sub[a]=1;
    dp[0][a]=p;
    for(auto b:v[a])
    {
        if(b!=p)
        {
            dist1[b]=dist1[a]+1;
            dfs(b,a);
            sub[a]+=sub[b];
        }
    }
}
void solve()
{
    ll i,a,b,j,q;
    cin>>n>>q;
    for(i=1; i<=n; i++)
    {
        cin>>val[i];
    }
    for(i=0; i<n-1; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    for(i=1; (1<<i)<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    pos=1;
    hld(1,-1,1);
    build(1,1,n);
    while(q--)
    {
        ll t;
        cin>>t>>a>>b;
        if(t==1)
        {
            update(1,1,n,position[a],b);
        }
        else
        {
            cout<<hldquery(a,b)<<" ";
        }
    }
    cout<<endl;
}

