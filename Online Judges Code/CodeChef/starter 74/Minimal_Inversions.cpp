

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define mem(a, b) memset(a, b, sizeof(a))

#define pb push_back

void solve()
{
    int n;

    scanf("%d", &n);
    vector<int> reduce[n + 3];

    int ct[n + 2];
    int aroBad[n + 4];
    mem(ct, 0);
    mem(aroBad, 0);
    int ar[n + 2];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &ar[i]);
        reduce[ar[i]].pb(i);
    }
    int cur = 0;
    int mainRes = 0;
    for (int j = n; j >= 1; j--)
    {
        int rs = reduce[ar[j] + 1].size();
        if (rs > 0)
        {
            cur += (rs - aroBad[ar[j] + 1]);
            for (int k = 0; k < rs; k++)
            {
                ct[reduce[ar[j] + 1][k]]++;
            }
        }

        cur -= ct[j];
        mainRes = max(cur, mainRes);
        aroBad[ar[j]]++;
    }

    printf("%d\n", mainRes);
}

int main()
{
    FasterIO;
    int tc = 1;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}
