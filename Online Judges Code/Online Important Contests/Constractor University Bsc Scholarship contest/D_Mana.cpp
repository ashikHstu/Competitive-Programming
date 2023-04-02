
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string res;
    long long int n;
    cin >> n;
    while (n != 1)
    {
        long long int t1 = n / 2;
        long long int t2 = (n / 2) + 1;
        if (t1 % 2 == 1)
        {
            res.push_back('2');
            n = t1;
        }
        else
        {
            res.push_back('1');
            n = t2;
        }
    }
    reverse(res.begin(), res.end());
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
