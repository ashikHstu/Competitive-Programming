
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
const int maxn = 1000005;

int max_total = maxn - 1;
ll st[maxn << 2];
int chk[maxn << 2];

bool Update(int Point, int b, int e, int idx, int v)
{
    if (b == e)
    {
        if (v > 0)
        {
            st[Point] += idx;
            chk[Point] += v;
        }
        else if (chk[Point] >= abs(v))
        {
            chk[Point] += v;
            st[Point] -= idx;
            return true;
        }

        return false;
    }

    bool ok = false;
    int mid = (b + e) / 2;
    if (idx <= mid)
        ok = Update(Point << 1, b, mid, idx, v);
    else
        ok = Update(Point << 1 | 1, mid + 1, e, idx, v);
    st[Point] = st[Point << 1] + st[Point << 1 | 1];
    chk[Point] = chk[Point << 1] + chk[Point << 1 | 1];
    return ok;
}

ll ask(int point, int b, int e, int k)
{
    if (k == 0)
        return 0;
    if (b == e)
    {
        return 1LL * k * b;
    }

    ll ans = 0;
    int mid = (b + e) / 2;
    if (chk[point << 1] <= k)
    {
        ans += st[point << 1];
        ans += ask(point << 1 | 1, mid + 1, e, k - chk[point << 1]);
    }
    else
        ans = ask(point << 1, b, mid, k);

    return ans;
}

void solve(int kase)
{

    // memset(ar,0,sizeof(ar));

    while (true)
    {
        int t;
        cin >> t;
        if (t == -1)
            return;
        if (t == 1)
        {
            int v;
            cin >> v;
            bool checkOk = Update(1, 1, max_total, v, 1);
        }
        else if (t == 2)
        {
            int v;
            cin >> v;
            bool checkOk = Update(1, 1, max_total, v, -1);
            if (checkOk)
                cout << v << endl;
            else
                cout << "-1\n";
        }
        else
        {
            int k;
            cin >> k;
            ll r = ask(1, 1, max_total, k);
            cout << r << endl;
        }
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
