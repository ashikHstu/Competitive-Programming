#include <bits/stdc++.h>
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
using namespace std;
vector<int> v[10000];
int visit[10000], color[10000];
bool dfs(int node, int c)
{
    visit[node] = 1;
    color[node] = c;

    for (auto child : v[node])
    {
        if (visit[child] == 0)
        {
            if (dfs(child, c ^ 1) == 0)
                return false;
        }
        else
        {
            if (color[node] == color[child])
                return false;
        }
    }
    return true;
}
int main()
{
    sync;
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    bool ans = dfs(1, 1);
    // cout<< ans << endl;
    if (ans == true)
        cout << "Graph is Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;
}
