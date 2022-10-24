#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void solve(int kase)
{
   int w,h;cin>>w>>h;

   int ar[w+2][h+2];
   for(int i=0;i<w;i++)
   {
       for(int j=0;j<h;j++)
       {
           cin>>ar[i][j];
       }
   }


   bool yes=true;

   for(int i=0;i<w;i++)
   {
       for(int j=0;j<h;j++)
       {
           for(int ii=i;ii<w;ii++)
           {
               for(int jj=j;jj<h;jj++)
               {
                   if(ar[i][j]+ar[ii][jj]>ar[i][jj]+ar[ii][j]){

                       // cout<<i<<" "<<j<<" , "<<ii<<" "<<jj<<endl;

                    yes=false;
                    break;
                   }
               }
           }
       }
   }

   if(yes)cout<<"Yes\n";
   else cout<<"No\n";


}


int main()
{

    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve(i);
    }

    return 0;
}


