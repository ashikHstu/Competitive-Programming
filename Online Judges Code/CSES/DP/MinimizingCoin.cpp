#include <bits/stdc++.h>
using namespace std;
#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inf 1000000000
int dp[102][1000002];
int value[102];
int n,m;



//
//int findNOC(int cur ,int taken)
//{
//
//    if(taken==m)return 0;
//    if(cur==n)return -5;
//    if(dp[cur][taken]!=-1)return dp[cur][taken];
//
//    int r=-5;
//    if(taken+value[cur]<=m)
//    {
//        int r1=findNOC(cur,taken+value[cur]);
//        int r2=findNOC(cur+1,taken+value[cur]);
//        if(r1>=0)r1++;
//        if(r2>=0)r2++;
//        if(r==-5 and r1>=0)r=r1;
//        if(r==-5 and r2>=0)r=r2;
//        else if(r2>=0)r=min(r,r2);
//    }
//    int rr=findNOC(cur+1,taken);
//    if(r==-5 and rr>=0)r=rr;
//    else if(rr>=0)r=min(r,rr);
//    return dp[cur][taken]=r;
//}

int main()
{
    FasterIO;
    cin>>n>>m;

    for(int i=0;i<n;i++)cin>>value[i];


    //memset(dp,-1,sizeof(dp));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {

            if(i==0)dp[i][j]=inf;
            if(j==0)dp[i][j]=0;
            if(i==0 || j==0)continue;
            if(i==1)
            {
                if(j%value[i-1]==0)dp[i][j]=j/value[i-1];
                else dp[i][j]=inf;
                continue;
            }

            if(value[i-1]<=j)
                dp[i][j]=min(1+dp[i][j-value[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];

        }
    }

    if(dp[n][m]>100000005)cout<<"-1\n";
    else cout<<dp[n][m]<<endl;
    return 0;


   // int r=findNOC(0,0);

//    cout<<"checking dp : "<<endl;
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<endl;
//    }




   // return 0;
}
