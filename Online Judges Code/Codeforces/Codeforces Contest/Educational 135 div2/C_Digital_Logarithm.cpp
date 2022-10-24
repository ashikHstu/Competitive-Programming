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

void solve(int kase)
{
    int n;
    cin >> n;
    int ar[n + 3], br[n + 2];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        mp[ar[i]]++;
    }
    vector<int> exa, exb;
    for (int i = 0; i < n; i++)
    {
        cin >> br[i];
        if (mp[br[i]] >= 1)
        {
            mp[br[i]]--;
        }
        else
        {
            exb.pb(br[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[ar[i]] >= 1)
        {
            exa.pb(ar[i]);
            mp[ar[i]]--;
        }
    }
    int res = 0;
    for (int i = 0; i < (int)exa.size(); i++)
    {
        if (exa[i] >= 10)
        {
            int nod = NUMLEN(exa[i]);
            res++;
            exa[i] = nod;
        }
        mp[exa[i]]++;
    }

    //  cout << "exa size : " << exa.size() << endl;
    // cout << "exb size : " << exb.size() << endl;

    vector<int> exaa, exbb;

    for (int i = 0; i < (int)exb.size(); i++)
    {
        if (exb[i] >= 10)
        {
            int nod = NUMLEN(exb[i]);
            res++;
            exb[i] = nod;
        }
        if (mp[exb[i]] > 0)
        {
            mp[exb[i]]--;
        }
        else
        {
            exbb.pb(exb[i]);
        }
    }

    for (int i = 0; i < (int)exa.size(); i++)
    {
        if (mp[exa[i]] >= 1)
        {
            exaa.pb(exa[i]);
            mp[exa[i]]--;
        }
    }
    for (int v : exaa)
    {
        if (v != 1)
            res++;
    }
    for (int v : exbb)
    {
        if (v != 1)
            res++;
    }
    // res = res + (exaa.size()) + (exbb.size());
    cout << res << endl;
    return;

    // cout << "exaa size : " << exaa.size() << endl;
    // cout << "exbb size : " << exbb.size() << endl;

    for (int i = 0; i < (int)exaa.size(); i++)
    {
        if (exaa[i] > 1)
            res++;
    }
    for (int i = 0; i < (int)exbb.size(); i++)
    {
        if (exbb[i] > 1)
            res++;
    }

    cout << res << endl;
}

int main()
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
