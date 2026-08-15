#include<bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int>vec(3);
    for(int &v:vec)cin>>v;
    sort(vec.begin(),vec.end());

    int r=min(abs(vec[1]-vec[0]),vec[2]-vec[1]);
    cout<<r<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)solve();
}