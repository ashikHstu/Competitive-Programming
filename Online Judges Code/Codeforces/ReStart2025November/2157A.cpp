#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ct[109]={0};
    for(int i=0;i<n;i++) ct[a[i]]++;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(ct[a[i]]>0)
        {
            if(ct[a[i]]>a[i]){
                ans+=(ct[a[i]]-a[i]);
                ct[a[i]]=a[i];
            }
            else if(ct[a[i]]<a[i]){
                ans+=ct[a[i]];
                ct[a[i]]=0;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }
}