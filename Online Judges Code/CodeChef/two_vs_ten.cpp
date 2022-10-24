#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int n;cin>>n;
   if(n%10==0)cout<<"0\n";
   else if(n%5==0)cout<<"1\n";
   else cout<<"-1\n";
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

