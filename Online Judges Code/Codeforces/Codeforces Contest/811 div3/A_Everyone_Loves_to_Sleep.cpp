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

pair<int,int>t(int h1,int m1,int h2,int m2)
{
    int m,h;
    if(m2<m1){
        m=m2+60-m1;
        h2--;
    }
    else {
        m=m2-m1;
    }
   if(h2<h1)
   {
    h=24-h1+h2;
   }
   else {
    h=h2-h1;
   }

   return {h,m};

}

void solve()
{
    int n,h,m;
    cin>>n>>h>>m;

    pair<int,int>res={244,232};
    
    for(int i=0;i<n;i++)
    {
        int h1,m1;
        cin>>h1>>m1;
        pair<int,int>cp=t(h,m,h1,m1);
        
        if(cp.first<res.first)
        res=cp;
        else if(cp.first==res.first && cp.second<res.second)res=cp;

    }

    cout<<res.first<<" "<<res.second<<endl;


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


