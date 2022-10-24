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


//#define mod        1000000007
#define ll         long long int
#define SIZ        1000005
#define win   cout<<"Kilani\n"
#define lose   cout<<"Ayoub\n"

//#define mod1 1000000007
//#define mod2 1000000009
//#define base 27





int add(int a,int b,int mod)
{
    int res=(a+b)%mod;
    if(res<0)res+=mod;
    return res;
}

int mult(int a,int b,int mod)
{
   // cout<<"a and b : "<<a<<", "<<b<<endl;
    int res=(a*1LL*b)%mod;
   // cout<<"res : "<<res<<endl;
    if(res<0)res+=mod;
    return res;
}
int power(int a,int b,int mod)
{
    int res=1;
    while(b)
    {
        if(b%2==1)
        {
            res=mult(res,a,mod);
        }
        a=mult(a,a,mod);
        b/=2;
    }
    return res;
}

const int N=1e5+5;
const int mod=1e9+7;
const int base=10;
int pw[N];
ll inv[N];
int Hash[N];
void preCal()
{
    pw[0]=1;
    for(int i=1;i<N;i++)
    {
        pw[i]=mult(pw[i-1],base,mod);
       // cout<<pw[i]<<" ";
    }

    inv[1] = 1;
for(int i = 2; i < 100005; ++i)
    inv[i] = mod - (mod/i) * inv[mod%i] % mod;
}

int chValue(char ch)
{
    if(ch>='a' && ch<='z')return ch-'a'+1;
    else if(ch>='A' && ch<='Z')return ch-'A'+27;
    else if(ch>='0' && ch<='9')return ch-'0'+53;
}
void build(string s)
{
    int n=s.length();

    for(int i=0;i<n;i++)
    {
        int sv=chValue(s[i]);
        int hv=0;
        if(i!=0)hv=Hash[i-1];
        int mlt=mult(pw[i],sv,mod);
       // cout<<"hv and mlt : "<<hv<<", "<<mlt<<endl;
        Hash[i]=add(hv,mlt,mod);
    }
//    cout<<"hash value in build : "<<endl;
//    for(int i=0;i<n;i++)cout<<Hash[i]<<" ";cout<<endl;
}

int getHash(int x,int y)
{
    ll res=add(Hash[y],(x==0)?0:-Hash[x-1],mod);
    res=mult(res,(x==0)?1:inv[x],mod);
    return res;
}



ll Hash2[N];


void build2(string s)
{
    int n=s.length();

    for(int i=0;i<n;i++)
    {
        int sv=chValue(s[i]);
        int hv=0;
        if(i!=0)hv=Hash2[i-1];
        int mlt=mult(pw[i],sv,mod);

        Hash2[i]=add(hv,mlt,mod);
    }
//    cout<<"reveres hash : ";
//    for(int i=0;i<n;i++)
//        cout<<Hash2[i]<<" ";cout<<endl;


}

int getHash2(int x,int y)
{
    ll res=add(Hash2[y],(x==0)?0:-Hash2[x-1],mod);
    res=mult(res,(x==0)?1:inv[x+1],mod);
    return res;
}


//
//ll basePowerM1[100005];
//ll basePowerM2[100005];
//void baseCal()
//{
//    basePowerM1[0]=basePowerM2[0]=1;
//    for(int i=1;i<=100002;i++)
//    {
//        basePowerM1[i]=(basePowerM1[i-1]*base)%mod1;
//        basePowerM2[i]=(basePowerM2[i-1]*base)%mod2;
//    }
//}
//
//ll value(char ch)
//{
//    if(ch<='z' && ch>='a')
//    return ch-'a'+1;
//    else return (26+1+ch-'A');
//}

void checkValues(){
    cout<<"checking inv : "<<endl;

    cout<<"inv of 1 : "<<inv[1]<<endl;
    for(int i=1;i<=100;i++)
    {
        cout<<mult(i,inv[i],mod)<<endl;
    }

}

void solve()
{

    string st1;


    while(cin>>st1)
    {
        string st2=st1;
        reverse(all(st2));
        build(st1);
        build2(st2);
        int n=st1.size();
        cout<<"hash of st1 : "<<Hash[n-1]<<endl;
        cout<<"hash of st2 : "<<Hash2[n-1]<<endl;

         cout<<"prefix hash of st1 : "<<endl;
        for(int i=0;i<st2.size();i++)cout<<Hash[i]<<" ";cout<<endl;

        cout<<"prefix hash of st2 : "<<endl;
        for(int i=0;i<st2.size();i++)cout<<Hash2[i]<<" ";cout<<endl;


        cout<<"hash checking : ";

         for(int i=0;i<n;i++)
            {
                cout<<getHash(i,i+1)<<" "<<getHash2(n-i-1,n-i)<<endl;
            }
            cout<<"last 2 checking : "<<endl;
            cout<<getHash(1,2)<<" "<<getHash2(1,2)<<endl;
            cout<<"inv if 1 : "<<inv[1]<<endl;

        for(int i=0;i<n;i++)
        {
            int sz=(n-i+1);
            sz/=2;
            int v1=getHash(i,i+sz-1);
            int v2=getHash2(0,sz-1);



            cout<<"sz : "<<sz<<endl;
            cout<<"value of v1 : "<<v1<<endl;
            cout<<"value of v2 : "<<v2<<endl;
            if(v1==v2)
            {
                for(int j=i-1;j>=0;j--)st1.pb(st1[j]);

                cout<<"res : ";
            cout<<st1<<endl;
            break;
            }

            if(i==n-1)
            {
                cout<<"baaal, pai na\n";
            }

        }
    }














//    while(cin>>st1)
//    {
//
//        string st2=st1;
//        reverse(all(st2));
//        int n=st1.size();
//        ll s1Hashm1[n+2],s1Hashm2[n+2];
//        ll s2Hashm1[n+2],s2Hashm2[n+2];
//        s1Hashm1[0]=s1Hashm2[0]=0;
//        s2Hashm1[0]=s2Hashm2[0]=0;
//
//        for(int i=1;i<=n;i++)
//        {
//            s1Hashm1[i]=(s1Hashm1[i-1]*base+(value(st1[i-1])))%mod1;
//            s1Hashm2[i]=(s1Hashm2[i-1]*base+(value(st1[i-1])))%mod2;
//
//            s2Hashm1[i]=(s2Hashm1[i-1]*base+(value(st2[i-1])))%mod1;
//            s2Hashm2[i]=(s2Hashm2[i-1]*base+(value(st2[i-1])))%mod2;
//
//
////             cout<<s1Hashm1[i]<<" "<<s1Hashm2[i]<<endl;
////        cout<<s2Hashm1[i]<<" "<<s2Hashm2[i]<<endl;
//
//        }
//
//
////cout<<"final : "<<endl;
////        cout<<s1Hashm1[n]<<" "<<s1Hashm2[n]<<endl;
////        cout<<s2Hashm1[n]<<" "<<s2Hashm2[n]<<endl;
////
////        cout<<"hash value array : "<<endl;
////        for(int i=0;i<=n;i++)cout<<s1Hashm1[i]<<" ";cout<<endl;
////
////        cout<<"pow array : "<<endl;
////        for(int i=0;i<7;i++)cout<<basePowerM1[i]<<" ";cout<<endl;
//
//
//
//        for(int i=1;i<=n;i++)
//        {
//             ll msz=n-i+1;
//             ll sz=msz/2;
//
//
//             ll s1HashdifM1=(s1Hashm1[i+sz-1]-(s1Hashm1[i-1]*basePowerM1[sz])%mod1)%mod1;
//             ll s1HashdifM2=(s1Hashm2[i+sz-1]-(s1Hashm2[i-1]*basePowerM2[sz])%mod2)%mod2;
//
//               ll s2HashdifM1=s2Hashm1[sz];
//               ll s2HashdifM2=s2Hashm2[sz];
//
////               ll s2HashdifM1=(s2Hashm1[i+sz-1]-(s2Hashm1[i-1]*basePowerM1[sz])%mod1)%mod1;
////               ll s2HashdifM2=(s2Hashm2[i+sz-1]-(s2Hashm2[i-1]*basePowerM2[sz])%mod2)%mod2;
//
//
////           cout<<"sz of substr : "<<sz<<endl;
////               cout<<st1.substr(i-1,sz)<<" ";
////               cout<<st2.substr(0,sz)<<endl;
////               cout<<s1HashdifM1<<" "<<s2HashdifM1<<endl;
////               cout<<s1HashdifM2<<" "<<s2HashdifM2<<endl;
//
//
//
//               if((s1HashdifM1==s2HashdifM1 && s1HashdifM2==s2HashdifM2) || msz==1)
//               {
//                  // cout<<"match found at pos : "<<i<<endl;
//                      for(int j=i-2;j>=0;j--)st1.pb(st1[j]);
//
//                      cout<<st1<<endl;
//                      break;
//               }
//
//        }




//    }

}
int main()
{
    //baseCal();
    preCal();
   checkValues();
    int tc=1;
   // cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}


/**
Input :
abacadeacafacae

OUtput :

*/

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/


