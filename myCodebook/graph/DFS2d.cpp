#include <bits/stdc++.h>
using namespace std;
int n, m;
#define sz 1001
int ar[sz][sz];
int visited[sz][sz];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || visited[x][y])
        return false;

    return ar[x][y];
}
void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
                ar[i][j] = 1;
            else
                ar[i][j] = 0;
        }
    }
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ar[i][j] == 1 and visited[i][j] == 0)
            {
                cc++;
                dfs(i, j);
            }
        }
    }
    cout << cc << endl;
    return 0;
}