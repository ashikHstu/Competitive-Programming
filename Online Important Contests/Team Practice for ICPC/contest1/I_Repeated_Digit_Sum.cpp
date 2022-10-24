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

ll sod(string st)
{
    ll sum = 0;
    if (st.size() == 1)
        return st[0] - '0';
    for (int i = 0; i < st.size(); i++)
    {
        sum += (st[i] - '0');
    }

    if (sum < 10)
        return sum;
    return sod(to_string(sum));
}

ll newSod(ll n)
{
    return sod(to_string(n));
}

int findMod(string b, int n)
{
    int cur = 0;
    for (int i = 0; i < b.size(); i++)
    {
        cur *= 10;
        cur += (b[i] - '0');
        cur %= n;
    }
    return cur % n;
}

void printRes(int kase, ll res)
{
    printf("Case %d: %lld\n", kase, res);
}

void solve(int kase)
{
    string a, b;
    cin >> a >> b;

    if (a.size() == 1 && a[0] == '0')
    {
        printRes(kase, 0);
        return;
    }

    if (a.size() == 1 && a[0] == '1')
    {
        printRes(kase, 1);
        return;
    }

    if (b.size() == 1 && b[0] == '0')
    {
        printRes(kase, 1);
        return;
    }

    ll ca = sod(a);

    if (b.size() == 1 && b[0] == '1')
    {
        printRes(kase, ca);
        return;
    }

    if (ca==3)
    {
        if (b.size() == 1 && b[0] == '1')
            printRes(kase, 3);
        else
            printRes(kase, 9);

        return;
    }

    if (ca==6)
    {
        if (b.size() == 1 && b[0] == '1')
            printRes(kase, 6);
        else
            printRes(kase, 9);

        return;
    }
//cout<<"is there? "<<endl;
    set<ll> st;
    vector<int> vec;
    ll na = ca;
    while (true)
    {
        if (st.find(ca) != st.end())
        {
            break;
        }
        // cout<<"inserted value : "<<ca<<endl;
        vec.pb(ca);
        st.insert(ca);
        ca = newSod(ca * na);
    }

    int len = vec.size();
    ll mv = findMod(b, len);
    // cout<<"mv : "<<mv<<endl;
    if (mv == 0)
        mv = len - 1;
    else
        mv = mv - 1;
    printRes(kase, vec[mv]);
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
