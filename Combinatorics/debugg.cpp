#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;cin>>n;
    ll b[n+2];
    ll c[n+2]={0};
    ll sum=0;
    ll res[n+2]={0};
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        sum+=b[i];
    }
    ll k=sum/n;
    int pointer=0;
    for(int i=n-1;i>=0;i--)
    {
        int cur_n=i+1;

        if(b[i]>=cur_n)
        {
            res[i]=1;
           for(int j=i;j>=i-k+1;j--)b[j]--;
           k--;

        }
    }

    for(int i=0;i<n;i++)cout<<res[i]<<" ";cout<<endl;



}

int main()
{
    int tc;cin>>tc;
    for(int i=0;i<tc;i++)
    {
        solve();
    }

    return 0;
}


/**

Input :
1
21
0 0 3 2 9 6 15 16 17 9 20 10 21 21 21 6 5 4 3 21 1


Output :
0 0 1 0 1 0 1 1 1 0 1 0 1 1 1 0 0 0 0 1 0

*/

