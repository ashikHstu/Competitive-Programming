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
struct segTree
{
    int size;
    vector<long long> operations;
    vector<long long> values;
    long long NEUTRAL_ELEMENT = 0;

    long long modify_op(long long a, long long b, long long len)
    {
        return (a + (b * len));
    }

    long long calc_op(long long a, long long b)
    {
        return (a + b);
    }

    void apply_mod_op(long long &a, long long b, long long len)
    {
        a = modify_op(a, b, len);
    }

    void build(int x, int lx, int rx)
    {
        if (rx == lx + 1)
        {
            values[x] = 1;
            return;
        }
        int mid = (lx + rx) / 2;
        build(2 * x + 1, lx, mid);
        build(2 * x + 2, mid, rx);
        values[x] = calc_op(values[x * 2 + 1], values[2 * x + 2]);
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        operations.assign(2 * size, 0LL);
        values.assign(2 * size, 0);
        // build(0, 0, size);
    }

    void Modify(int l, int r, int v, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return;
        if (lx >= l && rx <= r)
        {
            apply_mod_op(operations[x], v, 1);
            apply_mod_op(values[x], v, rx - lx);

            return;
        }
        int mid = (lx + rx) / 2;
        Modify(l, r, v, x * 2 + 1, lx, mid);
        Modify(l, r, v, x * 2 + 2, mid, rx);
        values[x] = calc_op(values[x * 2 + 1], values[x * 2 + 2]);

        apply_mod_op(values[x], operations[x], rx - lx);
    }
    void Modify(int l, int r, int v)
    {
        Modify(l, r, v, 0, 0, size);
    }

    long long calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
        {
            return values[x];
        }
        int mid = (lx + rx) / 2;
        auto m1 = calc(l, r, x * 2 + 1, lx, mid);
        auto m2 = calc(l, r, x * 2 + 2, mid, rx);
        auto res = calc_op(m1, m2);
        apply_mod_op(res, operations[x], min(rx, r) - max(lx, l));
        return res;
    }

    long long calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }

    long long Get(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return operations[x];
        }
        int mid = (lx + rx) / 2;
        long long res;
        if (i < mid)
        {
            res = Get(i, 2 * x + 1, lx, mid);
        }
        else
        {
            res = Get(i, 2 * x + 2, mid, rx);
        }
        return res + operations[x];
    }

    long long Get(int i)
    {
        return Get(i, 0, 0, size);
    }
};

void solve()
{
    int n;
    cin >> n;
    segTree st;
    st.init(10000007);
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        vec.pb({l, r});
    }
    reverse(all(vec));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int r = st.calc(vec[i].first, vec[i].second + 1);
        if (r < (vec[i].second - vec[i].first + 1))
            res++;
        st.Modify(vec[i].first, vec[i].second, 1);
    }
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
