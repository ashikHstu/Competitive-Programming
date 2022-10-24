#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<vector<pair<int, int>>> query(N);
    for (int i = 0; i < Q; ++i)
    {
        int u, k;
        cin >> u >> k;
        u -= 1;
        query[u].emplace_back(i, k);
    }
    auto get_farthest = [&](int src)
    {
        vector<int> dist(N, N);
        queue<int> que;
        auto push = [&](int u, int d)
        {
            if (dist[u] > d)
            {
                dist[u] = d;
                que.push(u);
            }
        };
        push(src, 0);
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (int v : graph[u])
            {
                push(v, dist[u] + 1);
            }
        }
        return max_element(dist.begin(), dist.end()) - dist.begin();
    };
    int L = get_farthest(0);
    int R = get_farthest(L);
    vector<int> ans(Q, -1);
    for (int root :
            {
                L, R
            })
    {
        vector<int> path;
        auto dfs = [&](auto&& dfs, int u, int p) -> void
        {
            for (const auto& [q, k] : query[u])
            {
                if (k <= (int)path.size())
                {
                    ans[q] = path[(int)path.size() - k] + 1;
                }
            }
            path.push_back(u);
            for (int v : graph[u])
            {
                if (v != p)
                {
                    dfs(dfs, v, u);
                }
            }
            path.pop_back();
        };
        dfs(dfs, root, -1);
    }
    for (int x : ans)
    {
        cout << x << '\n';
    }
    return 0;
}
