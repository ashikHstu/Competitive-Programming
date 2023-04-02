/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
   verdict : Accepted
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct DSU
{
    int totalConnectedComponent;
    vector<int> parent, setSize;

    void init(int n)
    {
        parent = setSize = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i, setSize[i] = 1;
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

    void Union(int u, int v)
    {
        int parent1 = findParent(u), parent2 = findParent(v);

        if (parent1 == parent2)
            return;

        totalConnectedComponent--;

        if (setSize[parent1] > setSize[parent2])
            swap(parent1, parent2);

        setSize[parent2] += setSize[parent1];
        setSize[parent1] = 0;
        parent[parent1] = parent[parent2];
    }

    bool isSameSet(int i, int j) { return findParent(i) == findParent(j); }
};

int main()
{
    int n, op;
    cin >> n >> op;
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < op; i++)
    {
        string type;
        int a, b;
        cin >> type;
        cin >> a >> b;
        if (type == "union")
        {
            dsu.Union(a, b); // make union of set contain a, with set contain b
        }
        else
        {
            if (dsu.isSameSet(a, b)) // check if a and b are from same set
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
