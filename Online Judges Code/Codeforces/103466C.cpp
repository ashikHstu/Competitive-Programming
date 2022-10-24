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
//----------------------Graph Moves----------------
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
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


int g[1002][1002];
 int n,m;
map<pair<int,int>,bool>visited;
map<pair<int,int>,int>level;
 bool isValid(int i,int j)
 {
     if(i<1 || i>n || j<1 || j>m)return false;
     return true;
 }

bool isValidStart(int i,int j)
{
    for(int ii=0;ii<4;ii++)
    {
        int ni=i+fx[ii];
        int nj=j+fy[ii];
        if(isValid(ni,nj))
        {
            if(g[ni][nj]+1==g[i][j])return false;
        }
    }
    return true;
}





int main()
{

   cin>>n>>m;


   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           cin>>g[i][j];
       }
   }

   int res=0;
   vector<pair<int,int>>startP;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(isValidStart(i,j))
           {
               startP.pb({i,j});
           }
       }
   }


   int totalS=startP.size();
   for(int i=0;i<totalS;i++)
   {
       int nsi=startP[i].first;
       int nsj=startP[i].second;

       queue<pair<int,int>>q;
       q.push({nsi,nsj});

       level[{nsi,nsj}]=0;

    cout<<"koibar? "<<g[nsi][nsj]<<endl;
       while(!q.empty())
       {
           int in_qi=q.front().first;
           int in_qj=q.front().second;
           q.pop();
           bool added=false;
           for(int i=0;i<4;i++)
           {
               int npi=in_qi+fx[i];
               int npj=in_qj+fy[i];
               if(isValid(npi,npj) && level[{npi,npj}]==0)
               {
                   if(g[npi][npj]==g[in_qi][in_qj]+1)
                   {
                       q.push({npi,npj});
                       level[{npi,npj}]=level[{in_qi,in_qj}]+1;

                       cout<<"add hocche?"<<endl;
                       added=true;
                   }
               }
           }
           cout<<endl<<endl;

           if(added==false)
           {
               if(level[{in_qi,in_qj}]>=3)
               {
                   res++;
               }
           }

       }

       cout<<"added from point : "<<res<<endl;
       level.clear();


   }


   cout<<"res : ";
   cout<<res<<endl;




}


/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/



