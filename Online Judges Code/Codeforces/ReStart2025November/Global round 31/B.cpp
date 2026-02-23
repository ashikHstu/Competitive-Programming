#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
   string a;
    string s="";
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(i==0)
        {
            s=a;
            continue;
        }
        string dekhi1=s+a;
        string dekhi2=a+s;
        if(dekhi1<dekhi2)
        {
            s=dekhi1;
        }
        else {
            s=dekhi2;
        }
    }
    cout<<s<<endl;
}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}