/** Success is not a destination, success is a journey */

#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
*/




#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define TIME              clock()*1.0/CLOCKS_PER_SEC
#define pi                acos(-1.0)
///Library
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
#define for0(i,n)           for(int i=0;i<n;i++)
#define for1(i,n)           for(int i=1;i<=n;i++)

#define POSL(x,v)          (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v)          (upper_bound(x.begin(),x.end(),v)-x.begin())
#define min3(a,b,c)        min(a,min(b,c))
#define min4(a,b,c,d)      min(a,min(b,min(c,d)))
#define max3(a,b,c)        max(a,max(b,c))
#define max4(a,b,c,d)      max(a,max(b,max(c,d)))
#define ABS(x)             ((x)<0?-(x):(x))
#define pb                 push_back
#define nl                 printf("\n")
#define endl               '\n'
#define oh cout<<"Problem ta ki?  "<<endl;

/**------- Char Chk----------*/
inline bool isLower(char ch)
{
    return (ch>='a' && ch<='z');
}
inline bool isUpper(char ch)
{
    return (ch>='A' && ch<='Z');
}
inline bool isDigit(char ch)
{
    return (ch>='0' && ch<='9');
}
inline bool isVowel(char ch)
{
    ch=tolower(ch);
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/




///vector
#define Lower_bound(vec,value) lower_bound(vec.begin(),vec.end(),value)
#define Upper_bound(vec,value) upper_bound(vec.begin(),vec.end(),value)
#define minElement(x) *min_element(all(x))

/// File In
#define READ(f)              freopen(f".in","r" ,stdin)
#define WRITE(f)             freopen(f".out","w" ,stdout)


#define mod        1000000007
#define ll         long long int
#define SIZ        1000005
#define win   cout<<"Kilani\n"
#define lose   cout<<"Ayoub\n"

struct s
{
    ll l,r,m;
    s(ll _l,ll _r,ll _m)
    {
        l=_l;r=_r;m=_m;
    }


    bool operator <(const s &d)const
    {
        return m>d.m;
    }
};

int ar[200000+2];
int n;
vector<s>res;

void findSol(int l,int r)
{
    if(r<l)
    {
        res.pb({n,0,0});
        return;
    }


    //cout<<"l , r : "<<l<<", "<<r<<endl;

    ll mul=1;
    ll lm=l-1;
    ll p=0;
    ll mp=0;
    for(int i=l;i<=r;i++)
    {
        if(abs(ar[i])==2)
        {
            p++;
        }
        if(ar[i]<0)mul*=(-1);
        if(mul==1)
        {
            lm=i;
            mp=p;
        }
    }

    //cout<<"r1 : "<<mp<<endl;

    res.pb({l,n-lm-1,mp});

        mul=1;
     p=0;
    mp=0;
     lm=r+1;
    for(int i=r;i>=l;i--)
    {
        if(abs(ar[i])==2)
        {
            p++;
        }
        if(ar[i]<0)mul*=(-1);
        if(mul==1)
        {
            lm=i;
            mp=p;
        }
    }

  //  cout<<"r2 : "<<mp<<endl;
    res.pb({lm,n-r-1,mp});

}


void solve()
{
  cin>>n;

res.clear();

  for(int i=0;i<n;i++)
  {
      cin>>ar[i];
  }
  int cur=0;

  for(int i=0;i<n;i++)
  {
      if(ar[i]==0)
      {
          findSol(cur,i-1);
          cur=i+1;
      }
  }

  findSol(cur,n-1);
  sort(all(res));



  cout<<res[0].l<<" "<<res[0].r<<endl;


}
int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}


/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/


/** input :
1
4
0 -2 1 2

*/


