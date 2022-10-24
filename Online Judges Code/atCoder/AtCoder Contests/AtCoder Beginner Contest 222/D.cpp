#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int n;cin>>n;
    int m= 998244353;
    int ar[n+2],b[n+2];
    int r=1;
    for(int i=0;i<n;i++)cin>>ar[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)
    {
        int v=b[i]-ar[i]+1;

        r*=v;
        r%= 998244353;
    }

    cout<<r<<endl;
}

