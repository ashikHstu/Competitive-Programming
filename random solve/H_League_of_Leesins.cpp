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
vector<pair<int, pair<int, int>>> vec;
vector<int> ache[200005 + 2];
int findSecond(int a, int b, int c)
{
    if (ache[a].size() == 2)
        return a;
    if (ache[b].size() == 2)
        return b;
    if (ache[c].size() == 2)
        return c;
}

int findThird(int a, int b, int c)
{
    // cout << "at third : " << a << ", " << b << ", " << c << endl;
    if (ache[a].size() == 3)
    {
        // cout << "sending : " << a << endl;
        return a;
    }
    if (ache[b].size() == 3)
    {
        // cout << "sending : " << b << endl;
        return b;
    }
    if (ache[c].size() == 3)
    {
        // cout << "sending : " << c << endl;
        return c;
    }
    else
        return -1;
}

int findCommon(int m, int l, int lid)
{
    set<int> st;
    for (int i = 0; i < ache[m].size(); i++)
        st.insert(ache[m][i]);

    int res;
    vector<int> ext;
    for (int i = 0; i < ache[m].size(); i++)
    {
        for (int j = 0; j < ache[l].size(); j++)
        {
            if (ache[m][i] == ache[l][j])
                ext.pb(ache[m][i]);
        }
    }
    for (int ex : ext)
    {
        if (ex != lid)
            return ex;
    }

    // for (auto it = st.begin(); it != st.end(); it++)
    // {
    //     cout << "common ind: " << *it << endl;
    //     if (*it != lid)
    //     {
    //         res = *it;
    //         // cout << "all ind : " << res << endl;
    //     }
    // }

    // return res;
}

int findLst(int m, int l, int ind)
{
    int lft = vec[ind].first;
    int md = vec[ind].second.first;
    int lst = vec[ind].second.second;

    if (lft != m && lft != l)
        return lft;
    if (md != m && md != l)
        return md;
    if (lst != m && lst != l)
        return lst;
}

void solve()
{

    int n;
    cin >> n;

    for (int i = 0; i < n - 2; i++)
    {
        int l, m, r;
        cin >> l >> m >> r;
        vec.pb({l, {m, r}});
        ache[l].pb(i);
        ache[m].pb(i);
        ache[r].pb(i);
    }

    int st;
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (ache[i].size() == 1)
        {
            res.pb(i);
            st = i;
            break;
        }
    }

    int id = ache[st][0];
    int l = vec[id].first;
    int md = vec[id].second.first;
    int ls = vec[id].second.second;
    int sec = findSecond(l, md, ls);

    res.pb(sec);
    int thrd = findThird(l, md, ls);
    // cout << "id , l, md, ls : " << id << ", " << l << ", " << md << ", " << ls << endl;
    // cout << "sec, thrd : " << sec << ", " << thrd << endl;
    res.pb(thrd);
    while (res.size() != n)
    {
        int commonInd = findCommon(sec, thrd, id);
        // cout << "commonInd: " << commonInd << endl;

        int tmp = thrd;
        thrd = findLst(sec, thrd, commonInd);

        // cout << "added ls : " << ls << endl;
        sec = tmp;
        id = commonInd;
        res.pb(thrd);
    }

    for (int v : res)
        cout << v << " ";
    cout << endl;
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
