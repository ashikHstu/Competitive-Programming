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

void solve()
{
    int n, m;
    cin >> n >> m;
    priority_queue<pair<ll, ll>> pq;
    ll ar[n + 2], prefix[n + 2];
    ll res = 0;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        if (i != 1 && ar[i] > 0 && i == m)
        {
            res++;
            ar[i] = -ar[i];
        }
        prefix[i] = prefix[i - 1] + ar[i];
    }

    for (int i = 1; i <= m; i++)
    {
        pq.push({ar[i], i});
    }
    ll change = 0;
    // cout << "agei res : " << res << endl;
    for (int i = 1; i < m; i++)
    {
        if (ar[i] < prefix[m])
        {
            while (ar[i] < prefix[m])
            {
                pair<ll, ll> tp = pq.top();
                pq.pop();
                // cout << "proposing index : " << tp.second << endl;
                if (tp.second <= i)
                    continue;

                res++;
                // cout << "negating index : " << tp.second << endl;
                ll nv = -(tp.first);
                prefix[m] += nv;
                prefix[m] += nv;
                //  cout << "new val : " << prefix[m] << endl;
                ar[tp.second] = nv;
            }
        }
        ar[i + 1] += ar[i];
    }

    priority_queue<ll> pq2;
    ll sum = ar[m];

    // cout << "preRes : " << res << endl;
    // cout << "preSum : " << sum << endl;

    for (int i = m + 1; i <= n; i++)
    {
        sum += ar[i];
        if (ar[i] < 0)
        {

            ll pv = (-1) * ar[i];
            pq2.push(pv);
        }
        while (sum < prefix[m] && !pq2.empty())
        {
            //  cout << "ever?\n";
            ll t = pq2.top();
            sum += t;
            sum += t;
            res++;
            pq2.pop();
        }
    }

    cout << res << endl;
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
