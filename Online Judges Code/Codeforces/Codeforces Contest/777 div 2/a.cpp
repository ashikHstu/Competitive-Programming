#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void solve()
{
    int n;cin>>n;
    int start;
    if((n-1)%3==0)
    {
        start=1;
    }
    else start=2;

    while(n>0)
    {
        cout<<start;n-=start;
        if(start==1)start=2;
        else start=1;
    }cout<<endl;

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

