#include <bits/stdc++.h>
using namespace std;
vector<int> g[2004];
int vis[2004];
int col[2004];
void init()
{
    for (int i = 0; i < 2002; i++)
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
        cout << "No suspicious bugs found!\n";
    else
        cout << "Suspicious bugs found!\n";
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