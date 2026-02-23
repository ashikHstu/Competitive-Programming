#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int>ar(n);
    for(int &v:ar)cin>>v;
    map<int,int>cnt;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cnt[ar[i]]++;
            res++;
            continue;
        }
        if(cnt[ar[i]-1]>0 && ar[i]-ar[i-1]<=1){
            cnt[ar[i]]++;
        }
        else{
            res++;
            cnt.clear();
            cnt[ar[i]]++;
        }
    }
    cout<<res<<endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}