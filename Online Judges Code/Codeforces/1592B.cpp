#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x;
    cin>>n>>x;
    int ar[n+2],srt[n+2];

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        srt[i]=ar[i];
    }

    sort(srt,srt+n);


    for(int i=n-x;i<x;i++)
    {
        if(srt[i]!=ar[i])
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}


int main()
{
    int tc;cin>>tc;
    while(tc--)solve();


    return 0;
}

