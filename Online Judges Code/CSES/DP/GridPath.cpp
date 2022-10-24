#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;cin>>n;
    string grid[n+2];

    for(int i=0;i<n;i++)cin>>grid[i];

    if(grid[n-1][n-1]=='*')
    {
        cout<<"0\n";
        return 0;
    }

    int table[n+2][n+2];
    memset(table,0,sizeof(table));


    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(i==n-1 && j==n-1){
                table[i][j]=1;
            }
            else if(grid[i][j]=='*'){
                table[i][j]=0;
            }
            else {
                table[i][j]=(table[i+1][j]+table[i][j+1])%mod;
            }
        }
    }


    cout<<table[0][0]<<endl;

    return 0;
}
