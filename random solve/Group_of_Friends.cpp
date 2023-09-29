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

/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
#define minHeap priority_queue<int, vector<int>, greater<int>>

struct DSU
{
    int totalConnectedComponent;
    vector<int> parent, setSize, setMin, setMax;

    void init(int n)
    {
        parent = setSize = setMin = setMax = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = setMin[i] = setMax[i] = i, setSize[i] = 1;
        }
        totalConnectedComponent = n;
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    /*
    int findParent(int u)
      {
          while (u != parent[u])
          {
              parent[u] = parent[parent[u]];
              u = parent[u];
          }
          return u;
      }
    */

    int getSetSize(int u)
    {
        return setSize[findParent(u)];
    }
    int getSetMin(int u)
    {
        return setMin[findParent(u)];
    }
    int getSetMax(int u)
    {
        return setMax[findParent(u)];
    }

    void Union(int u, int v)
    {
        int parent1 = findParent(u), parent2 = findParent(v);

        if (parent1 == parent2)
            return;

        totalConnectedComponent--;

        if (setSize[parent1] > setSize[parent2])
            swap(parent1, parent2);

        setSize[parent2] += setSize[parent1];
        setMin[parent2] = min(setMin[parent1], setMin[parent2]);
        setMax[parent2] = max(setMax[parent1], setMax[parent2]);
        setSize[parent1] = 0;
        parent[parent1] = parent[parent2];
    }

    bool isSameSet(int i, int j) { return findParent(i) == findParent(j); }
};
vector<int> divisors[100009];
void make()
{
    for (int i = 2; i <= 100005; i++)
    {
        for (int j = i; j <= 100005; j += i)
        {
            divisors[j].pb(i);
        }
    }
}

vector<int> kiJani[100006];
void solve()
{
    int n;
    cin >> n;
    DSU dsu;
    dsu.init(n);
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        int v = vec[i];

        // cout << "divisor size : " << divisors[v].size() << endl;

        for (int j = 0; j < (int)divisors[v].size(); j++)
        {
            int dv = divisors[v][j];
            if (kiJani[dv].size() > 0)
            {
                dsu.Union(kiJani[dv][0], i + 1);
                // cout << "the dv is : " << dv << endl;
                // cout << "add kortechi : " << kiJani[dv][0] << ", " << i + 1 << endl;
            }
            kiJani[dv].pb(i + 1);
        }
    }

    // cout << "all set size : " << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dsu.getSetSize(i) << " ";
    // }
    // cout << endl;

    int res = dsu.totalConnectedComponent;
    cout << res << endl;
}

int main()
{
    make();
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
