
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 3 != 0)
    {
        cout << "-1\n";
        return;
    }
    int each = (a + b + c) / 3;
    int res = abs(each - a);
    res += (abs(each - b));
    res += (abs(each - c));
    res /= 2;
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
