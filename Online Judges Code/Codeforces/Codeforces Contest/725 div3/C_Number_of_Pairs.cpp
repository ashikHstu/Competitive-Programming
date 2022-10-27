/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of Allah, the Most Gracious, the Most Merciful.)              */

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
/// Library
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
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
//#define nl                 printf("\n")
#define endl '\n'

/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/// vector
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)

/// File In
#define READ(f) freopen(f ".in", "r", stdin)
#define WRITE(f) freopen(f ".out", "w", stdout)

#define mod 1000000007
#define ll long long int
#define SIZ 1000005

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    int ar[n + 2];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    ordered_set os;
    os.insert(ar[n - 1]);
    ll res = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int nl = l - ar[i];
        int ns = r - ar[i];

        int rr1 = os.order_of_key(nl);
        // cout<<"testing rr1 on test : "<<rr1<<endl;
        rr1 = (n - i - 1) - rr1;

        //        cout<<"n-i+1 : "<<n-i-1<<endl;
        //          cout<<"set size : "<<os.size()<<endl;
        //        cout<<"rr1 : "<<rr1<<endl;

        int rr2 = os.order_of_key(ns + 1);
        rr2 = n - i - 1 - rr2;

        // cout<<"rr2 : "<<rr2<<endl;

        res += (rr1 - rr2);

        // cout<<"res test : "<<res<<endl;

        os.insert(ar[i]);
    }

    // cout<<"res : ";
    cout << res << endl;
}

int main()
{
    // FasterIO;

    int tc = 1;
    scanf("%d", &tc);
    for1(i, tc) solve();
    return 0;
}
