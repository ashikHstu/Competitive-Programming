#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxP[1000006];

void generateMaxP()
{
int n=1000000;
    for(ll i=2;i<=n;i++)
    {
        for(ll j=i,p=1;j<=n;j=j*i)
        {
            if(maxP[j]==0)
            {
                maxP[j]=p;
            }
              p++;

        }
    }
}


void solve(int kase)
{
    ll a,b;cin>>a>>b;


    ll res=maxP[a]*b;

    printf("Case #%d: %lld\n",kase,res);
}


int main()
{
    generateMaxP();
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve(i);
    }

    return 0;
}
