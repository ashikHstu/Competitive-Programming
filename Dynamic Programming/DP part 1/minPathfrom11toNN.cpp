#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
int main()
{
    int n, m;
    cin >> n >> m;
    int ar[n + 10][m + 10], dp[n + 10][m + 10];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ar[i][j];
        }
    }

    for (int i = 1; i <= m + 1; i++)
    {
        dp[n + 1][i] = INF;
    }
    for (int i = 1; i <= n + 1; i++)
    {
        dp[i][m + 1] = INF;
    }
    dp[n + 1][m] = dp[n][m + 1] = 0;

    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            dp[i][j] = ar[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}