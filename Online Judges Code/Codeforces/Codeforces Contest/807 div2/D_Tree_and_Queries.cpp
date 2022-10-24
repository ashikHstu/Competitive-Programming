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

const int maxN=100001;
const int BLK=700;
vector<int>ar[maxN];
int S[maxN],T[maxN],FT[2*maxN],col[maxN];
int nodeF[maxN],eleF[maxN],FF[maxN],bucket[maxN];
int ans[maxN],n;
int timer;

struct query{
    int l,r,idx,k;
};
query Q[maxN];

void dfs(int node,int par)
{
    S[node]=timer;
    FT[timer]=node;
    timer++;

    for(int child:ar[node])
    {
        if(child!=par)
        {
            dfs(child,node);
        }
    }

    T[node]=timer;
    FT[timer]=node;
    timer++;


}

int getBlock(int idx)
{
    return (idx+BLK-1)/BLK;
}


void add(int idx)
{
    int node=FT[idx];
    int c=col[node];
    nodeF[node]++;
    if(nodeF[node]==2)
    {
        eleF[c]++;
        FF[eleF[c]]++;
        bucket[getBlock(eleF[c])]++;
        FF[eleF[c]-1]--;
        bucket[getBlock(eleF[c]-1)]--;
    }
}


void remove(int idx)
{
    int node=FT[idx];
    int c=col[node];
    nodeF[node]--;
    if(nodeF[node]==1)
    {
        eleF[c]--;
        FF[eleF[c]]++;
        bucket[getBlock(eleF[c])]++;
        
        FF[eleF[c]+1]--;
        bucket[getBlock(eleF[c]+1)]--;
        
    }
}


bool comp(query a,query b)
{
    int x=a.l/BLK;
    int y=b.l/BLK;
    if(x!=y)
    return x<y;

    if(x%2)
    {
        return a.r<b.r;
    }
    else return a.r>b.r;
}


int getAns(int k,int n)
{
    int res=0;
    int LB=getBlock(k);
    int RB=getBlock(n);
    
    if(LB==RB)
    {
        for(int i=k;i<=n;i++)res+=FF[i];
    }
    else {
        for(int i=k;i<=LB*BLK;i++)
        res+=FF[i];

        for(int i=LB+1;i<RB;i++)
        res+=bucket[i];

        for(int i=RB*BLK+1;i<=n;i++)
        res+=FF[i];
    }

    return res;
}


void solve()
{
    timer=1;
    int q,a,b,k;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>col[i];

    }

    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        ar[a].pb(b);ar[b].pb(a);
    }
     
     dfs(1,-1);
     
     for(int i=1;i<=q;i++)
     {
        cin>>a>>k;
        Q[i].l=S[a];
        Q[i].r=T[a];
        Q[i].k=k;
        Q[i].idx=i;
     }

     sort(Q+1,Q+q+1,comp);

     int ML=1,MR=0;
     for(int i=1;i<=q;i++)
     {
        int L=Q[i].l;
        int R=Q[i].r;
        int idx=Q[i].idx;
        k=Q[i].k;
        while(MR<R)
        {
               MR++;
               add(MR);
        }

        while(ML>L)
        {
            ML--;
            add(ML);
        }
        
        while(MR>R)
        {
            remove(MR);
            MR--;
        }

        while(ML<L)
        {
            remove(ML);
            ML++;
        }
      ans[idx]=getAns(k,n);
     }


    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;

}

int main()
{
    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


