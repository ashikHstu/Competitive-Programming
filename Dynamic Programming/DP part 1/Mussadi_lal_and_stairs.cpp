/*
problem link : https://www.codechef.com/problems/JAM11
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define lim 1000006
ll dp[lim];

ll stairs(int n)
{
    if (n < 3)
        return n;
    if (n == 3)
        return 4;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (stairs(n - 1) % mod + stairs(n - 2) % mod + stairs(n - 3) % mod) % mod;

    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << stairs(n) % mod << endl;
    }
}