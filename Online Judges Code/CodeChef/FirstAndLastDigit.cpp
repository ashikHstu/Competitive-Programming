#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   string st;cin>>st;
   cout<<st[0]+st[st.size()-1]-'0'-'0'<<endl;
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
