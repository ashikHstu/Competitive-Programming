#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n,k;
ll ar[200005];
ll dp[200005];
ll jumpFrog(int cur)
{
    if(cur==n-1)return 0;
    if(dp[cur]!=-1)return dp[cur];
    ll r1=-1,r2=-1;
    r1=jumpFrog(cur+1)+(abs(ar[cur]-ar[cur+1]));

    for(int i=cur+2;i<cur+k+1 && i<n;i++){
   r2=jumpFrog(i)+(abs(ar[i]-ar[cur]));
     r1=min(r1,r2);

    }

 return dp[cur]=r1;

}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>ar[i];

    //cout<<"res : ";
    cout<<jumpFrog(0)<<endl;


}

