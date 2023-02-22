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
#define pdd pair<double, double>
struct point
{
    double x, y;
    point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    bool operator<(const point &p) const
    {
        return x <= p.x;
    }
};

double area(const vector<point> &fig)
{
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++)
    {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1 * (A.first) + b1 * (A.second);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2 * (C.first) + b2 * (C.second);

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        cout << "Ever zero?";
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        return make_pair(x, y);
    }
}

struct line
{
    double a, b, c;
};

line findLine(pair<double, double> p1, pair<double, double> p2)
{
}

void solve()
{
    int n;
    double k;
    cin >> n >> k;
    vector<point> allPoints;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        allPoints.pb(point(a, b));
    }
    sort(all(allPoints));
    for (int i = 1; i < n; i++)
    {
        pdd a = {allPoints[i - 1].x, 0};
        pdd b = {allPoints[i - 1].x, allPoints[i - 1].y};
        pdd c = {allPoints[i].x, 0};
        pdd d = {allPoints[i].x, allPoints[i].y};
        pdd ppt = lineLineIntersection(a, c, b, d);
        allPoints.pb({ppt.first, ppt.second});
    }
    allPoints.pb({0, 0});
    allPoints.pb({k, 0});
    sort(all(allPoints));

    double res = area(allPoints);
    cout << res << endl;
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
