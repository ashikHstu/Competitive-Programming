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

bool wayDeuVai(vector<int> ex, vector<int> sF)
{
    if (ex.size() > sF.size())
        return false;
    return true;

    vector<int> extra, soFar;
    sort(all(extra));
    reverse(all(ex));
    reverse(all(sF));
    for (int i = 0; i < ex.size(); i++)
    {
        int aroAche = ex[i] - sF[i];
        if (aroAche > 0)
            extra.pb(aroAche);
    }
    if (extra.size() == 0)
        return true;
    for (int i = ex.size(); i < sF.size(); i++)
        soFar.pb(sF[i]);

    return wayDeuVai(extra, soFar);
}

bool wayDeuVai2(vector<int> ex, vector<int> sF)
{
    bool hoiche = true;
    for (int i = 0; i < ex.size(); i++)
    {
        if (ex[i] > 0)
            hoiche = false;
    }
    if (hoiche)
        return true;
    for (int i = 0; i < sF.size(); i++)
    {
        for (int j = 0; j < ex.size(); j++)
        {
            vector<int> sF2;
            for (int k = 0; k < sF.size(); k++)
                if (k != i)
                    sF2.pb(sF[k]);

            ex[j] -= sF[i];
            if (wayDeuVai2(ex, sF2))
            {
                return true;
            }
            ex[j] += sF[i];
        }
    }

    return false;
}

void solve(int kase)
{
    int n;
    cin >> n;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v <= n)
            ar.pb(v);
    }

    sort(all(ar));
    vector<int> ar2;
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] <= i + 1)
            ar2.pb(ar[i]);
        else
            break;
    }
    ar = ar2;

    int k = 0;
    vector<int> soFar;
    for (int i = 0; i < (int)ar.size(); i++)
    {
        vector<int> extra;
        bool kicchu_korar_nai = false;
        for (int j = i; j < (int)ar.size(); j++)
        {
            if (ar[i] <= (i + 1))
            {
                extra.pb((i + 2 - ar[i]));
            }
            if (extra.size() > soFar.size())
            {
                kicchu_korar_nai = true;
                break;
            }
        }

        if (!kicchu_korar_nai)
        {
            bool hobeKi = wayDeuVai2(extra, soFar);
            kicchu_korar_nai = (kicchu_korar_nai | (!hobeKi));
        }

        if (kicchu_korar_nai)
        {
            k++;
        }
        else
        {
            cout << k << endl;
            return;
        }

        soFar.pb(i + 1);
    }

    cout << k << endl;
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
