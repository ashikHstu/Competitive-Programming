#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int l,r;cin>>l>>r;
    if(r&1)r--;
    cout<<(r/2)<<" "<<r<<endl;
}


int main()
{
    int tc;cin>>tc;
    while(tc--)
        solve();


    return 0;
}
