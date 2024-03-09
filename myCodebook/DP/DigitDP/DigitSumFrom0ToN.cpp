#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll cnt(string &st, int n, bool tight)
{
    if (tight == 0)
    {
        return (pow(10, n) + 0.1);
    }
    if (n == 0)
        return 1;
    ll numbers = 0;
    int ub = st[st.size() - n] - '0';
    for (int dig = 0; dig <= ub; dig++)
    {
        numbers += (cnt(st, n - 1, tight & (dig == ub)));
    }
    return numbers;
}
ll dp[20][2];
ll DigitSum(string st, int n, int tight)
{
    if (n == 0)
        return 0;
    if (dp[n][tight] != -1)
        return dp[n][tight];
    int ub = tight ? (st[st.size() - n] - '0') : 9;
    ll total = 0;
    for (int dig = 0; dig <= ub; dig++)
    {
        total += dig * (cnt(st, n - 1, tight & (dig == ub)));
        total += DigitSum(st, n - 1, tight & (dig == ub));
    }
    return dp[n][tight] = total;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    if (l != 0)
        l--;
    string L, R;
    L = to_string(l);
    R = to_string(r);
    memset(dp, -1, sizeof(dp));
    ll Rsum = DigitSum(R, R.length(), 1);
    memset(dp, -1, sizeof(dp));
    ll Lsum = DigitSum(L, L.length(), 1);
    ll res = Rsum - Lsum;
    // cout<<"Digit sum from l to r : ";
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