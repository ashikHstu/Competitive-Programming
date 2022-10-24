#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n,m;cin>>n>>m;
    vector<int>ar(m+1);
    int res=0;
    for(int i=0;i<m;i++)
    {
        cin>>ar[i];
        for(int j=0;j<i;j++)
        {
            if(ar[j]<ar[i])res++;
        }
    }

    cout<<res<<endl;

}



int main()
{

    int tc;
    cin>>tc;
    while(tc--)
        solve();

    return 0;
}

