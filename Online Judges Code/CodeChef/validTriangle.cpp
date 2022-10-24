#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int a,b,c;cin>>a>>b>>c;
   if(a+b+c==180)cout<<"YES\n";
   else cout<<"NO\n";
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

