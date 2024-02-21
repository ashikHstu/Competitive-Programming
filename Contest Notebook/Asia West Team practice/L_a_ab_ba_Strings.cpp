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
struct segTree
{
    int size;
    vector<long long> sums;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2 * size, 0LL);
    }
    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                sums[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, mid);
        build(a, x * 2 + 2, mid, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    long long sum(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return 0;
        if (lx >= l && rx <= r)
            return sums[x];
        int mid = (lx + rx) / 2;
        long long s1 = sum(l, r, x * 2 + 1, lx, mid);
        long long s2 = sum(l, r, x * 2 + 2, mid, rx);
        return s1 + s2;
    }
    long long sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

string st;
int n;
bool isOk(int pos)
{
    if (pos < 0 || pos >= n)
        return false;

    if (st[pos] == 'b')
        return true;
}

void solve()
{
    cin >> n;
    cin >> st;
    vector<int> status(n);
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 'b')
            status[i] = -1;
        else
        {
            if (i - 1 >= 0 && i + 1 < n)
            {
                if (st[i - 1] == 'b' || st[i + 1] == 'b')
                    status[i] = 1;
                else
                    status[i] = 0;
            }
            else if (i - 1 >= 0)
            {
                if (st[i - 1] == 'b')
                {
                    status[i] = 1;
                }
                else
                    status[i] = 0;
            }
            else if (i + 1 < n)
            {
                if (st[i + 1] == 'b')
                    status[i] = 1;
                else
                    status[i] = 0;
            }
        }
    }
    segTree ST;
    ST.init(n);
    ST.build(status);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int id;
            cin >> id;
            id--;
            if (st[id] == 'a')
            {
                status[id] = -1;
                st[id] = 'b';
                ST.set(id, -1);
            }
            else
            {
                st[id] = 'a';
                int prev = id - 1;
                if (status[prev] == 1)
                {
                    if (isOk(prev - 1) || isOk(prev + 1))
                    {
                        status[prev] = 1;
                    }
                    else
                    {
                        status[prev] = 0;
                        ST.set(prev, 0);
                    }
                }
                prev = id + 1;
                if (status[prev] == 1)
                {
                    if (isOk(prev - 1) || isOk(prev + 1))
                    {
                        status[prev] = 1;
                    }
                    else
                    {
                        status[prev] = 0;
                        ST.set(prev, 0);
                    }
                }

                if (isOk(id - 1) || isOk(id + 1))
                {
                    status[id] = 1;
                    ST.set(id, 1);
                }
            }
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (a == b)
            {
                if (st[a - 1] == 'a')
                    cout << "YES\n";
                else
                    cout << "NO\n";

                continue;
            }
            a--;
            int mn = 0;
            if (status[a] == 1)
            {
                if (st[a + 1] != 'b')
                    mn++;
            }
            if (status[b - 1] == 1)
            {
                if (st[b - 2] != 'b')
                    mn++;
            }

            int s = ST.sum(a, b);
            if (s - mn >= 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main()
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
