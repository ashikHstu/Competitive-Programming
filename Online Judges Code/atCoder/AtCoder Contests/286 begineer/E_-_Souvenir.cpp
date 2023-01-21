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

/** STL Functions     */
// pbds
#define fbo(ind) find_by_order(ind)
#define ook(val) order_of_key(val)

/**      Extra storing              */
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())

/**        End of Ex Storing                */

/**------- Char Chk----------*/
inline bool isLower(char ch) { return (ch >= 'a' && ch <= 'z'); }
inline bool isUpper(char ch) { return (ch >= 'A' && ch <= 'Z'); }
inline bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }
inline bool isVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

#define sz 302
vector<int> g[sz];
int vis[sz][sz], dis[sz][sz];
ll specialRes[sz][sz];
ll special[sz];
int N;

void bfs(int src)
{
    //  cout << "src is : " << src << ", " << d << endl;
    queue<int> q;
    q.push(src);
    dis[src][src] = 0;
    vis[src][src] = 1;
    //  ll taken[N + 2] = {0};
    // taken[src] = special[src];
    specialRes[src][src] = special[src];
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (!vis[src][v])
            {
                // if (v == d)
                {
                    // cout << "distance from : " << u << endl;
                    // cout << "src is : " << src << endl;
                    // cout << "prev dis : " << dis[u] << endl;
                    // cout << "src dis : " << dis[src] << endl;
                    // cout << "distance : " << dis[u] + 1 << endl;
                }
                vis[src][v] = 1;
                dis[src][v] = dis[src][u] + 1;
                specialRes[src][v] = specialRes[src][u] + special[v];
                // taken[v] = taken[u] + special[v];
                q.push(v);
            }
            else if (dis[src][u] + 1 == dis[src][v])
            {
                specialRes[src][v] = max(specialRes[src][v], specialRes[src][u] + special[v]);
                // taken[v] = max(taken[v], taken[u] + special[v]);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    N = n;
    for (int i = 0; i < n; i++)
        cin >> special[i];

    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < n; j++)
        {
            if (st[j] == 'Y')
                g[i].pb(j);
        }
    }

    for (int i = 0; i < n; i++)
        bfs(i);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, d;

        cin >> s >> d;
        s--;
        d--;
        if (vis[s][d] == 0)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dis[s][d] << " " << specialRes[s][d] << endl;
        }
    }
}

int main()
{
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
