#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++)
    {
        int l,r;cin>>l>>r;
        vec.push_back({l,r});
    }

    sort(vec.begin(),vec.end(),[](pair<int,int>&p1,pair<int,int>&p2){
         return p1.second<p2.second;
         });


    ll res=0;
    ll now=-1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            now=vec[i].second;
            res++;
            continue;
        }
        if(vec[i].first >now+d-1)
        {
            now=vec[i].second;
            res++;
        }
    }


    cout<<res<<endl;

    return 0;
}
