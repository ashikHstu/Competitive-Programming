#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void solve()
{
   int n,m;cin>>n>>m;

   int ar[n+2][m+2];
   for(int i=0;i<n;i++)
   {
       string st;cin>>st;
       for(int j=0;j<m;j++)
       {
           if(st[j]=='0')ar[i][j]=0;
           else ar[i][j]=1;
       }
   }



   for(int i=0;i<n-1;i++)
   {
       for(int j=0;j<m-1;j++)
       {
           int ct=0;
           if(ar[i][j]==1)ct++;
           if(ar[i+1][j]==1)ct++;
           if(ar[i][j+1]==1)ct++;
           if(ar[i+1][j+1]==1)ct++;
           if(ct==3){
            cout<<"NO\n";
            return;
           }
       }
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


