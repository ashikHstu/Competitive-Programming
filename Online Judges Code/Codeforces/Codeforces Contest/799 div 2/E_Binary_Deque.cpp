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
     int n,k;cin>>n>>k;
     int st[n+2];
     for(int i=0;i<n;i++)cin>>st[i];
     int ct=0;
   //  cout<<"start"<<endl;
     vector<int>fromFront,fromBack;
     for(int i=0;i<n;i++)
     {
        if(st[i]==1)
        {
            ct++;
            fromFront.push_back(i+1);

        }
     }

       for(int i=n-1;i>=0;i--)
     {
        if(st[i]==1)
        {
            
            fromBack.push_back(n-i);

        }
     }

    if(ct<k)
    {
        cout<<"-1\n";
        return;
    }

    if(ct==k)
    {
        cout<<"0\n";
        return;
    }

    // for(int ii:fromFront)cout<<ii<<" ";
    // cout<<endl;
    // cout<<endl;
    // cout<<"TE\n";
  // for(int ii:fromBack)cout<<ii<<" ";

    int rmv=ct-k;
    int res=fromFront[rmv-1];
    for(int i=rmv-1;i>=0;i--)
    {
       int r1=fromFront[i];
       int ex=rmv-i-1;
       int r2=0;
       if(ex>0)
        r2=fromBack[ex-1];
         res=min(res,(r1+r2));
    }
    res=min(res,fromBack[rmv-1]);

    cout<<res<<endl;
   // cout<<"testCseDone"<<endl;

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


