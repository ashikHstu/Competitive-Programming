#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mx 200005
int n;
int status[mx];
int res[mx];
int sum[mx];
vector<int> g[mx];
int visited[mx];
int dfs(int src)
{
    visited[src] = 1;
    sum[src] = (status[src] == 0) ? -1 : 1;
    for (int child : g[src])
    {
        if (!visited[child])
        {
            sum[src] += max(0, dfs(child));
        }
    }
    return sum[src];
}

void dfs2(int src)
{
    visited[src] = 1;

    res[src] = sum[src];
    for (int child : g[src])
    {
        if (!visited[child])
        {
            sum[src] -= max(0, sum[child]);
            sum[child] += (max(0, sum[src]));
            dfs2(child);
            sum[child] -= max(0, sum[src]);
            sum[src] += max(0, sum[child]);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> status[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);

    memset(visited, 0, sizeof(visited));
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}
