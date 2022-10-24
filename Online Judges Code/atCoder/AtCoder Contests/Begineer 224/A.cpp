#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void solve(int kase)
{
    string st;
    cin>>st;
    int len=st.size();
    if(st[len-1]=='r')cout<<"er\n";
    else cout<<"ist"<<endl;
}


int main()
{

    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve(i);
    }

    return 0;
}

