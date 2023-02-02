#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10, mod = 998244353;

int n, T, a[N], b[N];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    T = read();
    while (T--)
    {
        n = read();
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
            a[i] = read();
        for (int i = 0; i < n; i++)
            b[i] = read();
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                x++;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                y++;
            if (y > x / 2)
            {
                printf("%lld\n", (ll)x * (n - x) % mod);
                break;
            }
        }
    }
    return 0;
}