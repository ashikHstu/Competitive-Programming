#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string st;
    cin>>st;
    vector<int>zero;
    int len=st.size();
    int z=0;
    for(int i=0;i<len;i++)
    {
        if(st[i]=='0')
        {
            z++;
        }
        else {
            if(z>0)zero.push_back(z);
            z=0;

        }
    }
    if(z>0)zero.push_back(z);

    if(zero.size()==0)cout<<"0\n";
   else if(zero.size()==1)cout<<"1\n";
   else cout<<"2\n";

}

int main()
{
    int tc;cin>>tc;while(tc--)solve();

    return 0;
}
