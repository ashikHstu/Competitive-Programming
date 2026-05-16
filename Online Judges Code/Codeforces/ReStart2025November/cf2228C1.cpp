#include <bits/stdc++.h>
using namespace std;
#define FasterIO           \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
int n;
long long a;
int d[2];
map<long long,long long>mp;
map<long long,int>isVisited;

long long findSol(long long cur)
{
    if(isVisited[cur]==1)return mp[cur];

    if(cur>=a)
    {
       isVisited[cur]=1;
       mp[cur]=cur-a;
        return cur-a;
    }


  long long res=a-cur;
    for(int i=0;i<2;i++)
    {
        if(res==0)break;
        long long nxt=cur*10 + d[i];
        if(nxt>=a){
            res=min(res,nxt-a);
            break;
        }
        //cout<<"prev res, test res: "<<res<<", "<<testResult<<endl;
        res = min(res,findSol(nxt));

    }

    isVisited[cur]=1;
    mp[cur]=res;
    return res;
}

int precious(int n)
{
    while(n>=10){
        n/=10;
    }
    return n;
}

void solve()
{
    cin>>a>>n;
    for(int i=0;i<n;i++)cin>>d[i];


    // isVisited.clear();
    // mp.clear();
    // cout<<findSol(0)<<endl;
    
}

int main()
{
    FasterIO;
    int tc;cin>>tc;
    while(tc--)solve();
}