#include <bits/stdc++.h>
using namespace std;

string st[105];
int visited[105][105];
int alive;
int n;
int fx[] = {+1, -1, +0, +0};
int fy[] = {+0, +0, +1, -1};
bool isValid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return false;
    else if (visited[i][j] == 1 || st[i][j] == '.')
        return false;
    return true;
}
void dfs(int i, int j)
{
    visited[i][j] = 1;
    if (st[i][j] == 'x')
        alive = true;
    for (int ind = 0; ind < 4; ind++)
    {
        if (isValid(i + fx[ind], j + fy[ind]))
        {
            dfs(i + fx[ind], j + fy[ind]);
        }
    }
}
void solve(int kase)
{
    memset(visited, 0, sizeof(visited));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> st[i];
    }

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && st[i][j] != '.')
            {
                alive = false;
                dfs(i, j);
                if (alive)
                    res++;
            }
        }
    }

    printf("Case %d: %d\n", kase, res);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}
