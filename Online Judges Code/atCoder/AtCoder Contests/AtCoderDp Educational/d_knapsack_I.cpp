#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[102][100005];
ll n,w;
ll weight[100005],value[100005];

ll knapsack(ll cur,ll cost)
{
    if(cur==n)return 0;
    if(dp[cur][cost]!=-1)return dp[cur][cost];

    if(cost+weight[cur]<=w)
    {
          dp[cur][cost]=max(knapsack(cur+1,cost+weight[cur])+value[cur],knapsack(cur+1,cost));
    }
    else {
        dp[cur][cost]=knapsack(cur+1,cost);
    }

    return dp[cur][cost];

}

int main()
{

    memset(dp,-1,sizeof(dp));
    cin>>n>>w;

    for(int i=0;i<n;i++)
        cin>>weight[i]>>value[i];


    cout<<knapsack(0,0)<<endl;

    return 0;
}
