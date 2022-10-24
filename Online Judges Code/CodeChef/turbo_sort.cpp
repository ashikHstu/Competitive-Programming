#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int n;cin>>n;
   int ar[n+2];
   for(int i=0;i<n;i++)cin>>ar[i];
   sort(ar,ar+n);
   for(int i=0;i<n;i++)cout<<ar[i]<<endl;
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

