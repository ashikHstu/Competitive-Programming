#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mx=10000000000000;
ll a,n;
map<ll,ll>already;
ll numberOfDigit(int n)
{
    int ct=0;
    while(n>0)
    {
        ct++;
        n/=10;
    }
    return ct;
}


ll moveLastToFirst(ll n)
{
    ll ld=n%10;
    n/=10;
    ll p=1;
    ll nd=numberOfDigit(n);
    for(int i=1;i<=nd;i++)p*=10;

    ld*=p;
    ld+=n;
    return ld;

}

ll dp[2000006];

ll findSol(ll cur)
{



    if(cur>n)return mx;
    if(cur==n)return 0;

//already[cur]=1;

    if(dp[cur]!=-1)return dp[cur];

     ll res1=-1,res2=-1;

    ll change1=cur*a;
    if(change1<=n && already[change1]==0)
    {
       // cout<<"cur , change v : "<<cur<<" , "<<change1<<endl;
        already[change1]=1;
        res1=1+findSol(change1);

    }
    if(cur%10 !=0 && cur>10 )
    {
        ll nv=moveLastToFirst(cur);
        //cout<<"new v : "<<nv<<endl;
        if(already[nv]==0)res2=1+findSol(nv);
        already[nv]=1;

    }
    ll res;
    if(res1==-1 && res2==-1)res=mx;
    else if(res1==-1)res=res2;
    else if(res2==-1)res=res1;
    else res=min(res1,res2);
//cout<<"cur : "<<cur<<endl;
    return dp[cur]=res;
}

int main()
{
    memset(dp,-1,sizeof(dp));
//dp[1]=0;
    cin>>a>>n;

    ll res=findSol(1);


    cout<<"res : "<<res<<endl;
    if(res>=mx)cout<<"-1\n";
    else cout<<res<<endl;

    for(int i=0;i<=20;i++)
    {
        cout<<dp[i]<<" ";
        if(i%10==0)cout<<endl;
    }

}
