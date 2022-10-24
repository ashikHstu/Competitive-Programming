#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long int res=0;
    long long int ar[n+2];

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(i)
        {
            res=max(res,(ar[i]*ar[i-1]));
        }
    }

    cout<<res<<endl;
    return;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)solve();


    return 0;
}
