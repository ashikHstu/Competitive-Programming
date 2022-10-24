#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1000000000
const int inf = 1e9+9;

ll dp[102][100005];
ll n,w,V=100000;
ll weight[100005],value[100005];
//
//ll knapsack(ll cur,ll cost)
//{
//    if(cur==n)return 0;
//    if(dp[cur][cost]!=-1)return dp[cur][cost];
//
//    if(cost+value[cur]<=V)
//    {
//          dp[cur][cost]=min(knapsack(cur+1,cost+value[cur])+weight[cur],knapsack(cur+1,cost));
//    }
//    else {
//        dp[cur][cost]=knapsack(cur+1,cost);
//    }
//
//    return dp[cur][cost];
//
//}

ll knapsack2(int totalV)
{

    ll res=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=totalV;j++)
        {
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=totalV;j++)
        {
            if(j==0){

            dp[i][j]=0;
            continue;
            }
            if(value[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=min(dp[i-1][j],weight[i-1]+dp[i-1][j-value[i-1]]);
            }


            if(dp[i][j]<=w)res=j;
            if(dp[i][j]>INF)dp[i][j]=INF;
        }
    }

    return res;
}

int main()
{

    cin>>n>>w;
    int totalV=0;
    for(int i=0; i<n; i++){

        cin>>weight[i]>>value[i];
        totalV+=value[i];
    }


    cout<<knapsack2(totalV)<<endl;

    return 0;
}
