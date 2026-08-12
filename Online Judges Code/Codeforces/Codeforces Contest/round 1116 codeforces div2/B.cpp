#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
string st;

long long dp[200005][7][7];

long long findWays(int i,int prevValue,int prevSum)
{
    //cout<<"i, prev, prevSum: "<<i<<", "<<prevValue<<", "<<prevSum<<endl;
    if(i==n)return 1;
    // cout<<"chk0"<<endl;
    if(dp[i][prevValue][prevSum]!=-1)return dp[i][prevValue][prevSum];
    long long wys = 0;

    if(i==0){
        if(st[i]=='0'){
            wys=findWays(i+1,0,0);
        }
        else if(st[i]=='1')
        {
            wys=findWays(i+1,1,0);
        }
        else{
            wys+=findWays(i+1,0,0);
            wys+=findWays(i+1,1,0);
        }
    }
    else if(i==1){
        if(st[i]=='0'){
            wys=findWays(i+1,0,prevValue);
        }
        else if(st[i]=='1'){
            wys=findWays(i+1,1,prevValue+1);
        }
        else{
            wys+=findWays(i+1,0,prevValue);
            wys+=findWays(i+1,1,prevValue+1);
        }
    }
    else{
            if(st[i]=='0'){
          if(prevValue == prevSum)return 0;
          wys = findWays(i+1,0,prevValue);
          wys%=mod;
    }
    else if(st[i]=='1')
    {
        if(prevValue+1 == prevSum)return 0;
        wys = findWays(i+1,1,prevValue+1);
        wys%=mod;
    }
    else{
        if(prevValue != prevSum){
            wys+=findWays(i+1,0,prevValue);
            wys%=mod;
        }
        if(prevValue+1 != prevSum){
            wys+=findWays(i+1,1,prevValue+1);
            wys%=mod;
        }
    }
    }
  //  cout<<"chk1"<<endl;

  //  cout<<"Normally executed."<<endl;
    return dp[i][prevValue][prevSum]=wys%mod;



}

void solve()
{
    cin>>n;
    cin>>st;
    //cout<<"given n: "<<n<<endl;
   // cout<<"Given string is : "<<st<<endl;
   for(int i=0;i<=n;i++)
   {
      for(int j=0;j<7;j++)
      {
        for(int  k=0;k<7;k++)
        {
            dp[i][j][k]=-1;
        }
      }
   }
    // memset(dp,-1,sizeof(dp));
    //int ps = st[0]-'0' + st[1]-'0';
    cout<<findWays(0,2,5)%mod<<endl;

  //  cout<<findWays(2,1,1)<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)solve();
}