
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    ll res = 0;
    res = 2;
    n -= 2;
    while (n > 0)
    {
        res *= 2;
        n -= 1;
    }
    cout << res << endl;
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}
