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

const int mod = 1e9 + 7;
const int maxn = 200005;
vector<int> g[maxn];
int visited[maxn];

#define maxN 200005
#define K 25
int Log[maxN + 1];
int sparse_table[maxN][K + 1];
int ar[maxN];
int N;

/// precomputing all logarithm
void calLog()
{
    Log[1] = 0;
    for (int i = 2; i <= maxN; i++)
        Log[i] = Log[i / 2] + 1;
}

void makeSparseMax()
{
    for (int i = 0; i < N; i++)
    {
        sparse_table[i][0] = ar[i];
    }
    for (int j = 1; j <= K; j++)
    {
        for (int i = 0; i + (1 << j) <= N; i++)
        {
            sparse_table[i][j] = min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int findMin(int L, int R)
{
    int j = Log[R - L + 1];
    int maximum = min(sparse_table[L][j], sparse_table[R - (1 << j) + 1][j]);
    return maximum;
}

void dfs(int cur)
{
    visited[cur] = 1;
    for (int v : g[cur])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

void solve(int kase)
{
    int n;
    cin >> n;
    N = n * 2 + 1;
    string st;
    cin >> st;
    vector<int> chk(n * 2 + 2, -1);
    int curV = 0;

    ar[0] = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (st[i] == '(')
        {
            curV++;
        }
        else
        {
            curV--;
        }
        ar[i + 1] = curV;
        // if (chk[curV] != -1)
        // {
        //     cout << "connecting : " << chk[curV] + 1 << ", " << i + 1 << endl;
        //     g[chk[curV] + 1].pb(i + 1);
        //     g[i + 1].pb(chk[curV] + 1);
        //     chk[curV] = i + 1;
        // }
    }

    int prev[n * 2 + 3];
    int ending[n * 2 + 3];
    mem(ending, 0);
    mem(prev, -1);
    makeSparseMax();
    for (int i = 0; i <= n * 2; i++)
    {
        if (prev[ar[i]] == -1)
        {
            prev[ar[i]] = i;
        }
        else
        {
            int mn = findMin(prev[ar[i]], i);
            // cout << "min of " << prev[ar[i]] << ", " << i << " : " << mn << endl;
            // cout << "ar at min : " << ar[i] << endl;
            if (mn >= ar[i])
            {
                g[prev[ar[i]] + 1].pb(i);
                g[i].pb(prev[ar[i]] + 1);
                if (ending[prev[ar[i]]] != 0)
                {
                    g[prev[ar[i]]].pb(i);
                    g[i].pb(prev[ar[i]]);
                }
                ending[i] = 1;

                // cout << prev[ar[i]] + 1 << " " << i << endl;
            }
            prev[ar[i]] = i;
        }
    }

    int res = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        if (visited[i] == 0)
        {
            res++;
            dfs(i);
        }
    }
    cout << res << endl;
    for (int i = 0; i <= 2 * n; i++)
    {
        g[i].clear();
        visited[i] = 0;
    }
}

int main()
{
    calLog();
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
