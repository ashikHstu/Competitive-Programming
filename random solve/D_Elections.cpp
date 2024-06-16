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
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int &v : ar)
        cin >> v;

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int mxNext[n + 2], mxPrev[n + 2], prevSum[n + 2];
    mxPrev[0] = 0;
    mxPrev[1] = ar[0] + k;
    int mx = ar[0] + k;
    prevSum[0] = 0;
    prevSum[1] = k + ar[0];
    for (int i = 2; i < n; i++)
    {
        mx = max(mx, ar[i - 1]);
        prevSum[i] = prevSum[i - 1] + ar[i - 1];
        mxPrev[i] = mx;
    }
    mxNext[n - 1] = 0;
    mxNext[n - 2] = ar[n - 1];
    mx = ar[n - 1];
    for (int i = n - 3; i >= 0; i--)
    {
        mx = max(mx, ar[i + 1]);
        mxNext[i] = mx;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (mxNext[i] <= ar[i] + k)
            {
                cout << "0 ";
            }
            else
            {
                cout << "1 ";
            }
            continue;
        }

        if (mxPrev[i] < ar[i] && mxNext[i] <= ar[i])
        {
            cout << "0 ";
            continue;
        }

        if (prevSum[i] + ar[i] >= mxNext[i])
        {
            cout << i << " ";
            continue;
        }
        else
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int32_t main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }
    return 0;
}
