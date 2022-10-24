#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int n;cin>>n;
    int x,y;cin>>x>>y;
    int d1=max(x-1,y-1);
    int d2=max(n-x,n-y);
    if(d1<=d2)cout<<"White\n";
    else cout<<"Black\n";

    return 0;
}
