#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;

    long long int mod=1000000007;
    long long int v=16;
    long long int res=6;
    for(int i=2;i<=k;i++)
    {
        res*=v;
        res%=mod;
        v=(v*v);
        v%=mod;
    }

    cout<<res<<endl;
}
