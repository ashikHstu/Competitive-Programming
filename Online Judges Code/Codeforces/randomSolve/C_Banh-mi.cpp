/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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
#define NUMLEN(Num)        to_string(Num).size()

#define POSL(x,v)          (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v)          (upper_bound(x.begin(),x.end(),v)-x.begin())
#define min3(a,b,c)        min(a,min(b,c))
#define min4(a,b,c,d)      min(a,min(b,min(c,d)))
#define max3(a,b,c)        max(a,max(b,c))
#define max4(a,b,c,d)      max(a,max(b,max(c,d)))
#define ABS(x)             ((x)<0?-(x):(x))
#define pb                 push_back
#define nl                 printf("\n")

///vector
#define Lower_bound(vec,value) lower_bound(vec.begin(),vec.end(),value)
#define Upper_bound(vec,value) upper_bound(vec.begin(),vec.end(),value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))

const int mod = 1e9 + 7;

inline ll bigMod(ll a,ll b,ll mod)
{
    if(b==0)return 1%mod;
    ll ans = 1;
    while (b)
    {
        if (b&1) ans = (1ll * ans * a) % mod;
        a = (1ll * a * a) % mod;
        b /= 2;
    }
    return ans;
}

const int maxn=100005;
int n,q;
int ar[maxn];
ll TwoPow[maxn];

void findPow()
{
    TwoPow[0]=0;
    TwoPow[1]=1;
   ll cnt=1;
    for(int i=2;i<=maxn;i++)
    {
        cnt*=2;
        TwoPow[i]=cnt;
        TwoPow[i]+=TwoPow[i-1];
        cnt%=mod;
        TwoPow[i]%=mod;
    }

}

int findSolve(int l,int r)
{
    int one=ar[r]-ar[l-1];
    int zero=(r-l+1)-one;
     
     ll res=TwoPow[one];
     res+=(res*TwoPow[zero]);
   
   res%=mod;
   return res;

}

void solve()
{
    cin>>n>>q;
    string st;
    cin>>st;
    ar[0]=0;
    for(int i=1;i<=n;i++)
    {
      if(st[i-1]=='1')ar[i]=1;
      else ar[i]=0;
      ar[i]+=ar[i-1];
    }

    for(int i=0;i<q;i++)
    {
        int l,r;cin>>l>>r;
        int res=findSolve(l,r);
        cout<<res<<endl;
    }
    
}

int main()
{
    findPow();
    int tc=1;
   // cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

 
 /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
