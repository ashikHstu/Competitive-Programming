/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://open.kattis.com/problems/dogs
   verdict : Accepted
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

#define rep(i, a, b) for (__typeof(b) i = a; i < (b); ++i)

template <class T>
struct Point
{
    typedef T coordType;
    typedef Point P;
    typedef const P &R;
    T x, y;
    explicit Point(T x = T(), T y = T()) : x(x), y(y) {}
    bool operator==(R p) const { return x == p.x && y == p.y; }
    P operator+(R p) const { return P(x + p.x, y + p.y); }
    P operator-(R p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(R p) const { return x * p.x + y * p.y; }
    T dist2() const { return x * x + y * y; }             // distance^2
    double dist() const { return sqrt((double)dist2()); } // length
    P unit() const
    {
        if (dist() < 1e-9)
            return *this;
        return *this / (T)dist();
    } // makes dist()=1
};
template <class T>
ostream &operator<<(ostream &os, const Point<T> &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
template <class T>
istream &operator>>(istream &is, Point<T> &p)
{
    is >> p.x >> p.y;
    return is;
}
template <class P>
double segDist(const P &s, const P &e, const P &p)
{
    if (s == e)
        return (p - s).dist();
    typedef typename P::coordType T;
    T d = (e - s).dist2(), t = min(d, max(T(0), (p - s).dot(e - s)));
    return ((p - s) * d - (e - s) * t).dist() / d;
}

void solve()
{

    int n;
    cin >> n;
    vector<Point<double>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.push_back(a.back());
    int m;
    cin >> m;
    vector<Point<double>> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    b.push_back(b.back());

    Point<double> cura = a[0], curb = b[0];
    double ma = (cura - curb).dist();
    int nexta = 1, nextb = 1;
    while (nexta < n && nextb < m)
    { // Stop when one of them reaches home
        Point<double> mova = a[nexta] - cura;
        Point<double> movb = b[nextb] - curb;

        double lena = mova.dist();
        double lenb = movb.dist();
        double len = min(lena, lenb);
        Point<double> diff = cura - curb;
        cura = cura + mova.unit() * len;
        curb = curb + movb.unit() * len;

        double distance = segDist(diff, cura - curb, Point<double>(0, 0));
        ma = min(ma, distance);

        if (lena <= lenb)
        {
            // assign for better precision. the value of cura is almost the same as a[nexta] already
            cura = a[nexta];
            nexta++;
        }
        else
        {
            curb = b[nextb];
            nextb++;
        }
    }

    printf("%.11lf\n", ma);
}

int main()
{
    int tc = 1;
    //  cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
