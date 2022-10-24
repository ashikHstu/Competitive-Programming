#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    string st;cin>>st;
    int n=st.size();
    int r=0,g=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(st[i]=='R')
        {
            if(r==0){
                cout<<"NO\n";
                return;
            }
        }
        if(st[i]=='G' && g==0){
            cout<<"NO\n";
            return;
        }
        if(st[i]=='B' && b==0)
        {
                        cout<<"NO\n";
            return;
        }

        if(st[i]=='r')r++;
        if(st[i]=='g')g++;
        if(st[i]=='b')b++;

    }


    cout<<"YES\n";
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
