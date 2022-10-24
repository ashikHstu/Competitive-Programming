#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;cin>>n>>x;

    int dp[n+2][x+2];

    int cost[n+2],value[n+2];
    for(int i=0;i<n;i++)cin>>cost[i];
    for(int i=0;i<n;i++)cin>>value[i];


    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(cost[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i-1][j-cost[i-1]]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }


    cout<<dp[n][x]<<endl;
    return 0;

}
