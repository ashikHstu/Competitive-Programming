
vector<ll>v[N];
ll capacity[N][N];
ll bfs(ll s,ll t,vector<ll>&par)
{
    fill(par.begin(),par.end(),-1);
    par[s]=-2;
    queue<pair<ll,ll> >q;
    q.push({s,1e18});
    while(!q.empty())
    {
        ll cur=q.front().first;
        ll flow=q.front().second;
        q.pop();
        for(auto next:v[cur])
        {
            if(par[next]==-1&&capacity[cur][next]>0)
            {
                par[next]=cur;
                ll new_flow=min(flow,capacity[cur][next]);
                if(next==t)
                {
                    return new_flow;
                }
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}
ll n;
ll maxflow(ll s,ll t)
{
    ll flow=0;
    vector<ll>par(n+2);
    ll new_flow;
    while(new_flow=bfs(s,t,par))
    {
        flow+=new_flow;
        ll cur=t;
        while(cur!=s)
        {
            ll prev=par[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}
void solve()
{
    ll i,m,a,b,s,t,c;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
        capacity[a][b]+=c;
    }
    s=1,t=n;
    cout<<maxflow(s,t);
}

