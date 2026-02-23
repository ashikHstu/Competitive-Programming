#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    int sum=0;
    int nonZeroCount=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0) nonZeroCount++;
        sum+=a[i];
    }
    if(n-1<=(sum-nonZeroCount))
    {
        cout<<nonZeroCount<<endl;
        return;
    }
    int baki=n-1-(sum-nonZeroCount);
    cout<<nonZeroCount - baki<<endl;
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