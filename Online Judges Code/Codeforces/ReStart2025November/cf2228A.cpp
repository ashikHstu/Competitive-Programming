#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int &v:vec)cin>>v;
    
    int cnt[3]={0};
    for(int v:vec)cnt[v%3]++;

    cout<<cnt[0]+min(cnt[1],cnt[2])<<endl;
   

}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}