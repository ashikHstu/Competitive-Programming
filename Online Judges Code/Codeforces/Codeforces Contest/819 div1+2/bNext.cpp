#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if (n > m || (!(n & 1) && m & 1))
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        if (n == m)
        {
            for (int i = 1; i <= n; i++)
                cout << 1 << " ";
            cout << endl;
        }
        else if (n & 1)
        {
            for (int i = 1; i < n; i++)
                cout << 1 << " ";
            cout << m - n + 1 << endl;
        }
        else
        {
            for (int i = 1; i <= n - 2; i++)
                cout << 1 << " ";
            int k = (m - n + 2) / 2;
            cout << k << " " << k << endl;
        }
    }
    return 0;
}
