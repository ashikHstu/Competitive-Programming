#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;cin>>n>>k;
    string num;cin>>num;
    int res=0;
    for(int i=0;i<n-k+1;i++)
    {
        int temp=1;
        for(int j=i;j<i+k;j++)
        {
            temp*=(num[j]-'0');
        }
        res=max(res,temp);

    }

    cout<<res<<endl;
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}
