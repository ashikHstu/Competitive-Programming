#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    int ar[n + 2];
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        sum += ar[i];
        //  res[i] = i;
    }
    if (sum != n - 1)
    {
        cout << "NO\n";
        return;
    }
    if (ar[1] != 0 || ar[n] == 0)
    {
        cout << "NO\n";
        return;
    }
    vector<int> res;

    vector<int> extra;
    extra.pb(1);
    for (int i = 2; i <= n; i++)
    {
        if (ar[i] == 0)
        {
            extra.pb(i);
        }
        else
        {
            if (res.size() > 0)
            {
                if (res.back() < i)
                {
                    ar[i]--;
                }
            }
            res.pb(i);

            if (ar[i] > extra.size())
            {
                cout << "NO\n";
                return;
            }
            while (ar[i] > 0)
            {
                ar[i]--;
                res.pb(extra.back());
                extra.pop_back();
            }
        }
    }

    for (int v : extra)
        res.pb(v);
    cout << "YES\n";
    for (int r : res)
        cout << r << " ";
    cout << endl;
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
