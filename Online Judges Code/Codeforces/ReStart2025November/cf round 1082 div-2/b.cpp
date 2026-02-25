#include <bits/stdc++.h>
using namespace std;
string st;
    int n;
int dp[200005][2][2];
bool isPossible(int id,int b,int e){
    if(id==n)return true;
    if(dp[id][b][e]!=-1)return dp[id][b][e];

    if(st[id]=='a')
    {
        if(b==1)return dp[id][b][e]=isPossible(id+1,0,e);
        else if(e==1)return dp[id][b][e]=isPossible(id+1,b,0);
        else return dp[id][b][e]=false;
    }
    if(st[id]=='b')
    {
        if(b==0)return dp[id][b][e]=isPossible(id+1,1,e);
        else if(e==0)return dp[id][b][e]=isPossible(id+1,b,1);
        else return dp[id][b][e]=false;
    }
    else {
        return dp[id][b][e]= (isPossible(id+1,(b^1),e) || isPossible(id+1,b,(e^1)));
    }
}

void solve()
{
    cin>>n;
    cin>>st;
    memset(dp,-1,sizeof(dp));
    int bv=0;
    if(n%2==1)bv=1;
    if(isPossible(0,1,bv))cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}