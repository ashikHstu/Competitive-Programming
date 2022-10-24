#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n,k;
    cin>>n>>k;
    int ct=n/k;
    int cnt[k+2]={0};

    for(int i=0;i<n;i++)
    {
        int vv;cin>>vv;
        vv=vv%k;
        cnt[vv]++;
    }

    ll res=0;
    for(int i=0;i<k;i++)
    {
        if(cnt[i]>ct){
            ll ex=(cnt[i]-ct);
            res+=ex;
            cnt[i]=ct;
            cnt[i+1]+=(ex);

        }
    }

    if(cnt[k]>0){
            cnt[0]+=cnt[k];
    cnt[k]=0;

       for(int i=0;i<k;i++)
    {
        if(cnt[i]>ct){
            ll ex=(cnt[i]-ct);
            res+=ex;
            cnt[i]=ct;
            cnt[i+1]+=(ex);

        }
    }
    }


    cout<<res<<endl;



}


int main()
{
    int q;
   // cin>>q;
    q=1;
    for(int i=1;i<=q;i++)
    {
        solve();
    }

    return 0;
}
