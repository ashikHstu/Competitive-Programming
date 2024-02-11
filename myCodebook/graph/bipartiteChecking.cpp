#include <bits/stdc++.h>
using namespace std;
#define N 2004
vector<int> g[N];
int vis[N];
int col[N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        g[i].clear();
        vis[i] = 0;
    }
}
bool dfs(int source, int c)
{
    vis[source] = 1;
    col[source] = c;
    for (int child : g[source])
    {
        if (vis[child] == 0)
        {
            if (dfs(child, c ^ 1) == false)
                return false;
        }
        else if (col[source] == col[child])
            return false;
    }
    return true;
}

void solve()
{
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool yes = true;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            yes = yes && dfs(i, 0);
        }
    }
    if (yes)
        cout << "Bipartite!\n";
    else
        cout << "Not Bipartite!\n";
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Scenario #" << i << ":\n";
        solve();
    }
    return 0;
}