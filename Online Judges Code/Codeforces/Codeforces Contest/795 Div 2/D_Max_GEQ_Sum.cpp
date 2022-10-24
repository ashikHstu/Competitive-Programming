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
#define sz 200005

int suffixTree[3*sz],prefixTree[3*sz];
int prefix[sz],suffix[sz];
int n;
int minusInf=-10000000000000000LL;
void buildPrefixTree(int node,int b,int e)
{
    if(b==e)
    {
        prefixTree[node]=prefix[b];
       return;
    }

    int mid=(b+e)/2;
    buildPrefixTree(node*2,b,mid);
    buildPrefixTree(node*2+1,mid+1,e);
    prefixTree[node]=max(prefixTree[node*2],prefixTree[node*2+1]);
}

void buildSuffixTree(int node, int b,int e)
{
  
    if(b==e)
    {
        suffixTree[node]=suffix[b];
        return;
    }
    int mid=(b+e)/2;
    buildSuffixTree(node*2,b,mid);
    buildSuffixTree(node*2+1,mid+1,e);

    suffixTree[node]=max(suffixTree[node*2],suffixTree[node*2+1]);
    
}

int querySuffix(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)return minusInf;
    if(b>=i && e<=j)return suffixTree[node];

    int mid=(b+e)/2;
    int r1=querySuffix(node*2,b,mid,i,j);
    int r2=querySuffix(node*2+1,mid+1,e,i,j);
    return max(r1,r2);
}

int queryPrefix(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)return minusInf;
    if(b>=i && e<=j)return prefixTree[node];
    int mid=(b+e)/2;
    int r1=queryPrefix(node*2,b,mid,i,j);
    int r2=queryPrefix(node*2+1,mid+1,e,i,j);

    return max(r1,r2);
}

void solve()
{
   int n;cin>>n;
   int ar[n+2];

   for(int i=1;i<=n;i++)
    {
        cin>>ar[i];

    }
    prefix[1]=ar[1];
    for(int i=2;i<=n;i++)prefix[i]=prefix[i-1]+ar[i];

    suffix[n]=ar[n];
    for(int i=n-1;i>0;i--)suffix[i]=suffix[i+1]+ar[i];
     

     buildPrefixTree(1,1,n);
     buildSuffixTree(1,1,n);

    vector<int>nextG(n+3,0),prevG(n+3,0);


    stack<int>stk;
    for(int i=1;i<=n;i++)
    {
        while(!stk.empty() && ar[stk.top()]<ar[i])
        {
           nextG[stk.top()]=i;
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty())stk.pop();


    for(int i=n;i>=1;i--)
    {
        while(!stk.empty() && ar[stk.top()]<ar[i])
        {
            prevG[stk.top()]=i;
            stk.pop();
        }
        stk.push(i);
    }

     
     for(int i=1;i<=n;i++)
     {
        int ngg=nextG[i];
        if(ngg==0)ngg=n+1;
        ngg--;
    
        int maxPrefix=queryPrefix(1,1,n,prevG[i]+1,i-1)-suffix[i];
        int maxSuffix=querySuffix(1,1,n,i+1,ngg)-prefix[i];
        if(max(maxPrefix,maxSuffix)>0)
        {
            cout<<"NO\n";
            return;
        }
     }


     cout<<"YES\n";



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


