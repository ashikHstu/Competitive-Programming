#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz 1000006
vector<int> ar[sz], tr[sz], order, SCC;
int vis[sz];
void dfs(int node)
{
    vis[node] = 1;
    for (int child : ar[node])
        if (vis[child] == 0)
            dfs(child);
    order.pb(node);
}
void dfs1(int node)
{
    vis[node] = 1;
    for (int child : tr[node])
        if (vis[child] == 0)
            dfs1(child);
    SCC.pb(node);
}
int main()
{
    int n, a, b, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            ar[i].clear(),
                tr[i].clear(), vis[i] = 0;
        order.clear();
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            ar[a].pb(b);
            tr[b].pb(a);
        }
        for (int i = 1; i <= n; i++)
            if (vis[i] == 0)
                dfs(i);
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        for (int i = 1; i <= n; i++)
            if (vis[order[n - i]] == 0)
            {
                SCC.clear();
                dfs1(order[n - i]);
                cout << "dfs1() called from " << order[n - i] << " and printing SCC" << endl;
                for (int node : SCC)
                    cout << node << " ";
                cout << endl;
            }
    }
}
