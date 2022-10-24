#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isLucky(ll n)
{
    if(n<0)n*=(-1);
    while(n>0)
    {
        int ld=n%10;
        n/=10;
        if(ld==8)return true;
    }

    return false;
}


int main()
{
    ll n;cin>>n;
    ll i=1;
    while(!isLucky(n+i))
    {
        i++;
    }

    cout<<i<<endl;

    return 0;
}
