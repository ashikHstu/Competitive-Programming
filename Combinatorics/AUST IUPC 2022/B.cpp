#include <bits/stdc++.h>
using namespace std;
#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int
void solve()
{
   int n,k;cin>>n>>k;
   int ind[n+2];
   int ar[n+2];
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
       ind[ar[i]]=i+1;
   }


   ll prefix[n+2];
   prefix[0]=0;
   for(int i=1;i<=n;i++)
   {
       prefix[i]=prefix[i-1]+n-ind[i]+1;
   }

   for(int i=0;i<k;i++)
   {
      ll q;cin>>q;

       int indd=lower_bound(prefix,prefix+n,q)-prefix;
       if(q==prefix[indd]){
        cout<<ind[indd]<<" "<<n<<endl;
        continue;
       }
       else {

       indd--;
       q-=prefix[indd];
       indd++;
      // cout<<"the ind is : "<<indd<<endl;
      // cout<<"prefix[indd] : "<<prefix[indd]<<endl;
       cout<<ind[indd]<<" "<<ind[indd]+q<<endl;
       }

//       for(int i=1;i<=n;i++)
//       {
//           int cur=n-ind[i]+1;
//           if(cur<q)
//           {
//               q-=cur;
//               continue;
//           }
//           cout<<ind[i]<<" "<<ind[i]+q-1<<endl;
//           break;
//
//
//       }
   }



}

int main()
{
    FasterIO;
    int tc;scanf("%d",&tc);

    while(tc--)solve();


    return 0;
}

