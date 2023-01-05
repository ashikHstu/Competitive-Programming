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

bool testing(vector<int> vec)
{
    sort(all(vec));
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] + 1 != vec[i])
            return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    int ar[n + 2];
    int ct[n + 3] = {0};
    bool no = false;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        ct[ar[i]]++;
        if (ct[ar[i]] > 2)
        {
            no = true;
        }
        vec[i] = {ar[i], i};
    }

    if (ct[1] > 1)
    {
        cout << "NO\n";
        return;
    }

    if (no)
    {
        cout << "NO\n";
        return;
    }
    sort(all(vec));
    if (vec[n - 1].first != n)
    {
        cout << "NO\n";
        return;
    }
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     if (vec[i].first == vec[i + 1].first || vec[i].first + 1 == vec[i + 1].first)
    //         continue;
    //     else
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    reverse(all(vec));

    vector<int> tp1, tp2, writen2, writen1;
    map<int, int> mp1, mp2;
    vector<int> p1(n), p2(n);
    int lv1 = n, lv2 = n;
    for (int i = 0; i < n; i++)
    {
        if (mp1[vec[i].first] == 0)
        {
            p1[vec[i].second] = vec[i].first;
            mp1[vec[i].first]++;
            tp1.pb(vec[i].second);
            writen1.pb(vec[i].first);
        }
        else
        {
            p2[vec[i].second] = vec[i].first;
            tp2.pb(vec[i].second);
            writen2.pb(vec[i].first);
        }
    }

    int j = 0;
    for (int i = 0; i < tp2.size(); i++)
    {
        while (j < writen1.size() && lv1 == writen1[j] && j < writen1.size())
        {
            j++;
            lv1--;
        }
        p1[tp2[i]] = lv1;
        lv1--;
    }

    j = 0;
    for (int i = 0; i < tp1.size(); i++)
    {
        while (j < writen2.size() && lv2 == writen2[j] && j < writen2.size())
        {
            j++;
            lv2--;
        }
        p2[tp1[i]] = lv2;
        lv2--;
    }

    if (testing(p1))
    {
        cout << "NO\n";
        return;
    }
    if (testing(p2))
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int mv = max(p1[i], p2[i]);
        if (mv != ar[i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << p1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p2[i] << " ";
    }
    cout << endl;

    return;
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
