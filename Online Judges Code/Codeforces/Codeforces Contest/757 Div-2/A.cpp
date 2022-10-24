#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n,l,r,k;cin>>n>>l>>r>>k;


    int ar[n+2];
    for(int i=0;i<n;i++)
        cin>>ar[i];


    sort(ar,ar+n);


    int ct=0;
    for(int i=0;i<n;i++)
    {
        if(ar[i]>= l && ar[i]<=r && ar[i]<=k)
        {
           // cout<<"added i : "<<i<<endl;
            k-=ar[i];
            ct++;
        }
    }

    //cout<<"res : ";
    cout<<ct<<endl;


}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();


    return 0;
}
