#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<long long int>ev,od;
    for(int i=0;i<n;i++)
    {
        int v;cin>>v;
        if(v&1)od.push_back(v);
        else ev.push_back(v);
    }

    sort(od.begin(),od.end());
    sort(ev.begin(),ev.end());

    int olen=od.size();
    int elen=ev.size();
    int m=min(olen,elen);
    olen-=m;
    elen-=m;
    long long int res=0;

    for(int i=0;i<olen-1;i++)res+=od[i];
    for(int i=0;i<elen-1;i++)res+=ev[i];

    cout<<res<<endl;

}
