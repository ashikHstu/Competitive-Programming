#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz 10002
vector<int> g[sz];
vector<int> res;
int in[sz];
bool kahansAlgo(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int t = pq.top();
        res.pb(t);
        pq.pop();
        for (int child : g[t])
        {
            in[child]--;
            if (in[child] == 0)
                pq.push(child);
        }
    }
    return res.size() == n;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
        cin >> a >> b, g[a].pb(b), in[b]++;
    if (kahansAlgo(n))
    {
        for (int v : res)
            cout << v << " ";
        cout << endl;
    }
    else
    {
        cout << "topo sort failed.\n";
    }
    return 0;
}
