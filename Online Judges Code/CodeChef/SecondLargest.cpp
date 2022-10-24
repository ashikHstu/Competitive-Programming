#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int ar[4];
   for(int i=0;i<3;i++)cin>>ar[i];
   sort(ar,ar+3);
   cout<<ar[1]<<endl;
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

