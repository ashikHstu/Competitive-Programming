#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define gcd(a,b)  __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
void solve()
{
   ll a,b;cin>>a>>b;
   ll g=gcd(a,b);
   if(g>1)
   {
       cout<<"0\n";
       return;
   }
   else if(gcd(a+1,b)>1 || gcd(a,b+1)>1)
   {
       cout<<"1\n";
   }
   else {
    cout<<"2\n";
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

