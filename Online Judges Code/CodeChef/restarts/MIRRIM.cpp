#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int &v:vec)cin>>v;
    
    int h=n/2;
    for(int i=1;i<h;i++)
    {
        int j=n-i;
        if(vec[i]-vec[i-1]!=vec[j]-vec[j-1]){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}