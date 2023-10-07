#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ar[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    int dp[m + 1] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int curr_ele = ar[i];

        for (int j = m; j >= curr_ele; j--)
        {
            if (dp[j] || (dp[j - curr_ele] == 0))
                continue;
            else
            {
                // cout << "updating curel : " << curr_ele << endl;
                dp[j] = curr_ele;
            }
        }
    }

    if (dp[m] == 0)
        cout << "-1";
    else
    {
        int cur = m;
        int i = 10;
        while (cur > 0)
        {
            // cout << "cur : " << cur << endl;
            cout << dp[cur] << " ";
            cur -= dp[cur];
        }
    }

    return 0;
}