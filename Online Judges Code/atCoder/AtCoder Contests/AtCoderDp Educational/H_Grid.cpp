#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    int h,w;
    cin>>h>>w;
    string st[h+2];
    for(int i=0;i<h;i++)cin>>st[i];

    ll dp[h+2][w+2];

    dp[h-1][w-1]=0;
    for(int i=0;i<=h;i++)
    {
        dp[i][w]=0;
    }
    for(int i=0;i<=w;i++)
    {
        dp[h][i]=0;
    }

  for(int i=h-1;i>=0;i--)
  {
      for(int j=w-1;j>=0;j--)
      {
          if(i==h-1 && j==w-1){
            dp[i][j]=1;continue;
          }
          if(st[i][j]=='#')dp[i][j]=0;
          else {
            dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
          }
      }
  }


  //cout<<"res : ";
  cout<<dp[0][0]<<endl;

  return 0;

}
