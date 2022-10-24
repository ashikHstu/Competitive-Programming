#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n,T;

int ar[50];

ll AK(int ind,int t)
{
    if(ind>=n)return t;
    ll r1=-1,r2=-1;
    if(t+ar[ind]<=T)
    {
        r1=t+ar[ind]+AK(i+1,t+ar[ind]);
    }
    r2=t+AK(i+1,t);
    if(r1==-1)dp[ind]=


}
int main()
{

   cin>>n>>T;
   for(int i=0;i<n;i++)cin>>ar[i];




}
