#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPrime(ll n)
{
    ll sq=sqrt(n+1);
    if(n==1)return false;
    if(n==2 || n==3 || n==5 || n==7 || n==11 || n==13)return true;
    if(n%2==0 || n%3==0 || n%5==0 || n%7==0 || n%11==0 || n%13==0)return false;
    for(int i=17;i<=sq;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

void solve()
{
   int n;cin>>n;
   if(isPrime(n))
   {
       cout<<"yes\n";
   }
   else {
    cout<<"no\n";
   }

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

