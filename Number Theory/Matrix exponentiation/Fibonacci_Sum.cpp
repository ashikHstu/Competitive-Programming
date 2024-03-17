
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
const int sz = 2;

struct Mat
{
    ll m[sz][sz];
    Mat()
    {
        memset(m, 0, sizeof(m));
    }
    void identity()
    {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
    }

    // operator overloading
    Mat operator*(Mat a)
    {
        Mat res;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};
Mat expo(Mat T, int n)
{
    /// The T Mat value will assign earlier, default value is 0
    Mat res;
    res.identity();

    while (n)
    {
        if (n & 1)
            res = res * T;
        T = T * T;
        n /= 2;
    }
    return res;
}
ll Fib(int n)
{
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
    n -= 2;
    Mat res = expo(T, n);
    return (res.m[0][0] + res.m[0][1]) % mod;
}

ll fiboSum(int n)
{
    return (Fib(n + 2) - 1 + mod) % mod;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << (Fib(r + 2) - Fib(l + 1) + mod) % mod << endl;
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

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
