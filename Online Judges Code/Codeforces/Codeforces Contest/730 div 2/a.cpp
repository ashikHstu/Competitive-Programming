#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void solve()
{
   ll a,b;cin>>a>>b;
   if(a>b)swap(a,b);
   ll dif=b-a;

   if(a==b)
   {
       cout<<"0 0\n";
       return;
   }
   if(a==0)
   {
       cout<<b<<" 0"<<endl;
       return;
   }

   if(dif>=a)
   {
       ll res=min(a,dif-a);
       cout<<dif<<" "<<res<<endl;
       return;
   }
   ll d=a/dif;
   ll p1=d*dif;
   ll p2=(d+1)*dif;


   ll res=min(a-p1,p2-a);
   cout<<dif<<" "<<res<<endl;
   return;




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


