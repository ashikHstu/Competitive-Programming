int arr[200005];
int sparse[200005][32];
void sparseTable(int n)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        sparse[i][0] = arr[i];
    }
    for(j=1; (1<<j)<=n; j++)
    {
        for(i=1; i+(1<<j)-1<=n; i++)
        {
            sparse[i][j] = min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r)
{
    int sz = r - l + 1;
    int k = (int)log2(sz);
    return min(sparse[l][k], sparse[l+sz-(1<<k)][k]);
}

