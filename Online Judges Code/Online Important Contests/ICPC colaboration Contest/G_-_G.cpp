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

// int ext_gcd(int a, int b, int &x, int &y)
// {
//     x = 1, y = 0;
//     int x1 = 0, y1 = 1, a1 = a, b1 = b;
//     while (b1)
//     {
//         int q = a1 / b1;
//         tie(x, x1) = make_tuple(x1, x - q * x1);
//         tie(y, y1) = make_tuple(y1, y - q * y1);
//         tie(a1, b1) = make_tuple(b1, a1 - q * b1);
//     }
//     return a1;
// }

// class ChineseRemainderTheorem
// {
//     typedef long long vlong;
//     typedef pair<vlong, vlong> pll;

//     /** CRT Equations stored as pairs of vector. See addEqation()*/
//     vector<pll> equations;

// public:
//     void clear()
//     {
//         equations.clear();
//     }

//     /** Add equation of the form x = r (mod m)*/
//     void addEquation(vlong r, vlong m)
//     {
//         equations.push_back({r, m});
//     }
//     pll solve()
//     {
//         if (equations.size() == 0)
//             return {-1, -1}; /// No equations to solve

//         vlong a1 = equations[0].first;
//         vlong m1 = equations[0].second;
//         a1 %= m1;
//         /** Initially x = a_0 (mod m_0)*/

//         /** Merge the solution with remaining equations */
//         for (int i = 1; i < equations.size(); i++)
//         {
//             vlong a2 = equations[i].first;
//             vlong m2 = equations[i].second;

//             vlong g = __gcd(m1, m2);
//             if (a1 % g != a2 % g)
//                 return {-1, -1}; /// Conflict in equations

//             /** Merge the two equations*/
//             vlong p, q;
//             ext_gcd(m1 / g, m2 / g, &p, &q);

//             vlong mod = m1 / g * m2;
//             vlong x = ((__int128)a1 * (m2 / g) % mod * q % mod + (__int128)a2 * (m1 / g) % mod * p % mod) % mod;

//             /** Merged equation*/
//             a1 = x;
//             if (a1 < 0)
//                 a1 += mod;
//             m1 = mod;
//         }
//         return {a1, m1};
//     }
// };

tuple<int, int> exgcd(int a, int b)
{
    if (b == 0)
        return make_tuple(1, 0);
    int x, y;
    tie(x, y) = exgcd(b, a % b);
    return make_tuple(y, x - y * (a / b));
}

int crt(int a[], int m[], int n)
{
    int M = 1, x = 0;
    for (int i = 0; i < n; i++)
    {
        int a_ = a[i] % m[i], m_ = m[i];
        int y, t;
        tie(y, t) = exgcd(M, m_);
        int g = a_ - x;
        if (g % y != 0)
            return -1;
        int z = m_ / y;
        x = x + t * g / y % z * M;
        M *= z;
    }
    return (x + M) % M;
}

void solve2()
{
    cout << "solve2 started\n";
    int n;
    cin >> n;
    int a[n + 3], m[n + 3];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> m[i];
    }
    cout << "pre solve\n";
    cout << "The solution to the system of modular equations is " << crt(a, m, n) << endl;
}

void solve()
{
}

int main()
{
    solve2();

    return 0;
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
