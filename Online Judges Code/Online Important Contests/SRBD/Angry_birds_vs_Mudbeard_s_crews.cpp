/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define MinHeap priority_queue<int, vector<int>, greater<int>>
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(), x.end())
#define Reverse(x) reverse(x.begin(), x.end())
#define SortA(ar, s) sort(ar, ar + s)
#define SortD(ar, s) sort(ar, ar + s, greater<int>())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define sq(x) (x) * (x)
#define CEIL(a, b) ((a / b) + ((a % b) != 0))
#define NUMLEN(Num) to_string(Num).size()

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")

/// vector
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
const int mod = 1e9 + 7;
const int maxn = 105;
int ar[maxn][maxn];
int n, m;
int visited[maxn][maxn];
bool isValid(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m)
        return false;
    if (ar[i][j] == -1)
    {
        return false;
    }
    if (visited[i][j] == 1)
        return false;
    return true;
}

void solve(int kase)
{
    cout << "Case " << kase << ": ";
    cin >> n >> m;

    mem(ar, 0);
    memset(visited, 0, sizeof(visited));
    pair<int, int> tunel;
    int birds = 0;
    bool posible = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;

            if (ar[i][j] == -1)
            {

                if (ch == 'b' || ch == 't')
                {

                    posible = false;
                    //  cout << "happening at : " << i << " " << j << endl;
                }
            }
            if (ch == 'c')
            {
                for (int ix = 0; ix < 4; ix++)
                {
                    if (ar[i + fx[ix]][j + fy[ix]] == 2 || ar[i + fx[ix]][j + fy[ix]] == 5)
                        posible = false;
                }
                for (int ix = 0; ix < 4; ix++)
                {
                    ar[i + fx[ix]][j + fy[ix]] = -1;
                }
                //  ar[i][j] = ar[i - 1][j] = ar[i + 1][j] = ar[i][j + 1] = ar[i][j - 1] = -1;
            }
            else if (ch == '#')
                ar[i][j] = -1;
            else if (ch == 't')
            {
                tunel = {i, j};
                ar[i][j] = 5;
            }
            else if (ch == 'b')
            {
                birds++;
                ar[i][j] = 2;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << ar[i][j] << " ";
    //     cout << endl;
    // }

    //  cout << "possible : " << posible << endl;
    if (!posible)
    {
        cout << "no\n";
        return;
    }

    // cout << "Here?" << endl;

    queue<pair<int, int>> q;

    visited[tunel.first][tunel.second] = 1;
    q.push(tunel);
    int taken = 0;
    // cout << "points : " << endl;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();

        if (ar[cur.first][cur.second] == 2)
            taken++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + fx[i];
            int ny = cur.second + fy[i];
            if (isValid(nx, ny))
            {
                q.push({nx, ny});

                visited[nx][ny] = 1;
            }
        }
    }

    //  cout << "taken , birds : " << taken << ", " << birds << endl;

    if (taken == birds)
        cout << "yes\n";
    else
        cout << "no\n";

    // memset(ar,0,sizeof(ar));
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
