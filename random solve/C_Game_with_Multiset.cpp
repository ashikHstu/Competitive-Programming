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

#define int long long
#define ll long long

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
#define isOn(S, j) (S & (1 << j))
int addp(int n, int pos)
{
    cout << "n , p : " << n << ", " << pos << endl;
    if (pos == 31)
        return n;
    if (isOn(n, pos))
    {
        addp(n, pos + 1);
    }
    n = (n | (1 << pos));
    return n;
}

int twoP[33];
void tpCal()
{
    twoP[0] = 1;
    for (int i = 1; i < 30; i++)
    {
        twoP[i] = twoP[i - 1] * 2;
    }
}

void faltuTry1()
{
    tpCal();
    int n;
    cin >> n;
    int ms = 0;

    vector<int> vec[33];
    for (int ii = 0; ii < n; ii++)
    {
        int type;
        cin >> type;
        int v;
        cin >> v;
        if (type == 1)
        {

            if (vec[v].size() == 0)
            {
                vec[v].pb(twoP[v]);
            }
            else
            {
                vec[v].pb((vec[v].back() + (twoP[v])));
            }
            //   ms = addp(ms, v);
        }
        else if (v == 0)
        {
            cout << "YES\n";
        }
        else
        {
            // cout << "inpted v: " << v << endl;
            for (int i = 29; i >= 0; i--)
            {
                if (v <= 0)
                    break;
                // cout << "cur v : " << v << endl;
                if (vec[i].size() == 0)
                    continue;
                // cout << "2 p " << i << ": ";
                // for (int j = 0; j < vec[i].size(); j++)
                // {
                //     cout << vec[i][j] << " ";
                // }
                // cout << endl;
                int lb = lower_bound(vec[i].begin(), vec[i].end(), v) - vec[i].begin();
                // cout << "lb : " << lb << endl;
                if (lb == vec[i].size())
                {
                    lb--;
                }
                if (vec[i][lb] > v)
                    lb--;
                if (lb >= 0 && vec[i][lb] <= v)
                    v -= vec[i][lb];
            }
            //  cout << "last v: " << v << endl;
            if (v == 0)
                cout << "YES\n";
            else
                cout << "NO\n";

            // cout << "value of MS : " << ms << endl;
            // int xv = (v & ms);
            // if (xv == v)
            // {
            //     cout << "YES\n";
            // }
            // else
            //     cout << "NO\n";
        }
    }

    return;
}

int32_t main()
{
    faltuTry1();
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
