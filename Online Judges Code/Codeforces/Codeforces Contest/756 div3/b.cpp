#include <bits/stdc++.h>
using namespace std;
void solve()
{
   long long int a,b;cin>>a>>b;
   long long int total=a+b;
   long long int r1=total/4;

   long long int res=min(a,b);
   res=min(res,r1);
   cout<<res<<endl;
}


int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}
