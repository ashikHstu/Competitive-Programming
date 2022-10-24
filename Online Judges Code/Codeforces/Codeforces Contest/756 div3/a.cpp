#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string st;
    cin>>st;
    int len=st.size();
    if(st[len-1]%2==0)
    {
        cout<<"0\n";
    }
    else if(st[0]%2==0)
    {
        cout<<"1\n";
    }
    else {
        for(int i=0;i<len;i++)
        {
            if(st[i]%2==0){
                cout<<"2\n";
                return;
            }
        }
        cout<<"-1\n";
    }
}


int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}
