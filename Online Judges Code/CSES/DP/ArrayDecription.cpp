#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll n,m;
ll dp[100005][102];
int ar[100005];

ll decript(int ind,int v)
{
    if(v<=0 || v>m)return 0;

    if(ar[ind]!=0 && v!=ar[ind])return 0;

    if(ind==n-1)return 1;

    if(dp[ind][v]!=-1)return dp[ind][v];
    ll r=(decript(ind+1,v)+decript(ind+1,v-1)+decript(ind+1,v+1))%mod;


    return dp[ind][v]=r;

}

int main()
{
   memset(dp,-1,sizeof(dp));

   cin>>n>>m;
   for(int i=0;i<n;i++)cin>>ar[i];
    ll mainR=0;
   for(int i=1;i<=m;i++)
   {
        mainR=(mainR+decript(0,i))%mod;
   }

   //cout<<"res : ";
   cout<<mainR<<endl;

   return 0;
}
