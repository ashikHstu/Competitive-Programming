#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ar[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    bool dp[m + 1] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int curr_ele = ar[i];

        for (int j = m; j >= curr_ele; j--)
        {
            if (dp[j] == 1 || (dp[j - curr_ele] == 0))
                continue;
            else
                dp[j] = 1;
        }
    }
    for (int i = 0; i <= m; i++)
        cout << dp[i] << " ";
    cout << endl;
    bool ans = dp[m];
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}