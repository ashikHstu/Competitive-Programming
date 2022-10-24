#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int dp[101][1000006];

int main()
{
    int n,x;cin>>n>>x;
    int coin[n+2];
    for(int i=0;i<n;i++)cin>>coin[i];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
            if(i==0 || j==0)continue;

            if(coin[i-1]<=j)dp[i][j]=(dp[i-1][j]+dp[i][j-coin[i-1]])%mod;
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][x]<<endl;

    return 0;

}
