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

#define ll long long

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
#define int long long
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")
// #define priority_queue <int, vector<int>, greater<int>> minHeap
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
#define minHeap priority_queue<int, vector<int>, greater<int>>
#define mod 1000000007
ll calPow1(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 0)
        {
            b = b / 2;
            a = (a * a) % mod;
        }
        else
        {
            b--;
            ans = (ans * a) % mod;
        }
    }
    return ans;
}
ll mod1 = 1e9 + 9;
ll calPow2(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 0)
        {
            b = b / 2;
            a = (a * a) % mod1;
        }
        else
        {
            b--;
            ans = (ans * a) % mod1;
        }
    }
    return ans;
}

const int N = 9e3 + 2;
ll p1[N], p2[N], inv1[N], inv2[N], ar[N], br[N];
void preCalculations()
{
    ll a = 1, b = 1;
    p1[0] = 1;
    inv1[0] = 1;
    p2[0] = 1;
    inv2[0] = 1;
    for (ll i = 1; i <= 5050; i++)
    {
        a = (a * 31) % mod;
        p1[i] = a;
        inv1[i] = calPow1(a, mod - 2);
        b = (b * 137) % mod1;
        p2[i] = b;
        inv2[i] = calPow2(b, mod1 - 2);
    }
}
void calculate_hash(string &s)
{
    ll sum = 0, sum1 = 0;
    int n = s.size();
    for (ll i = 0; i < n; i++)
    {
        ll a = p1[i] * (s[i] - 96);
        sum = (sum + a) % mod;
        ar[i] = sum;
        a = p2[i] * (s[i] - 96);
        sum1 = (sum1 + a) % mod1;
        br[i] = sum1;
    }
}
pair<ll, ll> find_hash(ll i, ll j)
{
    ll a = ar[j];
    if (i > 0)
        a = (a + mod) - ar[i - 1];
    a = (a * inv1[i]) % mod;
    ll b = br[j];
    if (i > 0)
        b = ((b + mod1) - br[i - 1]);
    b = (b * inv2[i]) % mod1;
    return {a, b};
}

void solve()
{

    string str;
    cin >> str;
    str = to_lower(str);

    calculate_hash(str);
    int n = str.size();
    int result = 0;
    int table[n + 2];
    for (int i = 1; i < n; i++)
    {
        memset(table, 0, sizeof(table));
        for (int j = i - 1; j < n; j++)
        {
            table[j] = i;
        }
        for (int j = 2 * i - 1; j < n; j++)
        {
            if (find_hash(j - (2 * i) + 1, j - i) == find_hash(j - i + 1, j))
            {
                result = max3(result, table[j - i] + i, table[j]);
                table[j] = max(table[j], table[j - i] + i);
            }
        }
    }
    cout << result << endl;
}
int32_t main()
{
    preCalculations();
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
