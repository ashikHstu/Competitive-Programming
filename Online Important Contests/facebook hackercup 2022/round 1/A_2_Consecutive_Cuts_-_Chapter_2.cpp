/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define MinHeap priority_queue<int, vector<int>, greater<int>>
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
#define NUMLEN(Num) to_string(Num).size()

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")

/// vector
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const int mod = 1e9 + 7;
const int maxn = 100005;

using ii = pair<int, int>;

#define ff first
#define se second

const int mx = 1e5 + 5;

struct state
{
    int len, link, fpos;
    map<int, int> next;
} st[mx << 1];

vector<int> vec[mx << 1];
int sz, last, cnt[mx << 1];

inline void sa_extend(int c)
{
    int cur = sz++, p = last;
    cnt[cur] = 1;
    st[cur] = {st[p].len + 1, -1, st[p].len + 1};
    for (; ~p && !st[p].next.count(c); p = st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else
    {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else
        {
            int cln = sz++;
            cnt[cln] = 0;
            st[cln] = st[q];
            st[cln].len = st[p].len + 1;
            for (; ~p && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = cln;
            st[q].link = st[cur].link = cln;
        }
    }
    last = cur;
}

int Minimum_Cyclic_Shift(vector<int> s)
{
    int len = s.size(), u = 0;
    st[0] = {0, -1};
    sz = 1;
    last = 0;
    for (int i = 0; i < len; i++)
        sa_extend(s[i]);
    for (int i = 0; i < len; i++)
        sa_extend(s[i]);
    for (int i = 0; i < len; i++)
        u = st[u].next.begin()->second;
    return st[u].fpos - len + 1;
}

void solve(int kase)
{
    int n, k;
    cin >> n >> k;
    vector<int> ar(n), br, cr;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    bool started = false;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v == ar[0])
            started = true;
        if (started)
        {
            br.pb(v);
        }
        else
            cr.pb(v);
    }

    for (int i = 0; i < (int)cr.size(); i++)
    {
        br.pb(cr[i]);
    }

    cout << "Case #" << kase << ": ";

    for (int i = 0; i < n; i++)
    {
        if (ar[i] != br[i])
        {
            cout << "NO\n";
            return;
        }
    }

    if (cr.size() > 0 && k == 0)
    {
        cout << "NO\n";
        return;
    }
    if (cr.size() == 0 && k == 1)
    {
        cout << "NO\n";
        return;
    }

    if (n == 2)
    {
        int crSize = cr.size();
        if (crSize == 0 && k % 2 == 1)
        {
            cout << "NO\n";
            return;
        }
        if (crSize == 1 && k % 2 == 0)
        {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";
        return;
    }

    cout << "YES\n";
}

int main()
{
    // READ("input.txt");
    // WRITE("output.txt");
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
