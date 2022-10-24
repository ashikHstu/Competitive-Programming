#include <bits/stdc++.h>
using namespace std;

#define N 55 //Number of Coin
#define SUM 255  // The Value Which have to change.
long long int dp[N][SUM];
long long int ar[N];
int sum,n;
long long int numberOfWay(int pos,int curSum)
{
   if(curSum==0)return 1;
   if(curSum<0)return 0;
   if(pos==n)return 0;

   if(dp[pos][curSum]!=-1)return dp[pos][curSum];

   return dp[pos][curSum]=numberOfWay(pos,curSum-ar[pos])+numberOfWay(pos+1,curSum);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>sum>>n;
    for(int i=0; i<n; i++)
        cin>>ar[i];

    cout<<numberOfWay(0,sum)<<endl;
    return 0;

}
