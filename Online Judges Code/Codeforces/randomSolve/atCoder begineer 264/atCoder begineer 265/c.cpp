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

const int mod = 1e9 + 7;
const int maxn = 100005;

void solve()
{
    int n, m;
    cin >> n >> m;
    string st[n + 3];
    for (int i = 0; i < n; i++)
    {
        cin >> st[i];
    }

    int vis[n + 3][m + 3];
    mem(vis, 0);

    int cr = 1, cc = 1;
    while (true)
    {
        if (vis[cr][cc] != 0)
        {
            cout << "-1\n";
            return;
        }
        vis[cr][cc] = 1;

        char curCh = st[cr - 1][cc - 1];
       // cout << "curCh : " << curCh << endl;
        if (curCh == 'L')
        {
            if (cc == 1)
            {
                cout << cr << " " << cc << endl;
                return;
            }
            cc--;
        }
        else if (curCh == 'R')
        {
           // cout << "??fdf\n";
            if (cc == m)
            {
               // cout << "???\n";
                cout << cr << " " << cc << endl;
                return;
            }
            cc++;
        }
        else if (curCh == 'U')
        {
            if (cr == 1)
            {
                cout << cr << " " << cc << endl;
                return;
            }
            cr = cr - 1;
        }
        else if (curCh == 'D')
        {
            if (cr == n)
            {
                cout << cr << " " << cc << endl;
                return;
            }
            cr += 1;
        }

        //cout << "cr,cc : " << cr << " , " << cc << endl;
    }
}

int main()
{
    map<pair<pair<ll,ll>>,ll>sr;
    int tc = 1;
    // cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/