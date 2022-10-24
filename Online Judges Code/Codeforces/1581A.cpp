#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int fact(int n)
{
    int res=1;
    for(int i=2;i<=n;i++){
        res*=i;
        res%=mod;
    }
    return res;
}

void solve()
{
    int n;cin>>n;
   long long int res=1;
    for(long long int i=n*2-1;i>=n;i--)
    {
        res*=i;
        res%=mod;
    }
    for(long long int i=1;i<=n;i++)
       {

        res*=i;
        res%=mod;
       }
    cout<<res<<endl;
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}
