#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    int ar[n+2];
    for(int i=0;i<n;i++)cin>>ar[i];


   int status[k+2]={0};
   status[0]=0;
   for(int i=1;i<=k;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(i-ar[j]>=0 && status[i-ar[j]]==0)
           {
               status[i]=1;
               break;
           }
       }
   }

//for(int i=0;i<=k;i++)cout<<status[i]<<" ";cout<<endl;

   if(status[k]==1)
    cout<<"First\n";
   else cout<<"Second\n";
}
