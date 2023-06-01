#include <bits/stdc++.h>
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
using namespace std;
int main()
{
    // sync;
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int a[n + 4];
        map<int, int> mp;

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            mx = max(mx, a[i]);
        }

        int mx1 = 0, d = 0;

        for (auto x : mp)
        {
            mx1 = max(mx1, x.second);
        }
        for (auto x : mp)
        {
            if (x.second == mx1)
                d++;
        }

        // cout<< mx << "  "<< mx1<<"  "<< d << endl;

        if (d == 1)
            cout << "Yes\n";
        else
            cout << "No\n";

        mp.clear();
    }
    return 0;
}
