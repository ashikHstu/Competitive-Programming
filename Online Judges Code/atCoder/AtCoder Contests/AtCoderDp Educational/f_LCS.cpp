#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string s,t;
int dp[3000+2][3000+2];


int lcs(int n,int m)
{

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;

            else if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][m];
}

string printLCS(int i,int j)
{

    string res;
    // int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            res.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j-1]<dp[i-1][j])
            i--;
        else
            j--;

    }

    reverse(res.begin(),res.end());

    return res;

}


int main()
{
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int l=lcs(n,m);
    //cout<<"size : "<<lcs(n,m)<<endl;
    cout<<printLCS(n,m)<<endl;
    return 0;
}

