#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int n, cnt[1000005];

int mul(int a, int b)
{
    return (long long)a * b % MOD;
}

int power(int x, int e)
{
    int res = 1;
    while (e)
    {
        if (e & 1)
            res = mul(res, x);
        x = mul(x, x);
        e >>= 1;
    }
    return res;
}

int inverse(int x)
{
    return power(x, MOD - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int mx = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }

    vector<int> primes;
    vector<bool> is_prime(mx + 1, true);
    for (int i = 2; i <= mx; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= mx; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    int ans = 1;
    for (int p : primes)
    {
        int c = cnt[p];
        if (c == 0)
            continue;
        int ways = 0;
        for (int e = 1; e <= c; e++)
        {
            int coef = mul(power(2, e - 1), power(p, mul(e, n)));
            ways = (ways + coef) % MOD;
        }
        ans = mul(ans, ways);
    }

    for (int c = 2; c <= mx; c++)
    {
        if (is_prime[c])
            continue;
        int freq[primes.size()] = {};
        int x = c;
        for (int i = 0; i < primes.size(); i++)
        {
            while (x % primes[i] == 0)
            {
                x /= primes[i];
                freq[i]++;
            }
        }
        if (x > 1)
            continue;
        int ways = 1;
        for (int i = 0; i < primes.size(); i++)
        {
            int f = cnt[primes[i]];
            int coef = 0;
            for (int j = 1; j <= freq[i]; j++)
            {
                coef = (coef + f - j + 1) % MOD;
            }
            if (coef < 0)
                coef += MOD;
            ways = mul(ways, coef);
        }
        ans = (ans + ways) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
