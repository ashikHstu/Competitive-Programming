#include <bits/stdc++.h>
using namespace std;
#define sz 100005
vector<int> g[sz];
bool vis[sz], onStack[sz];
int in[sz], low[sz];
stack<int> st;
int timer = 1, SCC = 0;
void dfs(int node)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    onStack[node] = true;
    st.push(node);
    for (int u : g[node])
    {
        if ((vis[u] == true) && (onStack[u] == true))
        {
            low[node] = min(low[node], in[u]);
        }
        else if (vis[u] == false)
        {
            dfs(u);
            if (onStack[u] == true)
                low[node] = min(low[node], low[u]);
        }
    }
    if (in[node] == low[node])
    {
        SCC++;
        cout << "SCC #" << SCC << endl;
        int u;
        while (1)
        {
            u = st.top();
            st.pop(), onStack[u] = false;
            cout << u << " ";
            if (u == node)
                break;
        }
        cout << endl;
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a >> b, g[a].push_back(b);
    for (int i = 1; i <= n; i++)
        vis[i] = onStack[i] = false;
    for (int i = 1; i <= n; i++)
        if (vis[i] == false)
            dfs(i);
}
