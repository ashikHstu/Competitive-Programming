#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
struct data
{
    int l,r,ind;
    data(int _l,int _r,int _ind)
    {
        l=_l;r=_r;ind=_ind;
    }

    bool operator <(const data &d)const
    {
        if(l==d.l)return r<d.r;
        return l<d.l;
    }
};

int n,mod[200005],dp[200005][4];

int fun(int cur,int m)
{
    if(cur==0){
        if(m==2)return 1;
        else return 0;
    }
    if(dp[cur][m]!=-1)return dp[cur][m];

    dp[cur][m]=0;
    for(int i=0;i<3;i++)
    {
        dp[cur][m]+=(fun(cur-1,(m+i)%3)*mod[i])%MOD;
    }

    return dp[cur][m]%MOD;



}

void solve()
{
    int l,r;
    cin>>n>>l>>r;
    mod[0]=mod[1]=mod[2]=(r-l+1)/3;
    if((r-l+1)%3==1)mod[l%3]++;
    else if((r-l+1)%3==2)mod[r%3]++;

    memset(dp,-1,sizeof(dp));

    cout<<fun(n,2)<<endl;

}
int main()
{
    int tc=1;//cin>>tc;
    for(int i=1;i<=tc;i++)solve();


    return 0;
}
