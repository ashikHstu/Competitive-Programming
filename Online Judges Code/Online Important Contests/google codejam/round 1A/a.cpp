#include <bits/stdc++.h>
using namespace std;

void solve(int kase)
{
    string st;cin>>st;
    int n =st.size();
    int occ[n+2]={0};

    cout<<"Case #"<<kase<<": ";

    for(int i=n-1;i>0;i--)
    {
        if(st[i-1]<st[i])
        {
            int j=i-1;
            while(j>=0 && st[j]==st[i-1]){

            occ[j]=1;
            j--;
            }
            i=j+2;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<st[i];
        if(occ[i])cout<<st[i];
    }
    cout<<endl;

}

int main()
{

    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }

    return 0;
}
