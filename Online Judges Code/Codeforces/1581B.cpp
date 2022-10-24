#include <bits/stdc++.h>
using namespace std;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

long long int sum(long long int n)
{
    long long int r=n*(n+1);

    r/=2;
    return r;
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    k-=2;

    if(m<n-1)
    {
        no;
        return;
    }

    long long int rr=sum(n-1);

    if(rr<m)
    {
        no;
        return;
    }

    if(n==1)
    {
        (k>=0)?yes:no;
        return;

    }



    if(rr==m)
    {
        (k>=1)?yes:no;
        return;
    }

    (k>=2)?yes:no;


}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}
