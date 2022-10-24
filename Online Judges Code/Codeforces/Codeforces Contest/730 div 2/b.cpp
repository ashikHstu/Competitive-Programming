#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void solve()
{
   ll n;cin>>n;
   ll total=0;
   for(int i=0;i<n;i++)
   {
       int v;cin>>v;
       total+=v;
   }

   total=total%n;
   cout<<(total*(n-total))<<endl;
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


