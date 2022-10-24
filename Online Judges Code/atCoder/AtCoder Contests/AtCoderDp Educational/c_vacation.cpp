#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
ll a[4][200005];
ll dp[4][200005];

ll MakeVacation(int restrict,int indx)
{
    if(indx==n)return 0;

    if(dp[restrict][indx]!=-1)return dp[restrict][indx];
    ll res=-1;
    for(int i=0;i<3;i++)
    {
        if(i==restrict)continue;

        if(res==-1)res=a[i][indx]+MakeVacation(i,indx+1);
        else res=max(res,a[i][indx]+MakeVacation(i,indx+1));

    }

    return dp[restrict][indx]=res;

}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        {cin>>a[0][i]>>a[1][i]>>a[2][i];

        }

    //cout<<"res : ";
    cout<<MakeVacation(3,0)<<endl;


}


