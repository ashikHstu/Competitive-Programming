#include <bits/stdc++.h>
using namespace std;
#define int long long int
int forK[4033];

void FindAllK()
{
    for(int i=0;i<=1000;i++)
    {
        forK[i]=INT_MAX;
    }
    forK[1]=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int dv=i/j;
            if(i+dv<=1000)
                forK[i+dv]=min(forK[i]+1,forK[i+dv]);
        }
    }


}

void solve()
{
    int n,k;cin>>n>>k;

     int b[n+2],c[n+2];
     int newk=0;
     for(int i=0;i<n;i++)
     {
         cin>>b[i];
         b[i]=forK[b[i]];
         newk+=b[i];
     }

     k=min(k,newk);

     for(int i=0;i<n;i++)cin>>c[i];

     int ex=0;
//     for(int i=0;i<n;i++)
//     {
//         if(b[i]==0)
//         {
//             ex+=c[i];
//         }
//     }

int dp[n+1][k+1];
for(int i=1;i<=n;i++)dp[i][0]=0;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==0){
                dp[i][j]=0;
                continue;
            }
            if(j-b[i-1]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i-1]]+c[i-1]);
            else dp[i][j]=dp[i-1][j];

        }
    }

  //  cout<<"res : ";
    cout<<dp[n][k]+ex<<endl;
}

int32_t main()
{
    FindAllK();
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

/**
Input :
1
22 91
52 45 12 86 97 52 35 54 86 86 42 11 67 5 100 72 37 50 38 57 6 63
39 7 8 28 94 52 98 72 6 29 45 25 5 14 16 83 86 53 61 65 97 8
*/
