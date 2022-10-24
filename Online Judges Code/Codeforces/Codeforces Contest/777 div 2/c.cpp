#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

struct fourPoint
{
    int a,b,c,d;
    fourPoint(int _a,int _b,int _c,int _d)
    {
        a=_a;
        b=_b;
        c=_c;
        d=_d;
    }
};

void solve()
{
    int n,m;cin>>n>>m;

   int ar[n+2][m+2];
   int cur[n+2][m+2]={0};
   for(int i=1;i<=n;i++)
   {
       string st;cin>>st;
       for(int j=1;j<=m;j++)
       {
           if(st[j-1]=='0')ar[i][j]=0;
           else ar[i][j]=1;
       }
   }

   if(ar[1][1]==1)
   {
       cout<<"-1\n";
       return;
   }

   for(int i=0;i<n;i++)
   {
       ar[i][0]=1;
       ar[i][m+1]=1;
   }
   for(int i=0;i<m;i++)
   {
       ar[0][i]=1;
       ar[n+1][i]=1;
   }


   vector<fourPoint>vec;

   for(int i=n;i>=1;i--)
   {
       for(int j=m;j>=1;j--)
       {
           if(ar[i][j]==1)
           {
               if(i>1){
                vec.pb(fourPoint(i-1,j,i,j));
               }
               else
               {
                   vec.pb(fourPoint(i,j-1,i,j));
               }

           }
       }
   }
//cout<<"res : ";
   int len=vec.size();
   cout<<len<<endl;
   for(fourPoint fp:vec)
   {
       cout<<fp.a<<" "<<fp.b<<" "<<fp.c<<" "<<fp.d<<endl;
   }


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


