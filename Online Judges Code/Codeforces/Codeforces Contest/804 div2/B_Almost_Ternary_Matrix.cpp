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

void printS(string st)
{
    for(char ch:st)
    {
        cout<<ch<<" ";
    }cout<<endl;
}

void solve()
{
   int n,m;cin>>n>>m;
   string st1,st2;
   st1.pb('0');
   st2.pb('1');
   
    if(m==2)
    {
        st1.pb('1');
        st2.pb('0');
       
    }
else {
int new_m=m-2;
   new_m=new_m/2;
   int endAt=0;
   for(int i=0;i<new_m;i++)
   {
      if(i%2==0)
      {
        st1.pb('1');
        st1.pb('1');

        st2.pb('0');
      st2.pb('0');
      endAt=1;
      }
      else {
          st1.pb('0');
          st1.pb('0');

          st2.pb('1');
        st2.pb('1');
        endAt=0;
      }
   }

if(endAt==0){
st1.pb('1');
   st2.pb('0');
}else {
st1.pb('0');
   st2.pb('1');
}
   
}
   

   if(n==2)
   {
    printS(st1);
    printS(st2);
    return ;
   }
    int endAt1=0;
   int new_n=n-2;
   new_n/=2;
   printS(st1);
   for(int i=0;i<new_n;i++)
   {
    if(i%2==0)
    {
        printS(st2);
        printS(st2);
        endAt1=1;
    }
    else {
        printS(st1);
        printS(st1);
        endAt1=0;
    }
   }
  if(endAt1)
   printS(st1);
   else 
   printS(st2);


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


