/// Not Yet Tested
#include <bits/stdc++.h>
using namespace std;
#define N 2004
vector<int> g[N];
int vis[N];

bool dfs(int source, int par)
{
    vis[source] = 1;

    for (int child : g[source])
    {
        if (vis[child] == 0)
        {
            if (dfs(child, source) == true)
                return true;
        }
        else if (child != par)
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool yes = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            yes = yes || dfs(i, 0);
        }
    }
    if (yes)
        cout << "Has Cycle!\n";
    else
        cout << "No cycle!\n";
}