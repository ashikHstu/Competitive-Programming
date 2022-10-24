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
const int maxn=200005;
vector<int>pos[maxn];
int n,q;
int cur,curI;
int ar[maxn];

int findResult(int ind,int k)
{
    int res=0;
    if(pos[ind].size()==0)return 0;

    int Lower=Lower_bound(pos[ind],k)-pos[ind].begin();
    if(pos[ind][0]>k){
        res=0;
    }
    else if(pos[ind][pos[ind].size()-1]<=k)
    {
         res=pos[ind].size();
    }
    else {
        res=Lower;
        if(pos[ind][Lower]==k)res++;
    }

    if(ind==curI && k>n-1)
    {
        res+=(k-n+1);
    }

    return res;

}

void solve()
{
    cin>>n>>q;
    for(int i=0;i<=n;i++)pos[i].clear();
    for(int i=1;i<=n;i++)
    {
      cin>>ar[i];
    }

     cur=ar[1];
     curI=1;
    for(int i=2;i<=n;i++)
    {
        if(cur>ar[i])pos[curI].pb(i-1);
        else {
            cur=ar[i];
            curI=i;
            pos[curI].pb(i-1);
        }
    }

    for(int i=1;i<=q;i++)
    {
        int ind,k;cin>>ind>>k;
        int findR=findResult(ind,k);
        cout<<findR<<endl;
    }
    



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

 
 /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
