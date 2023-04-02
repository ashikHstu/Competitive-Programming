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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int hudaiA, hudaiB;
        cin >> hudaiA >> hudaiB;
    }
    DSU dsu;
    dsu.init(n);
    vector<pair<string, pair<int, int>>> vec;
    vector<string> res;
    for (int i = 0; i < k; i++)
    {
        string st;
        int a, b;
        cin >> st >> a >> b;
        vec.push_back({st, {a, b}});
    }

    for (int i = k - 1; i >= 0; i--)
    {
        if (vec[i].first == "cut")
        {
            dsu.Union(vec[i].second.first, vec[i].second.second);
        }
        else
        {
            if (dsu.isSameSet(vec[i].second.first, vec[i].second.second))
            {
                res.push_back("YES");
            }
            else
            {
                res.push_back("NO");
            }
        }
    }
    reverse(res.begin(), res.end());
    for (string r : res)
        cout << r << endl;

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
