#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int n;cin>>n;
   int ar[n+2];
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
   }

   sort(ar,ar+n);


   int d=ar[1]-ar[0];
   for(int i=2;i<n;i++)
   {
       d=min(d,ar[i]-ar[i-1]);
   }

   cout<<d<<endl;


}

int main()
{
    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

