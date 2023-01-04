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

void solve(int kase)
{
   int r,c;
   cin>>r>>c;
   cout<<"Case #"<<kase<<":"<<endl;
   for(int i=0;i<=r*2;i++)
   {
       for(int j=0;j<=c*2;j++)
       {
           if(i<=1 && j<=1){
            cout<<".";continue;
           }

           if(i%2==0)
           {
               if(j%2==0)
               {
                   cout<<"+";
               }
               else {
                cout<<"-";
               }
           }
           else {
            if(j%2==0){
                cout<<"|";
            }
            else {
                cout<<".";
            }
           }

       }

       cout<<endl;
   }

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve(i);
    }

    return 0;
}


