#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x,t;

    cin>>n>>x>>t;
    int res=x;
    set<int>s;
    while(true)
    {
        x=(x+t)%n;
        res=max(res,x);
        if(s.find(x)!=s.end())break;
        s.insert(x);
    }
    cout<<res<<endl;
   
}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}