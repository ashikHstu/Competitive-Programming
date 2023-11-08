int sub[200005],parent[200005];
set<int>adj[200005];
int dfs1(int a,int par)//finding subtree size
{
    sub[a]=1;
    for(int b:adj[a])
    {
        if(b!=par)
        {
            sub[a]+=dfs1(b,a);
        }
    }
    return sub[a];
}
int dfs(int a,int par,int n)//finding centroid
{
    for(int b:adj[a])
    {
        if(b!=par&&sub[b]>n/2)
        {
            return dfs(b,a,n);
        }
    }
    return a;
}
void decompose(int a,int par)
{
    int subtreesize=dfs1(a,-1);
    int centroid=dfs(a,par,subtreesize);
    parent[centroid]=par;
    for(int b:adj[centroid])
    {
        adj[b].erase(centroid);
        decompose(b,centroid);
    }
}

