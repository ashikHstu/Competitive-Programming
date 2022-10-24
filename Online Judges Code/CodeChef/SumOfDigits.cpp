#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int sumOfdigit(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}


void solve()
{
   int n;cin>>n;
   cout<<sumOfdigit(n)<<endl;
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
