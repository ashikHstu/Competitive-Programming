#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    int ar[n+2];
    for(int i=1;i<=n;i++)
        cin>>ar[i];

        if(n==1)
        {
            cout<<"0\n";
            return;
        }

    cout<<n-1<<endl;
    cout<<1<<" "<<n<<endl;
    if((ar[1]+ar[n])%2==0)ar[1]=ar[n];
    else ar[n]=ar[1];


    for(int i=2;i<n;i++)
    {
        if(ar[1]%2!=ar[i]%2)cout<<1<<" "<<i<<endl;
    }

    for(int i=2;i<n;i++)
    {
        if(ar[1]%2==ar[i]%2)cout<<i<<" "<<n<<endl;
    }

}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();


    return 0;
}
