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


ll dp[SIZ];
ll inv[SIZ];

ll power(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=(res*a)%mod;

        n>>=1;
        a=(a*a)%mod;
    }
    return res;
}

int chValue(char ch)
{
    if(ch>='a' && ch<='z')return ch-'a'+1;
    else if(ch>='A' && ch<='Z')return ch-'A'+27;
    else if(ch>='0' && ch<='9')return ch-'0'+53;
}

void init(string st)
{
    ll p=67;
    ll p_power=1;
    inv[0]=1;

    dp[0]=(chValue(st[0]));
    for(int i=1;i<st.size();i++)
    {
        char ch=st[i];
        p_power=(p_power*p)%mod;
        inv[i]=power(p_power,mod-2);

        dp[i]=(dp[i-1]+chValue(st[i])*p_power)%mod;

    }

}

ll subStringHash(int L,int R)
{
    ll res=dp[R];
    if(L>0)res-=dp[L-1];
    res=(res*inv[L])%mod;

    return res;
}


ll dp2[SIZ];
ll inv2[SIZ];

void init2(string st)
{
    ll p=67;
    ll p_power=1;
    inv2[0]=1;

    dp2[0]=(chValue(st[0]));
    for(int i=1;i<st.size();i++)
    {
        char ch=st[i];
        p_power=(p_power*p)%mod;
        inv2[i]=power(p_power,mod-2);

        dp2[i]=(dp2[i-1]+chValue(st[i])*p_power)%mod;

    }

}

ll subStringHash2(int L,int R)
{
    ll res=dp2[R];
    if(L>0)res-=dp2[L-1];
    res=(res*inv2[L])%mod;

    return res;
}




void findRes(string st)
{
    string inv_st=st;
    reverse(all(inv_st));
    init(st);
    init2(inv_st);
    int n=st.size();




    for(int i=0;i<n;i++)
        {
            int sz=(n-i+1);
            sz/=2;
            int v1=subStringHash(i,i+sz-1);
            int v2=subStringHash2(0,sz-1);


//
//            cout<<"sz : "<<sz<<endl;
//            cout<<"value of v1 : "<<v1<<endl;
//            cout<<"value of v2 : "<<v2<<endl;
            if(v1==v2)
            {
                for(int j=i-1;j>=0;j--)st.pb(st[j]);

               // cout<<"res : ";
            cout<<st<<endl;
            break;
            }

            if(i==n-1)
            {
                cout<<"dhet!, pai na\n";
            }

        }




}

void solve()
{
     string st;

     while(cin>>st)
     {
         findRes(st);
     }

     return;
}
int main()
{
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}


/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/



