#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n,k;
int dp[1000001];
int ar[102];

int fun(int cur)
{

 if(cur<0)return 0;
    if(cur==0)return 1;


    if(dp[cur]!=-1)return dp[cur];
    ll res=0;
    for(int i=0;i<n;i++)
    {
        res=(res+(fun(cur-ar[i])))%mod;
    }

    return dp[cur]=res%mod;

}

int main()
{
    FasterIO;
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>ar[i];

    cout<<fun(k)<<endl;

}
