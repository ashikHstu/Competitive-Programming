#include <bits/stdc++.h>
using namespace std;

/// Complexity : Time O(n*W), Space O(n*W)
#define mx 105 // mx is the max(n+1,w+1)
int val[] = {25, 44, 12, 33, 60};
int wt[] = {10, 20, 30, 40, 50};
int dp[mx][mx];

int knapsack(int n, int w)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    return dp[n][w];
}
// dp[arraySize][j] (j>=0 and j<=W) contain the max profit with knapsack size j

void knapsackWithPrint(int n, int w)
{
    int res = knapsack(n, w);
    int maxFill = res;
    for (int i = n; i > 0 and res > 0; i--)
    {
        if (res == dp[i - 1][w])
            continue;
        else
        {
            /// Do something here
            cout << "value  : " << val[i - 1] << endl;
            cout << "weight : " << wt[i - 1] << endl;
            w -= wt[i - 1];
            res -= val[i - 1];
        }
        cout << endl;
    }
    cout << "Total Filled size is : " << maxFill << endl;
}

int main()
{
    knapsackWithPrint(5, 10);
}