#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++)
    {
        int s,e;cin>>s>>e;
        vec.push_back({e,s});
    }

    sort(vec.begin(),vec.end());

    int res=0;
    int soFar=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i].second>=soFar){
            res++;
            soFar=vec[i].first;
        }
    }

   // cout<<"res : ";
    cout<<res<<endl;
}

int main()
{
    int tc;cin>>tc;
    for(int i=1;i<=tc;i++){
        solve();
    }

    return 0;
}
