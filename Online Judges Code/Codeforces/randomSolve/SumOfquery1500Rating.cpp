#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;cin>>n>>q;
   long long int ar[n+2];
    for(int i=0;i<n;i++)cin>>ar[i];
    long long int query[n+2]={0};
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        query[l]++;
        query[r+1]--;
    }
    for(int i=1;i<=n+1;i++)
    {
        query[i]+=query[i-1];

    }
    sort(query,query+n+1);
    reverse(query,query+n+1);
    sort(ar,ar+n);
    reverse(ar,ar+n);
    long long int res=0;
    for(int i=0;i<n;i++)
    {

        res+=(ar[i]*query[i]);
    }

    cout<<res<<endl;

}
