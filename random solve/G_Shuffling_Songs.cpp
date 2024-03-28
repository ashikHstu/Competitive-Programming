#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
// #define priority_queue <int, vector<int>, greater<int>> minHeap
/** STL Functions     */

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
#define minHeap priority_queue<int, vector<int>, greater<int>>

#define sz 1001
vector<int> g[sz];
int visited[sz];
int in[sz], out[sz];
int timer;
void dfs(int src)
{
    visited[src] = 1;
    timer++;
    in[src] = timer;
    for (int v : g[src])
    {
        if (visited[v] == 0)
            dfs(v);
    }
    timer++;
    out[src] = timer;
    visited[src] = 2;
}

#define isOn(S, j) (S & (1 << j))
vector<pair<int, int>> vec;
int n;

bool hoiKina(vector<int> tempo)
{
    int res = 1;
    for (int i = 1; i < tempo.size(); i++)
    {
        int prev = tempo[i - 1];
        int id = tempo[i];
        if (vec[prev].first == vec[id].first || vec[prev].second == vec[id].second)
            res++;
        else
            return false;
    }
    return true;
}

void solve()
{

    cin >> n;
    map<string, int> mp;
    vec.clear();
    int id = 1;

    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        if (mp[a] == 0)
        {
            mp[a] = id;
            id++;
        }
        if (mp[b] == 0)
        {
            mp[b] = id;
            id++;
        }

        vec.push_back({mp[a], mp[b]});
    }
    int res = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> tempo;
        for (int j = 0; j < n; j++)
        {
            if (isOn(i, j))
            {
                tempo.push_back(j);
            }
        }

        bool ok = hoiKina(tempo);
        if (ok)
        {
            res = max(res, (int)tempo.size());
        }
    }

    cout << n - res << endl;
}

int32_t main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }
    return 0;
}
