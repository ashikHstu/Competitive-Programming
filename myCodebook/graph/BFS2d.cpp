#include <bits/stdc++.h>
using namespace std;
int n;
#define sz 33
int adj[sz][sz];
int visited[sz][sz];
int dis[sz][sz];
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}; // Knights Move
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1}; // Knights Move
bool isValid(int x, int y)
{
    if (x > 8 || x < 1 || y < 1 || y > 8 || visited[x][y])
        return false;
    return true;
}
int bfs(int sx, int sy, int dsx, int dsy)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    dis[sx][sy] = 0;
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        if (curX == dsx && curY == dsy)
            return dis[curX][curY];
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int childX = curX + dx[i];
            int childY = curY + dy[i];
            if (isValid(childX, childY))
            {
                dis[childX][childY] = dis[curX][curY] + 1;
                visited[childX][childY] = 1;
                q.push({childX, childY});
            }
        }
    }
}
void solve()
{
    memset(dis, 0, sizeof(dis));
    memset(visited, 0, sizeof(visited));
    char ch1, ch2;
    int x1, x2;
    cin >> ch1 >> x1 >> ch2 >> x2;
    int y1 = ch1 - 'a' + 1;
    int y2 = ch2 - 'a' + 1;
    cout << bfs(x1, y1, x2, y2) << endl;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}