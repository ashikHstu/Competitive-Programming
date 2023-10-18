#include <bits/stdc++.h>

#define mod 1000000007
#define inf 1e18
#define ll long long
#define int long long
#define endl '\n'
#define mem(a, x) memset(a, x, sizeof(a))
#define double long double
using namespace std;

// cout << "0th element: " << *A.find_by_order(0) << endl;
// cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;
// priority_queue <int, vector<int>, greater<int>>

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> ar1(n + 2, (vector<ll>(m + 2, 0)));
    vector<vector<ll>> ar2(n + 2, (vector<ll>(m + 2, 0)));
    vector<vector<ll>> ar3(n + 2, (vector<ll>(m + 2, 0)));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ar1[i][j];
            ar2[i][j] = ar1[i][j];
            ar2[i][j] += ar2[i - 1][j];
            ar3[i][j] = ar1[i][j];
            ar3[i][j] += ar3[i][j - 1];
        }
    }
    ll result = 0;
    for (int j = 1; j <= m; j++)
    {
        ll sum = ar1[1][j];
        int a = 0, b = 0;
        for (int i = 2; i <= n; i++)
        {
            ll c = min({i - 1, j - 1, n - i, m - j});
            if (c > a && b == 0)
            {
                a++;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else if (a > 0)
            {
                b = 1;
                a--;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else
            {
                break;
            }
        }
        result = max(result, sum);
        sum = ar1[n][j];
        a = 0, b = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            ll c = min(i - 1, min(j - 1, min(n - i, m - j)));
            if (c > a && b == 0)
            {
                a++;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else if (a > 0)
            {
                b = 1;
                a--;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else
            {
                break;
            }
        }
        result = max(result, sum);
    }
    for (int i = 1; i <= n; i++)
    {
        ll summation = ar1[i][1];
        int a = 0, b = 0;
        for (int j = 2; j <= m; j++)
        {
            ll c = min({i - 1, j - 1, n - i, m - j});
            if (c > a && b == 0)
            {
                a++;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else if (a > 0)
            {
                a--;
                b = 1;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else
            {
                break;
            }
        }
        result = max(result, summation);
        summation = ar1[i][m];
        a = 0, b = 0;
        for (int j = m - 1; j >= 1; j--)
        {
            ll c = min({i - 1, j - 1, n - i, m - j});
            if (c > a && b == 0)
            {
                a++;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else if (a > 0)
            {
                a--;
                b = 1;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else
            {
                break;
            }
        }
        result = max(result, summation);
    }
    cout << result << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    int cs = 1;
    // cin>>t;
    while (t--)
    {
        // cout<<"Case #"<<cs<<": ";
        solve();
        cs++;
    }
}