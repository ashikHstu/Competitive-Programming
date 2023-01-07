/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://www.spoj.com/problems/LKS/
   verdict :  accepted
*/
#include <bits/stdc++.h>
using namespace std;
#define mx 2000005

long long int dp[2][mx];
long long int val[505];
int wt[505];
int k = 0;
int knapsackOptimized(int n, int w)
{
    for (int i = 0; i <= n; i++, k = !k)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[k][j] = 0;
            else if (wt[i - 1] > j)
                dp[k][j] = dp[!k][j];
            else
                dp[k][j] = max(dp[!k][j], val[i - 1] + dp[!k][j - wt[i - 1]]);
        }
    }
    return dp[!k][w];
}

int main()
{
    int n, w;
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &val[i], &wt[i]);
    }
    long long int res = knapsackOptimized(n, w);
    printf("%lld\n", res);
    return 0;
}
/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
