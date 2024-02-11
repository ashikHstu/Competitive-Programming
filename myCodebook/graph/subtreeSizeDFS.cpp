// Not tested
#include <bits/stdc++.h>
using namespace std;
#define sz 1001
vector<int> g[sz];
int visited[sz];
int subTreeSize[sz];
void dfs(int src, int par)
{
    visited[src] = 1;
    subTreeSize[src] = 1;
    for (int v : g[src])
    {
        if (v != par)
        {
            dfs(v, src);
            subTreeSize[src] += subTreeSize[v];
        }
    }
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
    dfs(1, -1); // root node, dummy parent
    return 0;
}