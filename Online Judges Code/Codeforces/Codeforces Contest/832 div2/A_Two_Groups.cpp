#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;
    int Neg = 0, Pos = 0;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v < 0)
            Neg -= v;
        else
            Pos += v;
    }
    int res = abs(Pos - Neg);
    cout << res << endl;
}

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}