/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

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
/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j)) // turn off j'th bit
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1)) // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1)) // turn off the last on bit
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

#define blz(a) __builtin_clz(a)              // Number of leading zero
#define btz(a) __builtin_ctz(a)              // number of trailing zero
#define totalSetBit(a) __builtin_popcount(a) // number of set bit
#define parity(a) __builtin_parity(a)        // if odd number of set bit > 1, if even > 0
int bitTaken[33];
#define sz 500005
int n;
int ar[sz];
int dp[sz];
vector<int> allState[sz];
int findRes(int cur, vector<int> dichi)
{
    bool ok = true;
    for (int i = 0; i < 30; i++)
    {
        if (bitTaken[i] != dichi[i])
            ok = false;
    }
    if (ok)
        return 0;
    if (dp[cur] != -1)
    {
        // bool yesOk = true;
        // for (int i = 0; i <= 30; i++)
        // {
        //     if (allState[cur][i] != dichi[i])
        //     {
        //         yesOk = false;
        //         break;
        //     }
        // }
        // if (yesOk)
        return dp[cur];
    }

    if (cur == n)
        return 99999999;
    int r1 = findRes(cur + 1, dichi);
    vector<int> lagbe(dichi);
    for (int i = 0; i <= 30; i++)
    {
        if (isOn(ar[cur], i))
            dichi[i] = 1;
    }
    int r2 = 1 + findRes(cur + 1, dichi);
    if (r1 < r2)
    {
        for (int i = 0; i <= 30; i++)
            allState[cur].pb(lagbe[i]);
    }
    else
    {
        for (int i = 0; i <= 30; i++)
            allState[cur].pb(dichi[i]);
    }
    return dp[cur] = min(r1, r2);
}

void solve()
{

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    vector<int> bitPosition[34];
    mem(bitTaken, 0);
    mem(dp, -1);
    for (int i = 30; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (isOn(ar[j], i))
                bitPosition[i].push_back(j);
        }
        if (bitPosition[i].size() == 1)
        {
            cout << "-1\n";
            return;
        }
        if (bitPosition[i].size() == 0)
            continue;
        else
        {
            bitTaken[i] = 1;
        }
    }
    vector<int> dichi(33, 0);
    int res = findRes(0, dichi);
    cout << n - res << endl;
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
