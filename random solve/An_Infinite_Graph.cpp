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

#define limit 1000006

int prime_chek[limit + 1], primes[50000000], total_primes;

void sieve_and_store_primes()

{
    int sqn = sqrt(limit) + 1;
    prime_chek[0] = prime_chek[1] = 1;
    primes[total_primes] = 2;
    total_primes++;
    for (int i = 3; i <= sqn; i += 2)
    {
        if (prime_chek[i] == 0)
        {
            primes[total_primes] = i;

            total_primes++;

            for (int j = i * i; j <= limit; j += i + i)
            {

                prime_chek[j] = 1;
            }
        }
    }

    if (sqn % 2 == 0)
    {
        sqn++;
    }
    for (int i = sqn; i < limit; i += 2)
    {
        if (prime_chek[i] == 0)
        {

            primes[total_primes] = i;

            total_primes++;
        }
    }
}

bool checkPrime(int n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    if (prime_chek[n] == 0)
        return true;
    return false;
}

vector<int> ar[1000006];
const int maxN = 27;
int level[1000006], LCA[1000006][maxN + 1];

void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par;

    for (int child : ar[node])
        if (child != par)
        {
            dfs(child, lvl + 1, node);
        }
}

void init(int n)
{
    dfs(2, 0, -1);

    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= n; j++)
            if (LCA[j][i - 1] != -1)
            {
                int par = LCA[j][i - 1];
                LCA[j][i] = LCA[par][i - 1];
            }
    }
}

int getLCA(int a, int b)
{
    if (level[b] < level[a])
        swap(a, b);

    int d = level[b] - level[a];

    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];

        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = maxN; i >= 0; i--)
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i], b = LCA[b][i];
        }

    return LCA[a][0];
}

int getDist(int a, int b)
{
    int lca = getLCA(a, b);
    return level[a] + level[b] - 2 * level[lca];
}
// int gulPrime[6000006];
//  void markGulPrime()
//  {
//      int ct = 0;
//      int sq = 1000;
//      for (int i = 1; i < total_primes / 10; i++)
//      {
//          for (int j = i + 1; j < total_primes; j++)
//          {
//              ct++;
//              if (primes[i] + primes[j] > 1000000)
//                  break;
//              gulPrime[primes[i] + primes[j]] = primes[i];
//          }
//      }
//      cout << "ct : " << ct << endl;
//  }

pair<int, int> isGul(int n)
{

    if (checkPrime(n))
        return {n, -1};
    // int sq = sqrt(n + 1);
    for (int i = 0; primes[i] <= n / 2; i++)
    {
        if (checkPrime(n - primes[i]))
        {
            return {primes[i], n - primes[i]};
        }
    }
    if (checkPrime(n / 2))
    {
        return {n / 2, n / 2};
    }

    return {-1, -1};
}

void makeGraph()
{
    int tct = 0;

    for (int i = 0; i * 2 + 1 < total_primes; i++)
    {
        int cur = i + 1;
        int l = cur * 2;
        int r = cur * 2 + 1;
        // if (i < 3)
        //     cout << "making child : " << primes[cur - 1] << " " << primes[l - 1] << endl;
        ar[primes[cur - 1]].pb(primes[l - 1]);
        ar[primes[cur - 1]].pb(primes[r - 1]);

        ar[primes[l - 1]].pb(primes[cur - 1]);
        ar[primes[r - 1]].pb(primes[cur - 1]);
        tct += 2;
    }
    for (int i = 1; i < 1000005; i++)
    {
        for (int j = 0; j <= maxN; j++)
            LCA[i][j] = -1;
    }
    init(1000005);
}

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << 1 << endl;
        cout << 2 << endl;
        cout << "0" << endl;
        return;
    }
    pair<int, int> res = isGul(n);
    if (res.second == -1)
    {
        cout << 1 << endl;
        cout << res.first << endl;
        cout << 0 << endl;
        return;
    }
    cout << 2 << endl;
    cout << res.first << " " << res.second << endl;
    cout << getDist(res.first, res.second) << endl;
}

int main()
{
    sieve_and_store_primes();
    makeGraph();

    // cout << "total primes : " << total_primes << endl;
    // markGulPrime();
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
