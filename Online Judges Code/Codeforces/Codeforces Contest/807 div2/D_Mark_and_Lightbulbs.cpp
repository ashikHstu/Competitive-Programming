#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
  int n;cin>>n;
  string st1,st2;
  cin>>st1;
  cin>>st2;
  if(st1[0]!=st2[0] || st1[n-1]!=st2[n-1])
  {
    cout<<"-1"<<endl;
    return;
  }

  vector<int>a,b;
  for(int i=0;i<n-1;i++)
  {
     if(st1[i]!=st1[i+1])
     a.pb(i);
  }
  
  for(int i=0;i<n-1;i++)
  {
    if(st2[i]!=st2[i+1])
    b.pb(i);
  }


  if(a.size()!=b.size())
  {
    cout<<"-1\n";
    return;
  }
  
  int res=0;
  for(int i=0;i<a.size();i++)
  {
    res+=(abs(a[i]-b[i]));
  }

  cout<<res<<endl;



}

int32_t main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


