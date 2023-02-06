#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int extended_euclid(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int g = extended_euclid(b % a, a, y, x);
    x -= (b / a) * y;
    return g;
}

int find_modulo_inverse(int a, int m)
{
    int x, y;
    int g = extended_euclid(a, m, x, y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}

int find_time(int a[], int b[], int n)
{
    int res = b[0];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        int a1 = lcm(a[0], a[i]);
        int b1 = b[i] - b[0];
        int g = extended_euclid(a[0], a[i], x, y);
        if (b1 % g != 0)
            return -1;
        x = find_modulo_inverse(a[0] / g, a[i] / g);
        x = (x * b1 / g) % (a[i] / g);
        res += (a1 / a[0]) * x * a[0] + b[0];
        a[0] = a1;
        b[0] = res;
    }
    return res;
}

signed main()
{
    int n, a[1005], b[1005];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    cout << find_time(a, b, n) << endl;
    return 0;
}