#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define SZ 10006
int phi[SZ+4];
void euler_phi_precompute()
{
    phi[0]=0;
    phi[1]=1;
    for(int i=2;i<=SZ;i++)
        phi[i]=i;

    for(int i=2;i<=SZ;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=SZ;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}

void solve()
{
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)sum+=phi[i];

    int res=0;
    for(int i=1;i<=n;i++)
    {
        res+=(phi[i]*sum);
    }

    cout<<res<<endl;


}

int32_t main()
{
    euler_phi_precompute();

    int tc;cin>>tc;while(tc--)solve();
}
