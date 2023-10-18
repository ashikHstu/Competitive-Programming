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
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> ar1(n + 2, (vector<ll>(m + 2, 0)));
    vector<vector<ll>> ar2(n + 2, (vector<ll>(m + 2, 0)));
    vector<vector<ll>> ar3(n + 2, (vector<ll>(m + 2, 0)));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ar1[i][j];
            ar2[i][j] = ar1[i][j];
            ar2[i][j] += ar2[i - 1][j];
            ar3[i][j] = ar1[i][j];
            ar3[i][j] += ar3[i][j - 1];
        }
    }
    ll result = 0;
    for (int j = 1; j <= m; j++)
    {
        ll sum = ar1[1][j];
        int a = 0, b = 0;
        for (int i = 2; i <= n; i++)
        {
            ll c = min({i - 1, j - 1, n - i, m - j});
            if (c > a && b == 0)
            {
                a++;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else if (a > 0)
            {
                b = 1;
                a--;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else
            {
                break;
            }
        }
        result = max(result, sum);
        sum = ar1[n][j];
        a = 0, b = 0;
        for (int i = n - 1; i >= 1; i--)
        {

            if (min(i - 1, min(j - 1, min(n - i, m - j))) > a && b == 0)
            {
                a++;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else if (a > 0)
            {
                b = 1;
                a--;
                sum += ar3[i][j + a] - ar3[i][j - a - 1];
            }
            else
            {
                break;
            }
        }
        result = max(result, sum);
    }
    for (int i = 1; i <= n; i++)
    {
        ll summation = ar1[i][1];
        int a = 0, b = 0;
        for (int j = 2; j <= m; j++)
        {
            if (min(i - 1, min3(j - 1, n - i, m - j)) > a && b == 0)
            {
                a++;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else if (a > 0)
            {
                a--;
                b = 1;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else
            {
                break;
            }
        }
        result = max(result, summation);
        summation = ar1[i][m];
        a = 0, b = 0;
        for (int j = m - 1; j >= 1; j--)
        {
            ll c = min({i - 1, j - 1, n - i, m - j});
            if (c > a && b == 0)
            {
                a++;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else if (a > 0)
            {
                a--;
                b = 1;
                summation += ar2[i + a][j] - ar2[i - a - 1][j];
            }
            else
            {
                break;
            }
        }
        result = max(result, summation);
    }
    cout << result << endl;
}

int32_t main()
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
