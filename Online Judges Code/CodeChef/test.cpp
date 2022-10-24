#include <bits/stdc++.h>
using namespace std;

bool ok=false;
int status[10002][102];
int n,a[102],b[102],x;
int findIf(int v,int cur)
{
    if(v>10000)
        return 0;
    if(cur==n && v==x)
        return 1;
    if(cur>=n)
        return 0;

    if(status[v][cur]!=-1)
        return status[v][cur];

    return status[v][cur]=findIf(v+a[cur],cur+1)|| findIf(v+b[cur],cur+1);
}


int main()
{

    memset(status,-1,sizeof(status));

    cin>>n>>x;

    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }

    if(findIf(0,0))
    {
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";

    return 0;
}
