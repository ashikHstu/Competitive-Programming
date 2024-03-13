#include <bits/stdc++.h>
using namespace std;
string n;
int memo[11][101][2];
#define md 1000000007

int fun(int ind, int res, int last)
{
    if (ind == n.size())
        return res % md;
    if (memo[ind][res][last] != -1)
        return memo[ind][res][last];
    int till = (last ? n[ind] - '0' : 9);
    int sum = 0;
    for (int i = 0; i <= till; i++)
    {
        sum += (fun(ind + 1, res + (i == 1), last && (i == till))) % md;
    }
    return memo[ind][res][last] = sum % md;
}

int solve(int _n)
{
    n = to_string(_n);

    memset(memo, -1, sizeof(memo));
    return fun(0, 0, true);
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
}