#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long int

typedef tree<
int,
null_type,
greater_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;


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
   string st;
   cin>>st;
   ordered_set os[3];
   int b[n+2]={0};
   b[0]=n;
   os[n%3].insert(n);
   int cnt=n;
   int res=0;
   for(int i=1;i<=n;i++)
   {
       if(st[i-1]=='+')
       {
           cnt++;

       }
       else {
        cnt--;

       }
       b[i]=cnt;

       int r=os[cnt%3].order_of_key(cnt-1);

       res+=(r);
       os[cnt%3].insert(cnt);


   }


 //  cout<<"res : ";
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

