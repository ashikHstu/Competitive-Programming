#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int ar[6]={1,2,3,4,5,6};

int dp[1000006];

int fun(int n)
{
    if(n<0)return 0;
    if(n==0)return 1;

    if(dp[n]!=-1)return dp[n];
    ll res=0;
    for(int i=1;i<=6;i++)
    {
        res+=(fun(n-i));
        res%=mod;
    }

    return dp[n]=res%mod;



}

int main()
{
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));


    cout<<fun(n)<<endl;

    return 0;
}
