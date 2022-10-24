#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    vector<pair<int,int>>vec;


    int n;cin>>n;
    int ar[n+2];

    for(int i=0;i<n;i++){
        int v;cin>>v;
        vec.push_back({v,i});
    }

    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());


    vector<int>indx;
    for(int i=1;i<=n;i++)
    {
        indx.push_back(i);
        indx.push_back((i*(-1)));
    }

     int res=0;
     int resAr[n+3];
     for(int i=0;i<n;i++)
     {
         res+=(2*(vec[i].first)*(abs(indx[i])));
         resAr[vec[i].second]=indx[i];
     }

   // cout<<" res : ";
    cout<<res<<endl;

    cout<<"0 ";
    for(int i=0;i<n;i++)
    {
        cout<<resAr[i]<<" ";
    }cout<<endl;



}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--)solve();


    return 0;
}

