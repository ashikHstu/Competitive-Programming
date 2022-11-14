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
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
// const int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1}; // Kings Move
// const int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; // Kings Move
//  const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//  const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

int h, w;
string st[1000006];
map<pair<int, int>, int> mp;
pair<int, int> sp;
bool curRank = false;
ll curm = 0;
bool isValid(int i, int j)
{
    if (i < 0 || j < 0 || i >= h || j >= w)
        return false;
    if (mp[{i, j}] != 0)
        return false;
    if (st[i][j] == '#')
        return false;
    return true;
}

void dfs(int road, pair<int, int> p)
{
    //  cout << "road : " << road << endl;
    mp[p]++;
    for (int i = 0; i < 4; i++)
    {
        int nx = p.first + fx[i];
        int ny = p.second + fy[i];

        if (isValid(nx, ny))
        {
            mp[{nx, ny}]++;

            dfs(road + 1, {nx, ny});
        }
        else if (nx >= 0 && nx < h && ny >= 0 && ny < w)
        {
            if (road >= 3 && st[nx][ny] == 'S')
                curRank = true;
        }
    }
}

void solve()
{
    cin >> h >> w;
    pair<int, int> s;
    for (int i = 0; i < h; i++)
    {
        cin >> st[i];
        for (int j = 0; j < w; j++)
        {
            if (st[i][j] == 'S')
                s = {i, j};
        }
    }
    sp = s;
    dfs(0, s);
    if (curRank)
        cout << "Yes\n";
    else
        cout << "No\n";
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
