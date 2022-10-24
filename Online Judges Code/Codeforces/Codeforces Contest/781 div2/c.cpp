#include <bits/stdc++.h>
using namespace std;
//#define ll long long int
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

vector<int>g[sz];
int visited[sz],dis[sz];
int n;

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=1;
    dis[src]=0;
    int ct[n+2]={0};
    int mxLevel=0;
    while(!q.empty())
    {
        int parent=q.front();
        ct[dis[parent]]++;
        mxLevel=max(mxLevel,dis[parent]);
        q.pop();
        for(int child:g[parent])
        {
            if(!visited[child])
            {
                visited[child]=1;
                dis[child]=dis[parent]+1;
                q.push(child);
            }
        }
    }

    vector<int>distances;
    int totalDis=0;
    for(int i=0;i<=mxLevel;i++)
    {
        distances.pb(ct[i]);

    }
    sort(all(distances));
    int res=0;
    for(int i=0;i<=mxLevel;i++)
    {
        res++;
        distances[i]=distances[i]-i-1;
        if(distances[i]<0)distances[i]=0;

    }

    sort(all(distances));
    reverse(all(distances));
    int removed=0;
    for(int i=0;i<mxLevel;i++)
    {
        if(distances[i]<=removed){
            break;
        }
        distances[i+1]-=removed;
        int need=distances[i]-distances[i+1];
         int act_need=need*(i+1);
        if(act_need<distances[i+1])
        {
            res+=act_need;
            distances[i]=distances[i+1];
        removed+=act_need;
        distances[i+1]-=act_need;
        }
        else {
                res+=distances[i+1];
            int m2=act_need-distances[i+1];
            int exR=CEIL(m2,(i+2));
            res+=exR;
           // cout<<"res : ";
            cout<<res<<endl;
            return;
        }
    }

    if(distances[mxLevel]>0)
    {
        res+=(CEIL((distances[mxLevel]*mxLevel),(mxLevel+1)));

    }

   // cout<<"res : ";
    cout<<res<<endl;

}



void solve()
{
    int v;
    cin>>n;

    for(int i=0;i<=n+1;i++)
    {
        g[i].clear();
        visited[i]=0;
        dis[i]=-1;
    }

   for(int i=2;i<=n;i++)
   {
       cin>>v;
       g[v].push_back(i);
       //g[i].pb(v);
   }

   if(n==2)
   {

   }
   bfs(1);
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


