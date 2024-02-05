#include <bits/stdc++.h>
using namespace std;

vector<int> g[101];
int visited[101];
int in[101], out[101];
int timer;
void dfs(int src)
{
    visited[src] = 1;
    timer++;
    in[src] = timer;
    for (int v : g[src])
    {
        if (visited[v] == 0)
            dfs(v);
    }
    timer++;
    out[src] = timer;
    visited[src] = 2;
}

int main()
{
    int n, e;
    cin >> n >> e;
    timer = 0;
    /** for(int i=0;i<=n;i++){
        visited[i]=0;
        g[i].clear();
     }
     */
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int connected_component = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (visited[i] == 0)
        {
            connected_component++;
            dfs(i);
        }
    }
    cout << "number of connected component : " << connected_component << endl;
    cout << "In time  : ";
    for (int i = 1; i <= n; i++)
        cout << in[i] << "  ";
    cout << endl;
    cout << "Out Time : ";
    for (int i = 1; i <= n; i++)
        cout << out[i] << " ";
    cout << endl;
    return 0;
}