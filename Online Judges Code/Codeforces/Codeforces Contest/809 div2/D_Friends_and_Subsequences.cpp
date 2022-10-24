#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define TIME              clock()*1.0/CLOCKS_PER_SEC
#define pi                acos(-1.0)
#define mem(a,b)           memset(a,b,sizeof(a))
#define all(a)             a.begin(),a.end()
#define Sort(x)            sort(x.begin(),x.end())
#define Reverse(x)         reverse(x.begin(),x.end())
#define SortA(ar,s)        sort(ar,ar+s)
#define SortD(ar,s)        sort(ar,ar+s,greater<int>())
#define gcd(a,b)           __gcd(a,b)
#define lcm(a,b)           (a*(b/gcd(a,b)))
#define sq(x)              (x)*(x)
#define CEIL(a,b)          ((a/b)+((a%b)!=0))





void solve()
{
    int n;
    cin>>n;
    ll ar[n+2],br[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>br[i];
    }

   ll res=0;
   deque<ll>mn,mx;
  // int j=1;
   for(int i=1,j=1;i<=n;i++)
   {
       

    while(!mx.empty() && ar[mx.back()]<=ar[i] )mx.pop_back();
     while(!mn.empty() && br[mn.back()]>=br[i])mn.pop_back();
    
    mx.push_back(i);
    mn.push_back(i);



    while(j<=i && ar[mx.front()]-br[mn.front()]>0)
    {
        j++;
        while(!mx.empty() && mx.front()<j)mx.pop_front();
        while (!mn.empty() && mn.front()<j)mn.pop_front();

      
      
        
    }



    if(!mx.empty() && !mn.empty() && ar[mx.front()]==br[mn.front()])
         res+=(min(mn.front(),mx.front())-j+1);

        //cout<<"temp res : "<<res<<endl;
       //     cout<<"value of J : "<<j<<endl;

     


   }

   cout<<res<<endl;

}

int main()
{
    int tc=1;
   // cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


