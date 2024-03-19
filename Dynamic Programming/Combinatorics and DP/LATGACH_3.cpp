
#include <bits/stdc++.h>
using namespace std;

#define int long long int

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve(int n)
{
    int f[n + 1], g[n + 1];
    f[0] = g[0] = 1;
    f[1] = g[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 2] + 2 * g[i - 2];
        g[i] = g[i - 2] + f[i];
    }
    cout << f[n] << endl;
}

int32_t main()
{
    int tc = 1;

    while (cin >> tc)
    {
        if (tc == -1)
            return 0;
        solve(tc);
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
