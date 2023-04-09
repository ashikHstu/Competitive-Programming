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
#define endl "\n"
#define ll long long

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

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

    int findSlot(int slot)
    {
        slot = findParent(slot);
        parent[slot] = (slot + 1) % (parent.size() - 1);
        return slot;
    }
};

int main()
{
    FasterIO;
    int n;
    cin >> n;
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < n; i++)
    {
        int slot;
        cin >> slot;
        int r = dsu.findSlot(slot - 1) + 1;
        cout << r << " ";
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
