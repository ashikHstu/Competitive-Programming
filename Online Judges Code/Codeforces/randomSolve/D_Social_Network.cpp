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
int extra;

class UnionFind
{
private:
    int numSets;
    vector<int> p, r;
    vector<int> setSize;

public:
    UnionFind(int n)
    {
        numSets = n;
        r.assign(n, 0);
        p.assign(n, -1);
        setSize.assign(n, 1);
    }
    void init(int n)
    {
        numSets = n;
        r.resize(n, 0);
        p.assign(n, -1);
        setSize.resize(n, 1);
    }
    int findSet(int i) { return p[i] == -1 ? i : p[i] = findSet(p[i]); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i);
            int y = findSet(j);
            if (r[x] > r[y])
            {
                setSize[x] += setSize[y];
                p[y] = x;
            }
            else
            {
                setSize[y] += setSize[x];
                p[x] = y;
                if (r[x] == r[y])
                    r[y]++;
            }
            numSets--;
        }
        else
        {
            extra++;
        }
    }
    int numDisJointSets() { return numSets; }
    int setSizeOf(int x) { return setSize[findSet(x)]; }
};

void solve(int kase)
{
    extra = 0;
    int n, d;
    cin >> n >> d;
    UnionFind uf(n);
    int soFar = 0;
    for (int i = 0; i < d; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.unionSet(u, v);

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[uf.findSet(i)]++;
        }
        vector<int> vec;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            vec.pb(it->second);
        }
        sort(all(vec));
        reverse(all(vec));
        int res = 0;
        for (int i = 0; i <= extra; i++)
        {
            res += vec[i];
        }
        cout << res - 1 << endl;
    }
}

int main()
{
    int tc = 1;
    //  cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
