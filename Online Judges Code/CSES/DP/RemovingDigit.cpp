#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int fun(int n)
{
    if(n==0)return 0;
    if(n<0)return 1000000000;

    if(dp[n]!=-1)return dp[n];

    int div=1;
    int r=100000000;
    for(int i=0;i<8;i++)
    {
        int d=n/div;
        d=d%10;

        div*=10;
        if(d!=0){
             r=min(r,fun(n-d));
        }
    }

    return dp[n]=r+1;
}


int main()
{
    int n;cin>>n;

    memset(dp,-1,sizeof(dp));

    cout<<fun(n)<<endl;
    return 0;

}
