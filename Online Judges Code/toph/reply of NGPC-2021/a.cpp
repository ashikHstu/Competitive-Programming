#include <bits/stdc++.h>
using namespace std;
void solve()
{
    double w,d;
    cin>>w>>d;
    w=w-d;
    int dd=w;
    if(dd%2==0)
    {
        cout<<dd/2<<endl;
        return;
    }
    double res=w/2;
    printf("%.4f\n",res);

    return;
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}
