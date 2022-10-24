#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353

ll sum(ll n)
{
    ll n2=n+1;

    if(n%2==0)n/=2;
    else n2/=2;

    n%=mod;
    n2%=mod;
    return (n*n2)%mod;

}

int numberOfDigit(ll n)
{
    return log10(n)+1;
}


int main()
{
    ll n;cin>>n;
    int l=numberOfDigit(n);
    //cout<<"number of digit : "<<l<<endl;
    ll rem=0,ml=9;
    ll res=0;
    for(int i=1;i<l;i++)
    {

        rem=rem*10+9;
        res+=(sum(ml));
        res%=mod;


        ml*=10;

       // cout<<"inner res  at "<<i<<" , : "<<res<<endl;
    }

    n-=rem;


    res+=(sum(n));
    res%=mod;

    cout<<res<<endl;

}
