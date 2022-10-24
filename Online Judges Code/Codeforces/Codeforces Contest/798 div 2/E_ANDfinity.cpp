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

int parent[2005];
void makeParent(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}

int findParent(int i)
{
    if(parent[i]==i)return i;
    else return parent[i]=findParent(parent[i]);
}


void solve()
{
    int n;
    cin>>n;
    vector<int>vec[35];
    int ar[n+2];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        for(int j=0;j<32;j++)
        {
            if(ar[i]&(1<<j))
            {
                vec[j].pb(i);
            }
        }
    }

    makeParent(n);

    for(int i=0;i<33;i++)
    {
        int len=vec[i].size();
        for(int j=1;j<len;j++)
        {
            int u=findParent(vec[i][0]);
            int v=findParent(vec[i][j]);
            if(u!=v)
            {
                parent[u]=v;

            }
        }
    }


    int oddParent=-1;
    map<int,int>mp;
    vector<int>inc_need;
    
    for(int i=0;i<n;i++)
    {
          int cp=findParent(i);
          if(ar[i]%2==1)
          {
            oddParent=cp;
          }
          if(mp[cp]==0)
          {
            inc_need.pb(cp);

          }
          mp[cp]++;
    }

    int rr=inc_need.size();
    if(oddParent!=-1)rr=rr-1;

    cout<<rr<<endl;
    for(int i=0;i<inc_need.size();i++)
    {
        if(oddParent!=inc_need[i])
        {
            int indd=inc_need[i];
            ar[indd]++;
        }
    }

    for(int i=0;i<n;i++)cout<<ar[i]<<" ";cout<<endl;
    



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


