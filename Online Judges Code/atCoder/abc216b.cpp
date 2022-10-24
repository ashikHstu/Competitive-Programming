#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>mp;
    int n;cin>>n;
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        string mainS=s1+" "+s2;
 ;
        if(mp[mainS])ok=true;
        mp[mainS]++;
    }
    if(ok)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
