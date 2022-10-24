#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,h;
    cin>>n>>h;

    int ar[n+2];
    for(int i=0;i<n;i++)cin>>ar[i];

    sort(ar,ar+n);

    int together=(ar[n-1]+ar[n-2]);
    int div=(h/together);
    int ex=h%together;
    long long int res=div*2;
    if(ex>ar[n-1])res+=2;
    else if(ex>0) res+=1;

   cout<<res<<endl;
}


int main()
{
    int tc;cin>>tc;
    while(tc--)solve();


    return 0;
}
