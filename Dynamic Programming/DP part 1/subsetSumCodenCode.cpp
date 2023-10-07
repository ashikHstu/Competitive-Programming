#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ar[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    bool dp[n + 1][m + 1];
    dp[0][0] = 1;

    for (int i = 2; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            if (j < ar[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                int need = j - ar[i];
                if (dp[i - 1][j] == 1 || dp[i - 1][need] == 1)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
                // dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - ar[i - 1]]);
            }
        }
    }
    bool ans = dp[n][m];
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}