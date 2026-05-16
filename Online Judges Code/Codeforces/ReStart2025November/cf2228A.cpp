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
    int res=cnt[0];
    int r2=min(cnt[1],cnt[2]);
    cnt[1]-=r2;
    cnt[2]-=r2;
    int r3=(cnt[1]/3) + (cnt[2]/3);
    cout<<res+r2+r3<<endl;
   

}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}