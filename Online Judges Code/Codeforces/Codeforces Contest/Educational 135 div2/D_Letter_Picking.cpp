/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int

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
const int maxn = 3005;

int dp[3][maxn][maxn];
int n;
string st;

int fun(int keVai, int shamne, int sheshe, char ki)
{
    if (sheshe < shamne)
    {
        return 2;
    }
    if (dp[keVai][shamne][sheshe] != -1)
        return dp[keVai][shamne][sheshe];

    int range = sheshe - shamne + 1;
    // cout << "range : " << range << endl;
    int geche = n - range;
    int hoiche = 2;
    if (geche % 2 == 0)
    {
        int dekhi1 = fun((keVai ^ 1), shamne + 1, sheshe, st[shamne]);
        int dekhi2 = fun((keVai ^ 1), shamne, sheshe - 1, st[sheshe]);

        if (dekhi1 == keVai || dekhi2 == keVai)
        {
            hoiche = keVai;
        }
        else if (dekhi1 == 2 || dekhi2 == 2)
        {
            hoiche = 2;
        }
        else
        {
            hoiche = (keVai ^ 1);
        }
    }
    else
    {
        if (st[shamne] < ki || st[sheshe] < ki)
        {
            hoiche = keVai;
        }
        else if (st[shamne] > ki && st[sheshe] > ki)
        {
            hoiche = (keVai ^ 1);
        }
        else if (st[shamne] == ki && st[sheshe] == ki)
        {
            int dekhi1 = fun((keVai ^ 1), shamne + 1, sheshe, st[shamne]);
            int dekhi2 = fun((keVai ^ 1), shamne, sheshe - 1, st[sheshe]);
            if (dekhi1 == keVai || dekhi2 == keVai)
            {
                hoiche = keVai;
            }
            else if (dekhi1 == 2 || dekhi2 == 2)
            {
                hoiche = 2;
            }
            else
            {
                hoiche = (keVai ^ 1);
            }
        }
        else if (st[shamne] == ki)
        {
            int dekhi1 = fun((keVai ^ 1), shamne + 1, sheshe, st[shamne]);
            hoiche = dekhi1;
        }
        else if (st[sheshe] == ki)
        {
            int dekhi2 = fun((keVai ^ 1), shamne, sheshe - 1, st[sheshe]);
            hoiche = dekhi2;
        }
        }

    return dp[keVai][shamne][sheshe] = hoiche;
}
void solve(int kase)
{

    cin >> st;
    n = st.size();
    for (int i = 0; i <= n + 10; i++)
    {
        for (int j = 0; j <= n + 10; j++)
        {
            dp[0][i][j] = -1;
            dp[1][i][j] = -1;
        }
    }

    int res = fun(0, 0, n - 1, 'A');

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[0][i][j] << "," << dp[1][i][j] << "| ";
    //     }
    //     cout << endl;
    // }

    // cout << "res : " << res << endl;
    if (res == 0)
        cout << "Alice" << endl;
    else if (res == 1)
        cout << "Bob\n";
    else if (res == 2)
        cout << "Draw" << endl;
}

int32_t main()
{
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
