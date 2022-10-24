#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n,x;
   cin>>n>>x;
   int ar[n+2];
   for(int i=0;i<n;i++)cin>>ar[i];

   ll fixLMax[n+3];
   for(int i=0;i<=n;i++)
   {
       fixLMax[i]=-1000000000;
   }

   for(int i=0;i<n;i++)
   {
       ll psum=0;
       for(int j=i;j<n;j++)
       {
           psum+=ar[j];
           fixLMax[j-i+1]=max(fixLMax[j-i+1],psum);

       }
   }



   ll rangeMax[n+4];
   rangeMax[n+1]=-100000000;
   fixLMax[0]=0;
   for(int i=n;i>=0;i--)rangeMax[i]=max(rangeMax[i+1],fixLMax[i]);



    ll res=0;
  for(ll i=0;i<=n;i++)
  {
      ll temp=rangeMax[i]+(i*x);
      res=max(res,temp);
      cout<<res<<" ";
  }cout<<endl;

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}
