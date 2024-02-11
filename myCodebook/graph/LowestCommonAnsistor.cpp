#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define N 10001
vector<int> ar[N];
const int maxN = 10; // log2(n)
int level[N], LCA[N][maxN + 1];
void dfs(int node, int lvl, int par)
{
	level[node] = lvl;
	LCA[node][0] = par;
	for (int child : ar[node])
		if (child != par)
		{
			dfs(child, lvl + 1, node);
		}
}
void init(int n)
{
	dfs(1, 0, -1);
	for (int i = 1; i <= maxN; i++)
	{
		for (int j = 1; j <= n; j++)
			if (LCA[j][i - 1] != -1)
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
		d -= 1 << i;
	}
	if (a == b)
		return a;
	for (int i = maxN; i >= 0; i--)
		if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
		{
			a = LCA[a][i], b = LCA[b][i];
		}
	return LCA[a][0];
}
int getDist(int a, int b)
{
	int lca = getLCA(a, b);
	return level[a] + level[b] - 2 * level[lca];
}

int main()
{
	int n, a, b, q;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= maxN; j++)
			LCA[i][j] = -1;
	}
	for (int i = 1; i < n; i++)
		cin >> a >> b, ar[a].pb(b), ar[b].push_back(a);
	init(n);
	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		cout << getDist(a, b) << endl;
	}
	return 0;
}
