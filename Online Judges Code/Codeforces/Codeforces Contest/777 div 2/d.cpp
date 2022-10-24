#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int notPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return i;
    }
    return 0;
}

void solve()
{
   ll x,d;cin>>x>>d;

   int ct=0;
   while(x%d==0)
   {
       ct++;
       x/=d;
   }

   if(ct==1)
   {
       cout<<"NO\n";
       return;
   }
   if(notPrime(x))
   {
       cout<<"YES\n";
       return;
   }
   if(notPrime(d) && d==notPrime(d)*notPrime(d) && x==notPrime(d) && ct==3)
   {
       cout<<"NO\n";
       return;
   }
   if(notPrime(d) && ct>2)
   {
       cout<<"YES\n";
       return;
   }
   cout<<"NO\n";
   return;


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


