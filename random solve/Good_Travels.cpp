/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link :
   verdict :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define doshomik(x) cout << fixed << setprecision(x)
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

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")

#define sz 1000006
vector<int> ar[sz];
vector<int> tr[sz];

vector<int> order;
vector<int> SCC;

int vis[sz];
int fun[sz];

void dfs(int node)
{
    vis[node] = 1;

    for (int child : ar[node])
        if (vis[child] == 0)
            dfs(child);

    order.pb(node);
}

void dfs1(int node)
{
    vis[node] = 1;

    for (int child : tr[node])
        if (vis[child] == 0)
            dfs1(child);

    SCC.pb(node);
}
int main()
{
    int n, a, b, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            ar[i].clear(),
                tr[i].clear(), vis[i] = 0;
        order.clear();

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            ar[a].pb(b);
            tr[b].pb(a);
        }

        for (int i = 1; i <= n; i++)
            if (vis[i] == 0)
                dfs(i);

        for (int i = 1; i <= n; i++)
            vis[i] = 0;

        for (int i = 1; i <= n; i++)
            if (vis[order[n - i]] == 0)
            {
                SCC.clear();
                dfs1(order[n - i]);

                cout << "dfs1() called from " << order[n - i] << " and printing SCC" << endl;
                for (int node : SCC)
                    cout << node << " ";
                cout << endl;
            }
    }
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/