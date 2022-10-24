#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(), x.end())
#define Reverse(x) reverse(x.begin(), x.end())
#define SortA(ar, s) sort(ar, ar + s)
#define SortD(ar, s) sort(ar, ar + s, greater<int>())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define sq(x) (x) * (x)
#define CEIL(a, b) ((a / b) + ((a % b) != 0))

vector<int> g[200005];
bool visited[200005];

int dfs(int cur)
{
    visited[cur]=true;
    for(int child:g[cur])
    {
        if(!visited[child])
        {
            return dfs(child)+1;
        }
    }

    return 1;
}

void solve()
{
    int n;cin>>n;
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        visited[i]=false;
    }
    bool ok=true;
for(int i=0;i<n;i++)
{
    int u,v;
    cin>>u>>v;
    g[u].pb(v),g[v].pb(u);
    if(v==u || g[u].size()>2 || g[v].size()>2)ok=false;

}


  if(!ok)
  {
    cout<<"NO\n";
    return;
  }

  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
        if(dfs(i)%2)
        {
            cout<<"NO\n";
            return;
        }
    }
  }

   cout<<"YES\n";



}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}
