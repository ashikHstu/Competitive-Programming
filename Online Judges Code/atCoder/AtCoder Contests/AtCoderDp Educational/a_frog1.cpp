#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
ll ar[200005];
ll dp[200005];
ll jumpFrog(int cur)
{
    if(cur==n-1)return 0;
    if(dp[cur]!=-1)return dp[cur];
    ll r1=-1,r2=-1;
    r1=jumpFrog(cur+1)+(abs(ar[cur]-ar[cur+1]));
    if(cur+2<n)r2=jumpFrog(cur+2)+(abs(ar[cur+2]-ar[cur]));

    if(r2==-1)return dp[cur]=r1;
    else return dp[cur]=min(r1,r2);

}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i];

    //cout<<"res : ";
    cout<<jumpFrog(0)<<endl;


}
