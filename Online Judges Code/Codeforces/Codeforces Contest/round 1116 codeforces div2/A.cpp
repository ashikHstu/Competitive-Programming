#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int>vec;
    for(int i=0;i<3;i++)
    {
        int v;cin>>v;
        vec.push_back(v);
    }
    sort(vec.begin(),vec.end());
    cout<<min(vec[2],vec[0]+vec[1])-vec[0]<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)solve();
}