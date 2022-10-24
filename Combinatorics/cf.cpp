#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sz 200005

int Left[sz],Right[sz];
vector<int>g[sz];
int parent[sz];
int res;

int dfs(int cur,int par)
{
   // cout<<"cur node : "<<cur<<", parent : "<<par<<endl;
    int sum=0;
    for(int v:g[cur])
    {
        if(v!=par)
        {
            sum+=dfs(v,cur);


        }
    }

   // cout<<"sum : "<<sum<<", for cur : "<<cur<<endl;

    if(sum>=Left[cur] )
    {
        return min(sum,Right[cur]);
    }
    else {
        res++;
        return Right[cur];
    }

}


void solve()
{
      int n;cin>>n;
      for(int i=2;i<=n;i++)
      {
        int v;cin>>v;
        g[v].push_back(i);
      }

      for(int i=1;i<=n;i++)
      {
          cin>>Left[i]>>Right[i];
      }


      res=0;
      int t=dfs(1,-1);

      //cout<<"res : ";
      cout<<res<<endl;
      for(int i=0;i<=n;i++)
      {
          g[i].clear();
      }



}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }


    return 0;
}
