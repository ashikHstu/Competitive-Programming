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
/**
#define debug(x); cerr << #x <<" "; _print(x); cerr << endl;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 */
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n, b, i, last, j;
    cin >> n >> b;
    int sum = (n * (n - 1)) / 2;
    for (i = 1;; i++)
    {
        last = n + i - 1;
        if (isPrime(sum + last))
        {
            break;
        }
    }
    deque<int> v;
    for (i = 1; i < n; i++)
    {
        v.pb(i);
    }
    v.pb(last);
    while (1)
    {
        int ok = 1;
        for (i = n - 2; i >= 0; i--)
        {
            if (i == n - 2)
            {
                if (v[i + 1] - v[i] > 2)
                {
                    v[i + 1]--;
                    v[i]++;
                }
                else
                {
                    ok = 0;
                    break;
                }
            }
            else if (v[i] + 1 < v[i + 1] && v[n - 1] - v[n - 2] > 1)
            {
                v[i]++;
                v[n - 1]--;
            }
            else
            {
                ok = 0;
                break;
            }
            // cout << v[i] << " " << v[n-1] << endl;
        }
        if (v[n - 1] - v[n - 2] <= 1 || ok == 0)
        {
            ok = 0;
            break;
        }
    }
    if (b < v[n - 1])
    {
        cout << "impossible" << endl;
        return;
    }

    for (i = 1; i <= n; i++)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        last = v.front();
        v.pop_front();
        v.pb(last);
    }
    cout << endl;
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