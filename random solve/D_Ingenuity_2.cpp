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
int a, b;
bool isPossible(string st)
{
    if (st.size() == 2)
    {
        if (st[0] == st[1])
            return true;
        return false;
    }
    if (st.size() < 4)
        return false;
    a = 0;
    b = 0;
    for (char ch : st)
    {
        if (ch == 'N')
            a++;
        if (ch == 'S')
            a--;
        if (ch == 'E')
            b++;
        if (ch == 'W')
            b--;
    }

    if ((abs(a) % 2 == 0) && (abs(b) % 2 == 0))
        return true;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    string st;
    cin >> st;
    if (!isPossible(st))
    {
        cout << "NO\n";
        return;
    }
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 'E')
            c1++;
        else if (st[i] == 'W')
            c2++;
        else if (st[i] == 'N')
            c3++;
        else if (st[i] == 'S')
            c4++;
    }
    int eh = c1 / 2, wh = c2 / 2, nh = c3 / 2, sh = c4 / 2;
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 'E')
        {
            if (eh > 0)
                st[i] = 'R', eh--;
            else
                st[i] = 'H';
        }
        else if (st[i] == 'W')
        {
            if (wh > 0)
                st[i] = 'R', wh--;
            else
                st[i] = 'H';
        }
        else if (st[i] == 'N')
        {
            if (nh > 0)
                st[i] = 'H', nh--;
            else
                st[i] = 'R';
        }
        else if (st[i] == 'S')
        {
            if (sh > 0)
                st[i] = 'H', sh--;
            else
                st[i] = 'R';
        }
    }
    cout << st << endl;
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
