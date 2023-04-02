
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string st;
    cin >> st;
    int lft = 0, up = 0;
    for (char ch : st)
    {
        if (ch == 'L')
            lft++;
        else if (ch == 'R')
            lft--;
        else if (ch == 'U')
            up++;
        else if (ch == 'D')
            up--;
    }

    int res = (abs(lft) + abs(up));
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
