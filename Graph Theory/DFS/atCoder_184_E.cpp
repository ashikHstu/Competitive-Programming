/** Problem : https://atcoder.jp/contests/abc184/tasks/abc184_e

*/
#include <bits/stdc++.h>
using namespace std;
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
int dx[4] = {0, 0, +1, -1};
int dy[4] = {+1, -1, 0, 0};
string st[2002 + 2];
int h, w;
vector<pair<int, int>> multiple[30];
int color[2004][2004];
int dist[2004][2004];
bool isValid(int i, int j)
{
    if (i < 0 || i >= h || j < 0 || j >= w)
        return false;
    if (st[i][j] == '#')
        return false;
    if (color[i][j] != 0)
        return false;
    return true;
}
int bfs(pair<int, int> start, pair<int, int> finish)
{
    queue<pair<int, int>> q;
    q.push(start);
    color[start.first][start.second] = 1;
    dist[start.first][start.second] = 0;
    bool checker[30] = {false};
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        if (u == finish)
        {
            return dist[u.first][u.second];
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newStage_i = u.first + dx[i];
            int newStage_j = u.second + dy[i];
            if (isValid(newStage_i, newStage_j))
            {
                color[newStage_i][newStage_j] = 1;
                dist[newStage_i][newStage_j] = dist[u.first][u.second] + 1;
                q.push({newStage_i, newStage_j});
            }
        }
        if (st[u.first][u.second] >= 'a' && st[u.first][u.second] <= 'z')
        {
            int needed_ind = st[u.first][u.second] - 'a';
            if (!checker[needed_ind])
            {
                checker[needed_ind] = true;

                for (pair<int, int> p : multiple[needed_ind])
                {
                    if (isValid(p.first, p.second))
                    {
                        color[p.first][p.second] = 1;
                        dist[p.first][p.second] = dist[u.first][u.second] + 1;
                        q.push(p);
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    FasterIO;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> st[i];
    pair<int, int> start, finish;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (st[i][j] == 'S')
            {
                start = make_pair(i, j);
            }
            else if (st[i][j] == 'G')
            {
                finish = make_pair(i, j);
            }
            else if (st[i][j] != '#' && st[i][j] != '.')
            {
                multiple[st[i][j] - 'a'].push_back({i, j});
            }
        }
    }
    cout << bfs(start, finish) << endl;
    return 0;
}
