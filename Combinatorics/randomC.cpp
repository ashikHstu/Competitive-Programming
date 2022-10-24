#include <bits/stdc++.h>
using namespace std;

vector<int>zp;
 int n;

bool isPossible(int k)
{
    if(k>=zp.size()-2)return true;
//cout<<"is calling?"<<endl;
    for(int i=0;i<=zp.size()-k-2;i++)
    {
        int left=zp[i]+1;
        int right=zp[i+k+1]-1;
        int insideOne;
        if(left>right)insideOne=0;
        else insideOne=right-left-k+1;


        int totalOne=n-(zp.size()-2);

        int rem=totalOne-insideOne;

        if(rem<=k)return true;

    }

    return false;


}


void solve()
{

    string st;cin>>st;
     n=st.size();
    zp.clear();
    zp.push_back(-1);
    for(int i=0;i<n;i++)
    {
        if(st[i]=='0')zp.push_back(i);
    }
    zp.push_back(n);

    int left=0,right=n;
    int res=n;
    while(left<=right)
    {
        int k=(left+right)/2;
        if(isPossible(k))
        {
            res=k;
            right=k-1;
        }
        else {
            left=k+1;
        }
    }


   // cout<<"res : ";
    cout<<res<<endl;


}


int main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }
}
