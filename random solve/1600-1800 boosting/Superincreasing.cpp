#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long st = 1;
    long long ct = 1;
    int n, x, k;
    cin >> n >> k >> x;
    while (ct != k)
    {
        st = st * 2;
        ct++;
        if (st > x)
        {
            cout << "No\n";
            return;
        }
    }

    if (st <= x)
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";
}

int main()
{
    // your code goes here
    int tc;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
