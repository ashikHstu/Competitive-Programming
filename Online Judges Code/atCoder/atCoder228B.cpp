#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;cin>>n>>x;

    int ar[n+2];

    for(int i=1;i<=n;i++)cin>>ar[i];


    int mark[n+2]={0};

    int res=0;
    while(mark[x]==0)
    {
        res++;
        mark[x]=1;
        x=ar[x];

    }

    cout<<res<<endl;
    return 0;

}
