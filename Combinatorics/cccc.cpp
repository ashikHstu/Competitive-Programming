#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;cin>>n>>m;
    int ar[n+2][m+2];
    int minar[n+2][m+2],maxar[n+2][m+2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
            minar[i][j]=ar[i][j];
            maxar[i][j]=ar[i][j];
            if(i-1>=0 && j-1>=0)
            {
                minar[i][j]+=(min(minar[i-1][j],minar[i][j-1]));
                maxar[i][j]+=(max(maxar[i-1][j],maxar[i][j-1]));
            }
            else if(i-1>=0)
            {
                minar[i][j]+=minar[i-1][j];
                maxar[i][j]+=maxar[i-1][j];
            }
            else if(j-1>=0)
            {
                minar[i][j]+=minar[i][j-1];
                maxar[i][j]+=maxar[i][j-1];
            }
        }
    }

    if((n+m-1)%2!=0)
    {
        cout<<"NO\n";
        return;
    }
    if(minar[n-1][m-1]>0 || maxar[n-1][m-1]<0)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;


}


int main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}
