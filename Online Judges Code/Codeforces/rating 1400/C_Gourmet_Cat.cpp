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

int extra(int a, int b, int c)
{
    int ct[4];
    ct[1] = a;
    ct[2] = b;
    ct[3] = c;
    map<int, int> mp;
    mp[2] = 1;
    mp[3] = 1;
    mp[6] = 1;
    mp[1] = 2;
    mp[4] = 2;
    mp[5] = 3;
    mp[7] = 3;
    int mainRes = 0;
    for (int i = 1; i <= 7; i++)
    {
        map<int, int> mpc = mp;
        int op = 1;
        int cnt = 0;
        int mx = 0;
        for (int j = i; op <= 7; j++, op++)
        {
            if (j == 8)
                j = 1;
            if (ct[mpc[j]] > 0)
            {
                cnt++;
                ct[mpc[j]]--;
            }
            else
            {
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
        if (cnt > 0)
            mx = max(mx, cnt);
        mainRes = max(mainRes, mx);
        cout << "main res from " << i << " : " << mainRes << endl;
    }

    return mainRes;
}

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    int r1 = (a / 3);
    int r2 = (b / 2);
    int r3 = (c / 2);
    int r = min3(r1, r2, r3);
    a = a - (r * 3);
    b = b - (r * 2);
    c = c - (r * 2);

    int ex = extra(a, b, c);
    cout << "extra : " << ex << endl;
    cout << (r * 7) + ex << endl;
    return;

    cout << "Updated a,b,c : " << a << ", " << b << ", " << c << endl;
    int week[8] = {0};
    if (a > 0)
    {
        a--;
        week[2]++;
    }
    if (a > 0)
    {
        a--;
        week[3]++;
    }
    if (a > 0)
    {
        a--;
        week[6]++;
    }

    if (b > 0)
    {
        b--;
        week[1]++;
    }
    if (b > 0)
    {
        b--;
        week[4]++;
    }
    if (c > 0)
    {
        c--;
        week[5]++;
    }
    if (c > 0)
    {
        c--;
        week[7]++;
    }

    cout << "weak is : " << endl;
    for (int i = 1; i <= 7; i++)
        cout << week[i] << " ";
    cout << endl;

    int ct = 0;
    vector<int> okk;
    int mx = 0;
    for (int i = 1; i <= 7; i++)
    {
        if (week[i] == 1)
        {
            ct++;
        }
        else
        {

            okk.pb(ct);
            mx = max(mx, ct);
            ct = 0;
        }
    }

    if (ct > 0)
        okk.pb(ct);
    mx = max(mx, ct);
    if (week[1] == 1 && week[7] == 1)
    {
        ct = okk[0] + okk[okk.size() - 1];
        mx = max(mx, ct);
    }
    mx = mx + (r * 7);
    cout << mx << endl;
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
