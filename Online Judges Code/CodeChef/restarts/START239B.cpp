#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int &v:vec)cin>>v;
    
    int res=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(vec[i]==vec[j])
            {
                res=min(res,i+(n-(j+1)));
                break;
            }
        }
    }
    if(res==INT_MAX)cout<<"-1\n";
    else cout<<res<<endl;
   

}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}