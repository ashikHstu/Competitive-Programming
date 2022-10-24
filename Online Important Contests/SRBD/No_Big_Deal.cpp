

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
const int maxn = 1000006;

ll n, ar[maxn];

ll Find(ll l, ll r)
{
    if (l == 0)
        return ar[r];
    return ar[r] ^ ar[l - 1];
    // ll res;
    // if (l != 0)
    //     res = ar[r];
    // else
    //     res = (ar[r] ^ ar[l - 1]);
    // return res;
}

void solve(int kase)
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (i != 0)
            ar[i] = (ar[i] ^ ar[i - 1]);
    }
    ar[n] = 0;

    int q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;

        ll res = 0;
        if (r - l + 1 >= n + 1)
        {
            l %= (n + 1);
            r %= (n + 1);
            res = Find(l, n);
            res ^= Find(0, r);
            cout << res << endl;
        }
        else
        {
            l %= (n + 1);
            r %= (n + 1);
            if (l > r)
            {
                res = Find(l, n);
                res ^= Find(0, r);
                cout << res << endl;
            }
            else
            {
                res = Find(l, r);
                cout << res << endl;
            }
        }

        //  cout << res << endl;
    }
}

int main()
{
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
