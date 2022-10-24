/** Success is not a destination success is a journey */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sz 3004
double dp[sz][sz];
double p[sz];
int n;


int main()
{

    cin>>n;
    for(int i=0;i<n;i++)cin>>p[i];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)dp[i][j]=0;
    }

   dp[0][0]=1;
    for(int i=1 ;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=1;
                continue;
            }
            else if(j==0)
            {
                dp[i][j]=(1.0-p[i-1])*dp[i-1][j];
            }
            else {
                dp[i][j]=(p[i-1]*dp[i-1][j-1])+(1.0-p[i-1])*dp[i-1][j];
            }
        }
    }

    double res=0.0;
    for(int i=n/2+1;i<=n;i++)res+=dp[n][i];

   // cout<<res<<endl;

    printf("%.10f\n",res);




    return 0;
}
