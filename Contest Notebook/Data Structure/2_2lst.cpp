int arr[200005],st[800005],lazy[800005];
void buildtree(int si,int ss,int se)
{
    if(ss == se)
    {
        st[si] = arr[ss];
        return ;
    }
    int mid = (ss + se) / 2;
    buildtree(2*si, ss, mid);
    buildtree(2*si+1, mid+1, se);
    st[si] = st[2*si] + st[2*si+1];
}
int query(int si,int ss,int se,int qs,int qe)
{
    if(lazy[si] != 0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);
        if(ss != se)
        {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }
    if(ss > qe || se < qs)
    {
        return 0;
    }
    if(ss >= qs && se <= qe)
    {
        return st[si];
    }
    int mid = (ss + se) / 2;
    return query(2*si, ss, mid, qs, qe) + query(2*si+1, mid+1, se, qs, qe);
}
void update(int si,int ss,int se,int qs,int qe,int val)
{
    if(lazy[si] != 0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);
        if(ss != se)
        {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }
    if(ss > qe || se < qs)
    {
        return;
    }
    if(ss >= qs && se <= qe)
    {
        int dx = (se - ss + 1) * val;
        st[si] += dx;
        if(ss != se)
        {
            lazy[2*si] += val;
            lazy[2*si+1] += val;
        }
        return ;
    }
    int mid = (ss + se) / 2;
    update(2*si, ss, mid, qs, qe, val);
    update(2*si+1, mid+1, se, qs, qe, val);
    st[si] = st[2*si] + st[2*si+1];
}
void solve()
{
    int n,q,i,t,l,r,x;
    cin >> n >> q;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    buildtree(1, 1, n);
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}

