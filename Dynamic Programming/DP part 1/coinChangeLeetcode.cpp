#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount)
{
    int n = coins.size();
    int dp[amount + 1];
    dp[0] = 0;
    int INF = 100000;
    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INF;
    }

    for (int i = 1; i <= amount; i++)
    {
        int res = INF;
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                res = min(res, dp[i - coins[j]]);
            }
        }
        if (res == INF)
            dp[i] = INF;
        else
            dp[i] = res + 1;
    }
    if (dp[amount] == INF)
        return -1;
    return dp[amount];
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    int sum;
    cin >> sum;
    cout << coinChange(vec, sum) << endl;
}