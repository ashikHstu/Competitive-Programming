#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w;
    cin >> n >> w;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int dp[n + 1][w + 1];
    // dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
            if (i == 0 || j == 0)
                continue;

            if (j < ar[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - ar[i - 1]]);
            }
        }
    }

    if (dp[n][w])
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}