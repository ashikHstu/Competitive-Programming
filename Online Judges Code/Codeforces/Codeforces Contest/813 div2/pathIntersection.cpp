#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define SIZ 10004
int inf = 1000000000;
vector<int> ar[SIZ];
const int maxN = 25;
int level[SIZ], LCA[SIZ][maxN + 1];

void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par;
    for (int child : ar[node])
    {
        if (child != par)
            dfs(child, lvl + 1, node);
    }
}

void init(int n)
{
    dfs(1, 0, -1);
    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int par = LCA[j][i - 1];
            LCA[j][i] = LCA[par][i - 1];
        }
    }
}

int getLCA(int a, int b)
{
    if (level[b] < level[a])
        swap(a, b);
    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }

    if (a == b)
        return a;
    for (int i = maxN; i >= 0; i--)
    {
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}

int getDist(int a, int b)
{
    int lca = getLCA(a, b);
    return (level[a] + level[b] - (2 * level[lca]));
}

void solve(int kase)
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ar[u].pb(v), ar[v].pb(u);
    }
    init(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int f, s;
        int r = 2;
        int k;
        cin >> k;

        for (int j = 1; j <= k; j++)
        {
            int u, v;
            cin >> u >> v;
            if (j == 1)
            {
                f = u;
                s = v;
            }
            else if (r == -1)
                continue;
            else
            {
                set<int> s;
                s.insert((getLCA(f, u)));
                s.insert((getLCA(f, v)));
                s.insert((getLCA(s, u)));
                s.insert((getLCA(s, v)));
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }
}