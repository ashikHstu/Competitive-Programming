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

#define MOD 1000000007
ll hashs[5005], pows[5005];
int getHash(int l, int r)
{
    return ((hashs[r + 1] - (hashs[l] * pows[r - l + 1]) % MOD) + MOD) % MOD;
}

void solve()
{
    string st;
    cin >> st;
    int n = st.size();

    int maxR = n / 2;
    for (int i = maxR; i >= 0; i--)
    {
        int cur = 0;
        for (int j = i; j < n; j++)
        {
            if (st[j - i] == st[j] || st[j - i] == '?' || st[j] == '?')
                cur++;
            else
                cur = 0;
            if (cur == i)
            {
                cout << cur * 2 << endl;
                return;
            }
        }
    }
    cout << "0" << endl;
    return;
    int p = 331;
    for (int i = 0; i < n; i++)
    {
        hashs[i + 1] = (hashs[i] * p + st[i]) % MOD;
    }
    int res = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j += 2)
        {
            int cl = j - i + 1;
            int md = cl / 2;
            int id2 = i + md - 1;
            int id3 = i + md;
            for (int k = 0; k < md; k++)
            {
                if (st[i + k] == st[i + k + md] || st[i + k] == '?' || st[i + k + md] == '?')
                {
                }
            }
            if (getHash(i, id2) == getHash(id3, j))
            {
                cout << "cursubstr: " << st.substr(i, cl) << endl;
                res = max(res, cl);
            }
        }
    }

    cout << res << endl;
    return;

    for (int i = 0; i < n; i++)
    {
        int curL = n - i;
        if (curL < res)
        {
            cout << res << endl;
            return;
        }
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int total = i - mid + 1;
            if (total + i >= n)
            {
                cout << "problem ta ki!!!!!!!!!!!!!!!!\n";
            }
            cout << "cur substr: " << st.substr(i, total) << endl;
            if ((total) % 2 != 0)
                mid++;
            int hlf = total / 2;
            bool ok = true;
            for (int k = 0; k < hlf; k++)
            {
                if (st[i + k] != st[i + hlf + k] || st[i + k] == '?' || st[i + hlf + k] == '?')
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                res = max(res, total);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }

    cout << res << endl;
}

int main()
{
    int p = 331;
    pows[0] = 1;
    for (int i = 1; i < 5005; i++)
    {
        pows[i] = (pows[i - 1] * p) % MOD;
    }

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
