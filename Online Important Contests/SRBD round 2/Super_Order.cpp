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

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j)) // turn off j'th bit
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1)) // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1)) // turn off the last on bit
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

const int mod = 1e9 + 7;
const int maxn = 555;

ll partnership[maxn][maxn];

ll nextFind[maxn][maxn];

ll dp[12][(1 << 12)];

ll findMaxRun(int cur, int indicator, int &n)
{
    if (indicator == 0)
        return 0;

    if (dp[cur][indicator] != -1)
        return dp[cur][indicator];
    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        if (isOn(indicator, i))
        {
            ll temp = partnership[cur][i];
            ll newIndicator = indicator ^ (1 << i);
            if (nextFind[cur][i] == 0)
                temp += findMaxRun(i, newIndicator, n);

            else
                temp += findMaxRun(cur, newIndicator, n);
            res = max(res, temp);
        }
    }
    return dp[cur][indicator] = res;
}

void solve(int kase)
{
    mem(nextFind, 0);
    mem(partnership, 0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            //  cout << ch;
            int r;
            cin >> r;
            //  cout << r;
            partnership[i][j] = r;
            cin >> ch;
            //  cout << ch;
            cin >> ch;
            // cout << ch;
            if (ch == 'T')
                nextFind[i][j] = 1;
            else
                nextFind[i][j] = 0;
            cin >> ch;
            // cout << ch << " ";
        }
        //  cout << endl;
    }

    memset(dp, -1, sizeof(dp));
    ll res = 0;
    ll indicator = 1 << n;
    indicator--;
    for (int i = 0; i < n; i++)
    {
        ll nIndicator = indicator ^ (1 << i);
        ll temp = findMaxRun(i, nIndicator, n);
        res = max(res, temp);
    }
    cout << "Case " << kase << ": " << res << endl;
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
