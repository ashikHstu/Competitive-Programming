#include <bits/stdc++.h>

#define mod 1000000007

#define ll long long int
#define endl '\n'
#define mem(a, x) memset(a, x, sizeof(a))

using namespace std;

ll calPow1(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 0)
        {
            b = b / 2;
            a = (a * a) % mod;
        }
        else
        {
            b--;
            ans = (ans * a) % mod;
        }
    }
    return ans;
}
ll mod1 = 1e9 + 9;
ll calPow2(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 0)
        {
            b = b / 2;
            a = (a * a) % mod1;
        }
        else
        {
            b--;
            ans = (ans * a) % mod1;
        }
    }
    return ans;
}

const int N = 5e3 + 2;
ll p1[N], p2[N], inv1[N], inv2[N], ar[N], br[N];
void preCalculations()
{
    ll a = 1, b = 1;
    p1[0] = 1;
    inv1[0] = 1;
    p2[0] = 1;
    inv2[0] = 1;
    for (ll i = 1; i <= 5000; i++)
    {
        a = (a * 31) % mod;
        p1[i] = a;
        inv1[i] = calPow1(a, mod - 2);
        b = (b * 137) % mod1;
        p2[i] = b;
        inv2[i] = calPow2(b, mod1 - 2);
    }
}
void calculate_hash(string &s)
{
    ll sum = 0, sum1 = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        ll a = p1[i] * (s[i] - 96);
        sum = (sum + a) % mod;
        ar[i] = sum;
        a = p2[i] * (s[i] - 96);
        sum1 = (sum1 + a) % mod1;
        br[i] = sum1;
    }
}
pair<ll, ll> find_hash(ll i, ll j)
{
    ll a = ar[j];
    if (i > 0)
        a = (a + mod) - ar[i - 1];
    a = (a * inv1[i]) % mod;
    ll b = br[j];
    if (i > 0)
        b = ((b + mod1) - br[i - 1]);
    b = (b * inv2[i]) % mod1;
    return {a, b};
}
void solve()
{
    ll n, i, a, b, j;
    string s;
    cin >> s;
    for (auto &a : s)
    {
        a = (char)tolower(a);
    }
    calculate_hash(s);
    ll ans = 0, table[s.size()];
    for (i = 1; i < s.size(); i++)
    {
        mem(table, 0);
        for (j = i - 1; j < s.size(); j++)
        {
            table[j] = i;
        }
        for (j = 2 * i - 1; j < s.size(); j++)
        {
            pair<ll, ll> p1 = find_hash(j - (2 * i) + 1, j - i);
            pair<ll, ll> p2 = find_hash(j - i + 1, j);
            if (p1 == p2)
            {
                table[j] = max(table[j], table[j - i] + i);
                ans = max(ans, table[j]);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    int cs = 1;
    preCalculations();
    cin >> t;
    while (t--)
    {
        // cout<<"Case #"<<cs<<": ";
        solve();
        cs++;
    }
}