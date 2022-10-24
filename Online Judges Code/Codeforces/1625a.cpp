#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,l;cin>>n>>l;
    int ar[33]={0};
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<l;j++)
        {
            if(x&(1<<j))
            {
                ar[j]++;
            }
        }
    }

    //l--;
    int res=0;
    for(int i=0;i<l;i++)
    {
        int ex=n-ar[i];
        if(ex<=ar[i])
        {

            res+=(1<<i);

        }
    }


    //cout<<"res : ";
    cout<<res<<endl;

}

int main()
{
    int tc;cin>>tc;
    for(int i=0;i<tc;i++)
    {
        solve();
    }
}
