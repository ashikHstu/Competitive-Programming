#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define mod 1000000007
#define inf 1e18
#define ppb pop_back
#define ff first
#define ss second

///  order_of_key return number of elements less than x -> os.order_of_key(x)
///  cout << "oth element  : " << *os.find_by_order(0) << endl; so it returns value of index

int lcm(int x, int y)
{
    return (x * 1LL * y) / __gcd(x, y);
}

// Graph on 2D Grid
/*----------------------Graph Moves----------------*/
// const int dx[]={+1,-1,+0,+0};
// const int dy[]={+0,+0,+1,-1};
// const int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

#define debug(x)       \
    ;                  \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;

void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

int vis[2000000], par[2000000];
vector<int> v[200000];

int Find(int a)
{
    if (par[a] < 0)
    {
        return a;
    }
    return par[a] = Find(par[a]);
}

void Union(int x, int y)
{
    par[y] = x;
}

void solve()
{
    int n, i, x, j, y;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        vis[x] = 1;
    }
    set<int> st, ans;
    for (i = 2; i <= 1e5; i++)
    {
        for (j = i; j <= 1e5; j += i)
        {
            v[j].pb(i);
        }
    }
    memset(par, -1, sizeof(par));
    for (i = 1; i <= 1e5; i++)
    {
        if (!vis[i])
        {
            continue;
        }
        sort(all(v[i]));
        for (auto it : v[i])
        {
            st.insert(it);
        }
        for (j = 1; j < v[i].size(); j++)
        {
            x = Find(v[i][j - 1]);
            y = Find(v[i][j]);
            if (x != y)
            {
                Union(x, y);
            }
        }
    }
    for (auto it : st)
    {
        x = Find(it);
        ans.insert(x);
    }
    cout << ans.size() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
}
/**
Test Case :

**/