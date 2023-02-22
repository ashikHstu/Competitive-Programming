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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
/* PRINTS */
template <class T>
void print_v(vector<T> &v)
{
    cout << "{";
    for (auto x : v)
        cout << x << ",";
    cout << "\b}";
}

/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
#define sz 60
vector<pair<int, int>> g[sz + 1];
void clearAll(int n)
{
    for (int i = 0; i <= n; i++)
        g[i].clear();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    clearAll(n + 3);
    vector<pair<int, pair<int, int>>> allPaths;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        allPaths.pb({i, {u, v}});
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    int okNode = -1;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() < n - 1)
        {
            okNode = i;
            break;
        }
    }
    if (okNode != -1)
    {
        // cout << "selected node is : " << okNode << endl;
        cout << "2\n";
        for (int i = 0; i < m; i++)
        {
            if (allPaths[i].second.first == okNode || allPaths[i].second.second == okNode)
                cout << "1 ";
            else
                cout << "2 ";
        }
        cout << endl;
        return;
    }

    int res[m + 3] = {0};
    int totalColor = n - 1;
    int curC = 1;
    for (int i = 1; i <= 2; i++)
    {
        int tt = 0;
        for (pair<int, int> p : g[i])
        {
            if (res[p.second] == 0)
            {
                res[p.second] = curC;
                tt++;
                if (tt == totalColor - 1)
                {
                    curC++;
                    break;
                }
            }
        }
    }
    totalColor = max(3, totalColor);
    cout << 3 << endl;
    for (int i = 0; i < m; i++)
    {
        if (res[i] != 0)
            cout << res[i] << " ";
        else
            cout << "3 ";
    }
    cout << endl;
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

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
