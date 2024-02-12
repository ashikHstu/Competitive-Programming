// Not tested
#include <bits/stdc++.h>
using namespace std;
#define sz 1001
vector<int> g[sz];
int visited[sz];
vector<int> res;
void dfs(int src)
{
    visited[src] = 1;
    for (int v : g[src])
    {
        if (visited[v] == 0)
            dfs(v);
    }
}
int topoSort(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }
    reverse(res.begin(), res.end());
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    topoSort(n);
    return 0;
}