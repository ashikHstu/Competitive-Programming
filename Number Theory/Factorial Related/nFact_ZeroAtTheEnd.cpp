
/// Problem link : https://www.spoj.com/problems/FCTRL/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin>>n;
    long long int d=5;

    long long int res=0;
    while(d<=n)
    {
        res+=(n/d);
        d*=5;
    }
    cout<<res<<endl;

}

int main()
{
    int tc;cin>>tc;

    while(tc--)
    {
        solve();
    }
}
