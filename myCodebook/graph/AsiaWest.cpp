#include <bits/stdc++.h>
#define mod 1000000007
#define inf 1e18
#define ll long long int
#define endl '\n'
#define mem(a, x) memset(a, x, sizeof(a))
#define double long double
using namespace std;

// cout << "0th element: " << *A.find_by_order(0) << endl;
// cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;
// priority_queue <int, vector<int>, greater<int>>

ll mod1 = 1e9 + 9;

const int N = 1e6 + 3;
ll dp[N], ar[N], ct[N], mn[N];
void solve()
{
    ll n, i, m, k, a, b, j;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    for (i = 1; i <= m; i++)
    {
        cin >> dp[i];
    }
    dp[m + 1] = INT_MAX;
    for (i = m; i >= 1; i--)
    {
        dp[i] = min(dp[i], dp[i + 1]);
    }
    for (i = 2; i <= m + 1; i++)
    {
        for (j = 2; j * j <= i; j++)
        {
            a = (i + j - 1) / j;
            dp[i] = min(dp[i], dp[j] + dp[a]);
        }
    }
    ll l = 0, r = m, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll val = 0;
        for (i = 1; i <= n; i++)
        {
            if (ar[i] > mid)
            {
                if (mid == 0)
                {
                    a = ar[i] + 1;
                }
                else
                    a = (ar[i] + mid - 1) / mid;
                val += dp[a];
            }
            if (i > n / 2 || val > k)
            {
                break;
            }
        }
        if (val <= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    int cs = 1;
    cin >> t;
    while (t--)
    {
        // cout<<"Case #"<<cs<<": ";
        solve();
        cs++;
    }
}