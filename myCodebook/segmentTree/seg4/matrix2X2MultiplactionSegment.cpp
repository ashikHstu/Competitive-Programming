/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B
   verdict :  tle on test 13
*/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
// struct item
//{
//     long long seg,pref,suf,sum;
// };

struct item
{
    int a, b, c, d;
};

int mod;

struct segTree
{
    int size;
    vector<item> values;
    item NEUTRAL_ELEMENT = {1, 0, 0, 1};
    item Single(item v)
    {
        int aa = v.a % mod;
        int bb = v.b % mod;
        int cc = v.c % mod;
        int dd = v.d % mod;
        return {aa, bb, cc, dd};
    }
    item Merge(item a, item b)
    {
        int aa = ((a.a * b.a) + (a.b * b.c)) % mod;
        int bb = ((a.a * b.b) + (a.b * b.d)) % mod;
        int cc = ((a.c * b.a) + (a.d * b.c)) % mod;
        int dd = ((a.c * b.b) + (a.d * b.d)) % mod;

        return {aa, bb, cc, dd};
    }
    // O(log(n))
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.resize(2 * size);
    }

    // O(nlogn) , although said, O(n), i think O(nlogn)
    void build(vector<item> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                values[x] = Single(a[lx]);
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, mid);
        build(a, x * 2 + 2, mid, rx);
        values[x] = Merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void build(vector<item> &a)
    {
        build(a, 0, 0, size);
    }

    item calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return values[x];
        int mid = (lx + rx) / 2;
        item s1 = calc(l, r, x * 2 + 1, lx, mid);
        item s2 = calc(l, r, x * 2 + 2, mid, rx);
        return Merge(s1, s2);
    }

    item calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
};

int32_t main()
{
    FasterIO;
    int r, n, m;
    cin >> r >> n >> m;

    mod = r;

    segTree ST;

    ST.init(n + 2);

    vector<item> ar(n);
    for (int i = 0; i < n; i++)
    {
        int aa, bb, cc, dd;
        cin >> aa >> bb >> cc >> dd;

        ar[i] = {aa, bb, cc, dd};
    }

    ST.build(ar);
    for (int i = 0; i < m; i++)
    {

        int ll, rr;
        cin >> ll >> rr;
        ll--;
        item res = ST.calc(ll, rr);
        cout << res.a << " " << res.b << endl;
        cout << res.c << " " << res.d << endl;

        cout << endl;
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
