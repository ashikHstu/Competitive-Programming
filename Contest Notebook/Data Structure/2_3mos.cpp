struct query
{
    int l,r,i;
};
query Q[200001];
int arr[200001],ans[200001],freq[2000001],power;
bool cmp(query a,query b)
{
    if(a.l/block != b.l/block)
    {
        return a.l/block < b.l/block;
    }
    return a.r < b.r;
}
void add(int pos)
{
    int cnt = freq[arr[pos]];
    freq[arr[pos]]++;
    power -= (cnt * cnt * arr[pos]);
    cnt++;
    power += (cnt * cnt * arr[pos]);
}
void remove(int pos)
{
    int cnt = freq[arr[pos]];
    freq[arr[pos]]--;
    power -= (cnt * cnt * arr[pos]);
    cnt--;
    power += (cnt * cnt * arr[pos]);
}
void solve()
{
    int n,q,i;
    cin >> n >> q;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0; i<q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--;
        Q[i].r--;
    }
    sort(Q, Q+q, cmp);
    int cL = 0,cR = -1;
    for(i=0; i<q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;
        while(cL > L)
        {
            cL--;
            add(cL);
        }
        while(cR < R)
        {
            cR++;
            add(cR);
        }
        while(cL < L)
        {
            remove(cL);
            cL++;
        }
        while(cR > R)
        {
            remove(cR);
            cR--;
        }
        ans[Q[i].i] = power;
    }
    for(i=0; i<q; i++)
    {
        cout << ans[i] << endl;
    }
}

