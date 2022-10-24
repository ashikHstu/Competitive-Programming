#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int n;cin>>n;

   for(int i=n-1;i>=1;i--)
   {
       cout<<n<<" "<<i<<" ";
       for(int j=n-1;j>=1;j--)
       {
           if(j!=i)cout<<j<<" ";
       }
       cout<<endl;
   }

   cout<<n-1<<" "<<n<<" ";
   for(int i=n-2;i>=1;i--)
   {
       cout<<i<<" ";
   }cout<<endl;
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

