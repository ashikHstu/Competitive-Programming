/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
   verdict : Accepted
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long

struct DSU
{
    int totalConnectedComponent;
    vector<int> parent, setMax;

    void init(int n)
    {
        parent = setMax = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = setMax[i] = i;
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

        if (parent1 > parent2)
            swap(parent1, parent2);

        setMax[parent2] = max(setMax[parent1], setMax[parent2]);
        parent[parent1] = parent[parent2];
    }

    bool isSameSet(int i, int j) { return findParent(i) == findParent(j); }
    void Leave(int x)
    {
        Union(x, x + 1);
    }
    int FindRight(int v)
    {
        return getSetMax(v);
    }
};

int main()
{
    FasterIO;
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n + 2);
    for (int i = 0; i < m; i++)
    {
        char ch;
        int v;
        cin >> ch >> v;
        if (ch == '-')
        {
            dsu.Leave(v);
        }
        else
        {
            int r = dsu.FindRight(v);
            if (r == n + 1)
                r = -1;
            cout << r << "\n";
        }
    }

    return 0;
}
static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
