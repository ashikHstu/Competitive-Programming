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

/// File In
#define READ(f)              freopen(f,  "r" ,stdin)
#define WRITE(f)             freopen(f,  "w" ,stdout)

const int mod = 1e9 + 7;
const int maxn=100005;
int n,k;
int ar[maxn];
int res[maxn];

int findColor(int i)
{
    if(res[i]!=-1)return res[i];
    int findFirst=i;
    int minPos=i-k+1;
    minPos=max(0,minPos);
    for(int j=i;j>i-k && j>=0;j--)
    {
        if(res[j]==-1)
        {
            

            
            findFirst=j;
        
        }
        else {
            if(res[j]>=minPos)
            {
                for(int k=j;k<=i;k++)res[k]=res[j];
                return res[i];
            }

           // cout<<"res["<<j<<"] : "<<res[j]<<endl;
           // cout<<"minPos : "<<minPos<<endl;
            break;
        }
    }

   // cout<<"find first : "<<findFirst<<endl;
   // if(findFirst==i+1)findF

    for(int j=findFirst;j<=i;j++)
    {
        res[j]=findFirst;
    }

    return res[i];

}


void solve()
{
    cin>>n>>k;
    vector<int>ar(n);
    for(int i=0;i<n;i++)
    {
      cin>>ar[i];
     
    }
   // sort(all(ar));
    memset(res,-1,sizeof(res));
    int mainRes[n+3];
    
    for(int i=0;i<n;i++)
    {
      cout<<findColor(ar[i])<<" ";
        
    }cout<<endl;
    
    //for(int i=0;i<n;i++)cout<<mainRes[i]<<" ";cout<<endl;


}

int main()
{
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
