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

#define int long long int

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

#define P complex<int>
#define X real()
#define Y imag()

int cross(P a, P b, P c)
{
    P u = b - a;
    P v = c - a;
    return (conj(u) * v).Y;
}

bool comp(const P &a, const P &b)
{
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}

bool mid(P a, P b, P c)
{
    vector<P> v = {a, b, c};
    sort(v.begin(), v.end(), comp);
    return (v[1] == c);
}

int sgn(int x)
{
    return (x > 0) - (x < 0);
}

bool check(P a, P b, P c, P d)
{
    int cp1 = cross(a, b, c);
    int cp2 = cross(a, b, d);
    int cp3 = cross(c, d, a);
    int cp4 = cross(c, d, b);
    if (cp1 == 0 && mid(a, b, c))
        return 1;
    if (cp2 == 0 && mid(a, b, d))
        return 1;
    if (cp3 == 0 && mid(c, d, a))
        return 1;
    if (cp4 == 0 && mid(c, d, b))
        return 1;
    if (sgn(cp1) != sgn(cp2) && sgn(cp3) != sgn(cp4))
        return 1;
    return 0;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        P a, b, c, d;
        cin >> x >> y;
        a = {x, y};
        cin >> x >> y;
        b = {x, y};
        cin >> x >> y;
        c = {x, y};
        cin >> x >> y;
        d = {x, y};
        cout << (check(a, b, c, d) ? "YES" : "NO") << endl;
    }
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
