#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    int sq=sqrt(n);
    int res=0;
set<int>s;
   int ct[n+2]={0};
    for(int i=1; i<=sq; i++)
    {
        for(int j=i+1; j<=sq; j++)
        {
            if(i*i+j*j<=n)
            {

                if(__gcd(i,j)==1 && (i%2==0 || j%2==0))
                {
                    res++;

                }
                 int mx=i*i+j*j;
                int mx2=2*i*j;
                int mx3=j*j-i*i;
                for(int cr=1;;cr++)
                {

                    if(mx*cr>n || mx2*cr>n || mx3*cr>n)break;
                    ct[mx*cr]=1;
                    ct[mx2*cr]=1;
                    ct[mx3*cr]=1;
                }


            }
        }
    }

   // cout<<"s.size : "<<s.size()<<endl;
    int bad=0;
    for(int i=1;i<=n;i++)if(ct[i]==0)bad++;


    cout<<res<<" "<<bad<<endl;
}

int main()
{
    int n;
    while(cin>>n)
        solve(n);

    return 0;
}
